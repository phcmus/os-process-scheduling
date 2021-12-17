#include "Process.h"
Process::Process(string _name, int _arrivalTime, int _cpuBurst, int _priority)
{
    this->name = _name;
    this->arrivalTime = _arrivalTime;
    this->cpuBurst = _cpuBurst;
    this->priority = _priority;
};
Process::Process() 
{
    this->name = "";
    this->arrivalTime = 0;
    this->cpuBurst = 0;
    this->priority = 0;
};
Process::~Process() {}
void Process::updateChart(string& chart, Process process, int timestamp)
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
;

// Overload the < operator.
bool operator<(const Process& _process1, const Process& _process2)
{
    return (_process1.priority != _process2.priority) ? _process1.priority < _process2.priority : _process1.arrivalTime > _process2.arrivalTime;
}
// Overload the > operator.
bool operator>(const Process& _process1, const Process& _process2)
{
    return (_process1.priority != _process2.priority) ? _process1.priority > _process2.priority : _process1.arrivalTime < _process2.arrivalTime;
}