#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    string name;
    int arrivalTime;
    int burstTime;

    int responseTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};

bool compareProcesses(Process a, Process b)
{
    if (a.arrivalTime != b.arrivalTime)
    {
        return a.arrivalTime < b.arrivalTime;
    }
    return a.id < b.id;
}

void printTable(vector<Process> &processList)
{
    cout << "\n";
    cout << "+----+----------------+--------------+---------------+---------------+-------------------+--------------+-------------+\n";
    cout << "| ID | Process Name   | Arrival Time | Burst Time    | Response Time | Completion Time  | Waiting Time | Turn Around  |\n";
    cout << "+----+----------------+--------------+---------------+---------------+-------------------+--------------+-------------+\n";

    for (auto &proc : processList)
    {
        cout << "| " << setw(2) << proc.id << " | "
             << setw(14) << proc.name << " | "
             << setw(12) << proc.arrivalTime << " | "
             << setw(13) << proc.burstTime << " | "
             << setw(13) << proc.responseTime << " | "
             << setw(17) << proc.completionTime << " | "
             << setw(12) << proc.waitingTime << " | "
             << setw(11) << proc.turnAroundTime << " |\n";
    }

    cout << "+----+----------------+--------------+---------------+---------------+-------------------+--------------+-------------+\n";
}

int main()
{
    int numberOfProcesses;
    cout << "Enter no. of processes : ";
    cin >> numberOfProcesses;

    vector<Process> processList(numberOfProcesses);

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processList[i].id = (i + 1);
        cout << "\nEnter Process Name for " << (i + 1) << ": ";
        cin >> processList[i].name;
        cout << "Enter Arrival Time for Process " << (i + 1) << ": ";
        cin >> processList[i].arrivalTime;
        cout << "Enter Burst Time for Process " << (i + 1) << ": ";
        cin >> processList[i].burstTime;
    }

    sort(processList.begin(), processList.end(), compareProcesses);

    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int totalResponseTime = 0;
    int totalCompletionTime = 0;

    int sum = 0;

    for (int i = 0; i < numberOfProcesses; i++)
    {
        processList[i].waitingTime = sum - processList[i].arrivalTime;
        processList[i].completionTime = sum + processList[i].burstTime;
        processList[i].turnAroundTime = processList[i].completionTime - processList[i].arrivalTime;

        if (i == 0)
        {
            processList[i].responseTime = 0;
        }
        else
        {
            processList[i].responseTime = processList[i - 1].completionTime;
        }

        totalWaitingTime += processList[i].waitingTime;
        totalTurnAroundTime += processList[i].turnAroundTime;
        totalResponseTime += processList[i].responseTime;
        totalCompletionTime += processList[i].completionTime;

        sum += processList[i].burstTime;
    }

    printTable(processList);

    cout << "\n\nAverage Response Time for " << numberOfProcesses << " Processes: " << (float)totalResponseTime / numberOfProcesses;
    cout << "\n\nAverage Completion Time for " << numberOfProcesses << " Processes: " << (float)totalCompletionTime / numberOfProcesses;
    cout << "\n\nAverage Waiting Time for " << numberOfProcesses << " Processes: " << (float)totalWaitingTime / numberOfProcesses;
    cout << "\n\nAverage Turn Around Time for " << numberOfProcesses << " Processes: " << (float)totalTurnAroundTime / numberOfProcesses;
    cout << "\n\n";

    return 0;
}
