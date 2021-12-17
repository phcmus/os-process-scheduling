#include "FCFS.h"

void FCFS::fcfs_findWaitingTime(vector<ScheduledProcess>& processes, int n, string& chart)
{
    processes[0].waitingTime = 0;
    Process::updateChart(chart, processes[0], processes[0].cpuBurst);
    for (int i = 1; i < n; i++)
    {
        processes[i].waitingTime = ScheduledProcess::sumCPUBurst(processes, 0, i - 1) - processes[i].arrivalTime;
        Process::updateChart(chart, processes[i], ScheduledProcess::sumCPUBurst(processes, 0, i));
    }
}

void FCFS::fcfs_scheduling(vector<ScheduledProcess> processes, int n)
{
    cout << "First come, first served Scheduling: " << endl;
    string chart = "0";
    fcfs_findWaitingTime(processes, n, chart);
    ScheduledProcess::findTurnAroundTime(processes, n);
    ScheduledProcess::write_to_file(processes, n, chart, "FCFS.txt");
    cout << endl;
}

FCFS::FCFS()
{
}

FCFS::~FCFS()
{
}
