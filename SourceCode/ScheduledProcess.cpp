#pragma once
#include "Process.cpp"
#include "Base.cpp"
class ScheduledProcess : public Process
{
public:
    int waitingTime;
    int turnaroundTime;

    ScheduledProcess(){};
    ScheduledProcess(Process _process)
    {
        this->arrivalTime = _process.arrivalTime;
        this->cpuBurst = _process.cpuBurst;
        this->name = _process.name;
        this->priority = _process.priority;
        this->waitingTime = 0;
        this->turnaroundTime = 0;
    };
    ~ScheduledProcess(){};
};

int sumCPUBurst(vector<ScheduledProcess> processes, int begin, int end)
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

int sumWaitingTime(vector<ScheduledProcess> processes, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += processes[i].waitingTime;
    }

    return sum;
}

int sumTurnaroundTime(vector<ScheduledProcess> processes, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += processes[i].turnaroundTime;
    }

    return sum;
}

void findTurnAroundTime(vector<ScheduledProcess> &processes, int n)
{
    for (int i = 0; i < n; i++)
        processes[i].turnaroundTime = processes[i].cpuBurst + processes[i].waitingTime;
}

void write_to_file(vector<ScheduledProcess> processes, int n, string filename)
{
    ofstream ofile(filename);
    ofile << chart << endl;
    for (int i = 0; i < n; i++)
    {
        ofile << processes[i].name << "\tTT = " << processes[i].turnaroundTime << " WT = " << processes[i].waitingTime << endl;
    }
    ofile << "Average: \tTT = " << float(sumTurnaroundTime(processes, n)) / float(n) << "\tWT = " << float(sumWaitingTime(processes, n)) / float(n);
    ofile.close();
}