#include "Base.cpp"
#include "Process.cpp"
#include "FCFS.cpp"
#include "RR.cpp"
#include "SJF.cpp"

bool readFile(priority_queue<Process, vector<Process>, less<vector<Process>::value_type>> &processes, int &quantum)
{
    ifstream inputfile(fileName);
    if (inputfile.is_open())
    {
        int n = 0;
        inputfile >> n >> quantum;

        while (!inputfile.eof())
        {
            Process temp;
            inputfile >> temp.name >> temp.arrivalTime >> temp.cpuBurst >> temp.priority;
            processes.push(temp);
        }
    }
    else
    {
        cout << "Mo file khong thanh cong! File khong ton tai!" << endl;
        return false;
    }
    inputfile.close();
    return true;
}

void priorityqueue2vector(priority_queue<Process> src, vector<Process>& dest)
{
    dest = vector<Process>(0);
    while (src.size() != 0)
    {
        Process temp = src.top();
        dest.push_back(temp);
        src.pop();
    }
}
int main()
{
    priority_queue<Process, vector<Process>, less<vector<Process>::value_type>> processes;
    
    int quantum = 0;
    bool isReadedQueue = readFile(processes, quantum);
    if (isReadedQueue)
    {
        vector<Process> vProcess(0);
        vector<ScheduledProcess> vScheduledProcess(0);
        priorityqueue2vector(processes, vProcess);
        for (int i = 0; i < vProcess.size(); i++)
        {
            vScheduledProcess.push_back((ScheduledProcess) vProcess[i]);
        }

        // fcfs_scheduling(vScheduledProcess, vScheduledProcess.size());
        // rr_scheduling(vScheduledProcess, vScheduledProcess.size(), quantum);
        // sjf_scheduling(vScheduledProcess, vScheduledProcess.size());        
    }

    return 0;
}