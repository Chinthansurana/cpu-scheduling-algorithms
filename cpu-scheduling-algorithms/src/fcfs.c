// fcfs.c

#include "scheduling_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

void fcfs(Process *processes, int n) {
    int total_wait_time = 0, total_turnaround_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        current_time += processes[i].burst_time;
    }

    calculate_wait_and_turnaround_times(processes, n);
    print_processes(processes, n);
}
