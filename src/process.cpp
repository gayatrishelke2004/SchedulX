#include "../include/process.h"

// Constructor Implementation
Process::Process(int id, int at, int bt, int pr)
    : pid(id), 
      arrivalTime(at), 
      burstTime(bt), 
      priority(pr),
      startTime(0),
      completionTime(0),
      waitTime(0),
      turnaroundTime(0) 
{}