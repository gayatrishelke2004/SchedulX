#include <iostream>
#include <vector>
#include <fstream>
#include "../include/process.h"
#include "../include/fcfs.h"

int main() {
    std::vector<Process> processes = {
        Process(1, 0, 4),
        Process(2, 2, 3),
        Process(3, 4, 1)
    };

    FCFS scheduler;
    scheduler.schedule(processes);

    std::cout << "PID  Arrival  Burst  Start  Completion Waiting  Turnaround\n";
    for (const auto& p : processes) {
        std::cout << p.pid << "     " << p.arrivalTime << "       "
                  << p.burstTime << "      " << p.startTime << "      "
                  << p.completionTime << "          " << p.waitTime << "           "
                  << p.turnaroundTime << "\n";
    }

    // ✅ This block must be inside main()
    std::ofstream fout("process_log.csv");
    fout << "PID,Start,Burst\n";
    for (const auto& p : processes) {
        fout << p.pid << "," << p.startTime << "," << p.burstTime << "\n";
    }
    fout.close();

    return 0;
}