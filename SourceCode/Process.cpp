#pragma once
#include "Base.cpp"

class Process
{
public:
    string name;
    int arrivalTime;
    int cpuBurst;
    int priority;

    Process(string _name, int _arrivalTime, int _cpuBurst, int _priority)
    {
        this->name = _name;
        this->arrivalTime = _arrivalTime;
        this->cpuBurst = _cpuBurst;
        this->priority = _priority;
    };
    Process(){};
    ~Process(){};

    // Overload the < operator.
    friend bool operator<(const Process &_process1, const Process &_process2)
    {
        return (_process1.priority != _process2.priority) ? _process1.priority < _process2.priority : _process1.arrivalTime > _process2.arrivalTime;
    }
    // Overload the > operator.
    friend bool operator>(const Process &_process1, const Process &_process2)
    {
        return (_process1.priority != _process2.priority) ? _process1.priority > _process2.priority : _process1.arrivalTime < _process2.arrivalTime;
    }
};

static void updateChart(string &chart, Process process, int timestamp)
{
    size_t found_last = chart.find_last_of("~");
    size_t found_last_last = chart.substr(0, found_last - 1).find_last_of("~");
    string last_process = chart.substr(found_last_last + 1, found_last - found_last_last - 1);

    if (process.name != last_process)
    {
        string newProcess = "~" + process.name + "~" + to_string(timestamp);
        chart += newProcess;
    }
    else
    {
        chart.replace(chart.begin() + found_last + 1, chart.end(), to_string(timestamp));
    }
}