#pragma once
#include "Process.cpp"
#include "ScheduledProcess.cpp"

void sjf_findWaitingTime(vector<ScheduledProcess> &processes, int n)
{
    int rt[n];

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
        updateChart(chart, processes[shortest], t+1);

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

            // Find finish time of current
            // process
            finish_time = t + 1;

            // Calculate waiting time
            processes[shortest].waitingTime = finish_time - processes[shortest].cpuBurst - processes[shortest].arrivalTime;

            if (processes[shortest].waitingTime < 0)
                processes[shortest].waitingTime = 0;
        }
        // Increment time        
        t++;
    }
}

void sjf_scheduling(vector<ScheduledProcess> processes, int n)
{
    chart = "0";
    sjf_findWaitingTime(processes, n);
    findTurnAroundTime(processes, n);    
    write_to_file(processes, n, "SJF.txt");
}