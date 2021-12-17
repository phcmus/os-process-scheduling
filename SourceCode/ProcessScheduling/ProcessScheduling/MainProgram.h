#pragma once
#include "Header.h"
#include "Process.h"
#include "ScheduledProcess.h"
#include "FCFS.h"
#include "RR.h"
#include "SJF.h"

class MainProgram
{
public:
	int runMenu();
	void feature1();
	void feature2();
	void feature3();
	void feature4();
	void feature5();
	bool readFile(priority_queue<Process, vector<Process>, less<vector<Process>::value_type>>& processes, int& quantum);
};

