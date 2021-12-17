#include "SJF.h"

SJF::SJF()
{
}

SJF::~SJF()
{
}

void SJF::sjf_findWaitingTime(vector<ScheduledProcess>& processes, int n, string& chart)
{
    vector<int> rt(n);

    // Copy the burst time into rt[]
    for (int i = 0; i < n; i++)
        rt[i] = processes[i].cpuBurst;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    // Process until all processes gets
    // completed
    while (complete != n)
    {
        // Find process with minimum
        // remaining time among the
        // processes that arrives till the
        // current time`
        for (int j = 0; j < n; j++)
        {
            if ((processes[j].arrivalTime <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        // execute process => reduce remaining time by one + add chart with time + 1
        rt[shortest]--;
        Process::updateChart(chart, processes[shortest], t + 1);

        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        // If a process gets completely
        // executed
        if (rt[shortest] == 0)
        {
            // Increment complete
            complete++;
            check = false;
            finish_time = t + 1;

            processes[shortest].waitingTime = finish_time - processes[shortest].cpuBurst - processes[shortest].arrivalTime;

            if (processes[shortest].waitingTime < 0)
                processes[shortest].waitingTime = 0;
        }

        t++;
    }
}

void SJF::sjf_scheduling(vector<ScheduledProcess> processes, int n)
{
    cout << "Shortest job first Scheduling: " << endl;
    string chart = "0";
    sjf_findWaitingTime(processes, n, chart);
    ScheduledProcess::findTurnAroundTime(processes, n);
    ScheduledProcess::write_to_file(processes, n, chart, "SJF.txt");
    cout << endl;
}
