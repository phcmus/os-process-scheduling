#include "ScheduledProcess.h"

ScheduledProcess::ScheduledProcess()
{
    this->arrivalTime = 0;
    this->cpuBurst = 0;
    this->name = "";
    this->priority = 0;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
}

ScheduledProcess::ScheduledProcess(Process _process)
{
    this->arrivalTime = _process.arrivalTime;
    this->cpuBurst = _process.cpuBurst;
    this->name = _process.name;
    this->priority = _process.priority;
    this->waitingTime = 0;
    this->turnaroundTime = 0;
}

ScheduledProcess::~ScheduledProcess()
{
}

int ScheduledProcess::sumCPUBurst(vector<ScheduledProcess> processes, int begin, int end)
{
    if (end >= processes.size() || begin > end || begin < 0)
    {
        return -1;
    }
    int sum = 0;
    for (int i = begin; i <= end; i++)
    {
        sum += processes[i].cpuBurst;
    }
    return sum;
}

int ScheduledProcess::sumWaitingTime(vector<ScheduledProcess> processes, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += processes[i].waitingTime;
    }

    return sum;
}

int ScheduledProcess::sumTurnaroundTime(vector<ScheduledProcess> processes, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += processes[i].turnaroundTime;
    }

    return sum;
}

void ScheduledProcess::findTurnAroundTime(vector<ScheduledProcess>& processes, int n)
{
    for (int i = 0; i < n; i++)
        processes[i].turnaroundTime = processes[i].cpuBurst + processes[i].waitingTime;
}

void ScheduledProcess::write_to_file(vector<ScheduledProcess> processes, int n, string chart, string filename)
{
    ofstream ofile(filename);
    cout << chart << endl;
    ofile << chart << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].name << "\tTT = " << processes[i].turnaroundTime << " WT = " << processes[i].waitingTime << endl;
        ofile << processes[i].name << "\tTT = " << processes[i].turnaroundTime << " WT = " << processes[i].waitingTime << endl;
    }
    cout << "Average: \tTT = " << float(sumTurnaroundTime(processes, n)) / float(n) << "\tWT = " << float(sumWaitingTime(processes, n)) / float(n);
    ofile << "Average: \tTT = " << float(sumTurnaroundTime(processes, n)) / float(n) << "\tWT = " << float(sumWaitingTime(processes, n)) / float(n);
    ofile.close();
}

