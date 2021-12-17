#pragma once
#include "Process.cpp"
#include "ScheduledProcess.cpp"


void fcfs_findWaitingTime(vector<ScheduledProcess>& processes, int n)
{
    processes[0].waitingTime = 0;
    updateChart(chart, processes[0], processes[0].cpuBurst);
    for (int i = 1; i < n; i++)
    {
        processes[i].waitingTime = sumCPUBurst(processes, 0, i - 1) - processes[i].arrivalTime;
        updateChart(chart, processes[i], sumCPUBurst(processes, 0, i));
    }
}

void fcfs_scheduling(vector<ScheduledProcess> processes, int n)
{
    chart = "0";
    fcfs_findWaitingTime(processes, n);
    findTurnAroundTime(processes, n);
    write_to_file(processes, n, "FCFS.txt");
}