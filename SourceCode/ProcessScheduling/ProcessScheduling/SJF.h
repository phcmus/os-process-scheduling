#pragma once
#include "Header.h"
#include "ScheduledProcess.h"
class SJF
{
public:
    SJF();
    ~SJF();
    static void sjf_findWaitingTime(vector<ScheduledProcess>& processes, int n, string& chart);
    static void sjf_scheduling(vector<ScheduledProcess> processes, int n);
};