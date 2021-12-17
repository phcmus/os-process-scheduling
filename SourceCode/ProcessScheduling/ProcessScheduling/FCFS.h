#pragma once
#include "Header.h"
#include "ScheduledProcess.h"
class FCFS
{
public:
	static void fcfs_findWaitingTime(vector<ScheduledProcess>& processes, int n, string& chart);
	static void fcfs_scheduling(vector<ScheduledProcess> processes, int n);
	FCFS();
	~FCFS();
};