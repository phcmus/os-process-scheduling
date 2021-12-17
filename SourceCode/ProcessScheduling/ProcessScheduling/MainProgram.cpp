#include "MainProgram.h"

priority_queue<Process, vector<Process>, less<vector<Process>::value_type>> processes;
int quantum = 0;

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

int MainProgram::runMenu()
{
	int choice = -1;
	int maxChoice = 5;
	do
	{
		system("cls");
		while (!processes.empty()) processes.pop();
		cout << "Welcome to our program!" << endl << "Please select the function you want to execute below!" << endl;
		cout << '\t' << "1. First come, first served." << endl;
		cout << '\t' << "2. Round Robin." << endl;
		cout << '\t' << "3. Shortest job first." << endl;
		cout << '\t' << "4. All. After execution, the program will generate 3 files corresponding to 3 scheduling algorithms above." << endl;
		cout << '\t' << "5. Quit." << endl;
		cout << "Your choice: ";
		cin >> choice;
		if (choice < 1 || choice > maxChoice)
		{
			cout << "Feature not found! Please select feature from 1 to " << maxChoice << "!" << endl;
			cout << "Press Enter to continue!";
			system("pause");
		}
	} while (choice < 1 || choice > maxChoice);
	return choice;
}

void MainProgram::feature1()
{
	while (!readFile(processes, quantum)) { system("pause"); }
	vector<Process> vProcess(0);
	vector<ScheduledProcess> vScheduledProcess(0);
	priorityqueue2vector(processes, vProcess);
	for (int i = 0; i < vProcess.size(); i++)
	{
		vScheduledProcess.push_back((ScheduledProcess)vProcess[i]);
	}

	FCFS::fcfs_scheduling(vScheduledProcess, vScheduledProcess.size());
}

void MainProgram::feature2()
{
	while (!readFile(processes, quantum)) { system("pause"); }
	vector<Process> vProcess(0);
	vector<ScheduledProcess> vScheduledProcess(0);
	priorityqueue2vector(processes, vProcess);
	for (int i = 0; i < vProcess.size(); i++)
	{
		vScheduledProcess.push_back((ScheduledProcess)vProcess[i]);
	}

	RR::rr_scheduling(vScheduledProcess, vScheduledProcess.size(), quantum);
}

void MainProgram::feature3()
{
	while (!readFile(processes, quantum)) { system("pause"); }
	vector<Process> vProcess(0);
	vector<ScheduledProcess> vScheduledProcess(0);
	priorityqueue2vector(processes, vProcess);
	for (int i = 0; i < vProcess.size(); i++)
	{
		vScheduledProcess.push_back((ScheduledProcess)vProcess[i]);
	}

	SJF::sjf_scheduling(vScheduledProcess, vScheduledProcess.size());
}

void MainProgram::feature4()
{
	while (!readFile(processes, quantum)) { system("pause"); }
	vector<Process> vProcess(0);
	vector<ScheduledProcess> vScheduledProcess(0);
	priorityqueue2vector(processes, vProcess);
	for (int i = 0; i < vProcess.size(); i++)
	{
		vScheduledProcess.push_back((ScheduledProcess)vProcess[i]);
	}
	FCFS::fcfs_scheduling(vScheduledProcess, vScheduledProcess.size());
	RR::rr_scheduling(vScheduledProcess, vScheduledProcess.size(), quantum);
	SJF::sjf_scheduling(vScheduledProcess, vScheduledProcess.size());
}

void MainProgram::feature5()
{
}

bool MainProgram::readFile(priority_queue<Process, vector<Process>, less<vector<Process>::value_type>>& processes, int& quantum)
{
	string filename = "Input.txt";
	ifstream inputfile(filename);
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
		cout << "File not exist! Press enter to reload file!" << endl;
		return false;
	}
	inputfile.close();
	return true;
}