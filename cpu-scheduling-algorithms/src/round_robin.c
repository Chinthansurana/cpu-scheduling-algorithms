// round_robin.c

#include "scheduling_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

void round_robin(Process *processes, int n, int quantum) {
    int total_wait_time = 0, total_turnaround_time = 0;
    int remaining_processes = n;
    int *remaining_burst_time = (int*)malloc(n * sizeof(int));
    int *waiting_time = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int current_time = 0;
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > quantum) {
                    remaining_burst_time[i] -= quantum;
                    current_time += quantum;
                } else {
                    current_time += remaining_burst_time[i];
                    waiting_time[i] = current_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = waiting_time[i] + processes[i].burst_time;
                    total_wait_time += waiting_time[i];
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_burst_time[i] = 0;
                    remaining_processes--;
                }
            }
        }
    }

    free(remaining_burst_time);
    free(waiting_time);
    calculate_wait_and_turnaround_times(processes, n);
    print_processes(processes, n);
}
