#pragma once
#include "Header.h"
#include "ScheduledProcess.h"
class RR
{
public:
    RR();
    ~RR();
    static void rr_findWaitingTime(vector<ScheduledProcess>& processes, int n, int quantum, string& chart);
    static void rr_scheduling(vector<ScheduledProcess> processes, int n, int quantum);
};