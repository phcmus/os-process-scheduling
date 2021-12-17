#pragma once
#include "Process.cpp"
#include "ScheduledProcess.cpp"

void rr_findWaitingTime(vector<ScheduledProcess> &processes, int n, int quantum)
{
    // Make a copy of burst times bt[] to store remaining
    // burst times.
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = processes[i].cpuBurst;

    int t = 0; // Current time

    // Keep traversing processes in round robin manner
    // until all of them are not done.
    while (1)
    {
        bool done = true;

        // Traverse all processes one by one repeatedly
        for (int i = 0; i < n; i++)
        {
            // If burst time of a process is greater than 0
            // then only need to process further
            if (rem_bt[i] > 0)
            {
                done = false; // There is a pending process

                if (rem_bt[i] > quantum)
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t += quantum;

                    // Decrease the burst_time of current process
                    // by quantum
                    rem_bt[i] -= quantum;
                }

                // If burst time is smaller than or equal to
                // quantum. Last cycle for this process
                else
                {
                    // Increase the value of t i.e. shows
                    // how much time a process has been processed
                    t = t + rem_bt[i];

                    // Waiting time is current time minus time
                    // used by this process
                    processes[i].waitingTime = t - processes[i].cpuBurst - processes[i].arrivalTime;

                    // As the process gets fully executed
                    // make its remaining burst time = 0
                    rem_bt[i] = 0;
                }

                updateChart(chart, processes[i], t);
            }
        }

        // If all processes are done
        if (done == true)
        {
            break;
        }
    }
}


void rr_scheduling(vector<ScheduledProcess> processes, int n, int quantum)
{
    chart = "0";
    rr_findWaitingTime(processes, n, quantum);
    findTurnAroundTime(processes, n);
    write_to_file(processes, n, "RR.txt");
}