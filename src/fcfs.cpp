#include "../include/fcfs.h"
#include "../include/process.h"
#include "../include/scheduler.h"
#include <algorithm>
void FCFS::schedule(vector<Process>& processes) 
{
    sort(processes.begin(), processes.end(),
              [](Process a, Process b) { return a.arrivalTime < b.arrivalTime; });

    int currentTime = 0;
    for (auto& p : processes) {
        p.startTime = std::max(currentTime, p.arrivalTime);
        p.completionTime = p.startTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitTime = p.turnaroundTime - p.burstTime;
        currentTime = p.completionTime;
    }
}