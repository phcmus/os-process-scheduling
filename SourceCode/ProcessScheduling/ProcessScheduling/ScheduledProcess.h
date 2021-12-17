#pragma once
#include "Process.h"
class ScheduledProcess : public Process
{
public:
    int waitingTime;
    int turnaroundTime;

    ScheduledProcess();
    ScheduledProcess(Process _process);
    ~ScheduledProcess();

    static int sumCPUBurst(vector<ScheduledProcess> processes, int begin, int end);
    static int sumWaitingTime(vector<ScheduledProcess> processes, int n);
    static int sumTurnaroundTime(vector<ScheduledProcess> processes, int n);
    static void findTurnAroundTime(vector<ScheduledProcess>& processes, int n);
    static void write_to_file(vector<ScheduledProcess> processes, int n, string chart, string filename);
};