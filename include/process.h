#pragma once
#include <string>
using namespace std;
class Process 
{
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int completionTime;
    int waitTime;
    int turnaroundTime;

    Process(int id, int at, int bt, int pr = 0);
};