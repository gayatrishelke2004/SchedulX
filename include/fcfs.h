#pragma once
#include "../include/scheduler.h"
using namespace std;
class FCFS : public Scheduler {
public:
    void schedule(vector<Process>& processes) override;
};