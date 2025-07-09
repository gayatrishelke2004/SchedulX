#pragma once
#include <vector>
#include "../include/process.h"
using namespace std;
class Scheduler {
public:
    virtual void schedule(vector<Process>& processes) = 0;
    virtual ~Scheduler() = default;
};