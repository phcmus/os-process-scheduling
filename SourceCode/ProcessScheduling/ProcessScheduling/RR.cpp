#include "RR.h"

void RR::rr_findWaitingTime(vector<ScheduledProcess>& processes, int n, int quantum, string& chart)
{
    // Make a copy of burst times bt[] to store remaining
    // burst times.
    vector<int> rem_bt(n);
    for (int i = 0; i < n; i++)
        rem_bt[i] = processes[i].cpuBurst;

    int t = 0; // Current time

    while (1)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    processes[i].waitingTime = t - processes[i].cpuBurst - processes[i].arrivalTime;
                    rem_bt[i] = 0;
                }

                Process::updateChart(chart, processes[i], t);
            }
        }

        // If all processes are done
        if (done == true)
        {
            break;
        }
    }
}

void RR::rr_scheduling(vector<ScheduledProcess> processes, int n, int quantum)
{
    cout << "Round Robin Scheduling: " << endl;
    string chart = "0";
    rr_findWaitingTime(processes, n, quantum, chart);
    ScheduledProcess::findTurnAroundTime(processes, n);
    ScheduledProcess::write_to_file(processes, n, chart, "RR.txt");
    cout << endl;
}

RR::RR()
{
}

RR::~RR()
{
}