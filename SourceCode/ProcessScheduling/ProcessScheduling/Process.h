#pragma once
#include "Header.h"

class Process
{
public:
    string name;
    int arrivalTime;
    int cpuBurst;
    int priority;

    Process(string _name, int _arrivalTime, int _cpuBurst, int _priority);
    Process();
    ~Process();

    // Overload the < operator.
    friend bool operator<(const Process& _process1, const Process& _process2);
    // Overload the > operator.
    friend bool operator>(const Process& _process1, const Process& _process2);

    static void updateChart(string& chart, Process process, int timestamp);
};