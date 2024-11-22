// srtf.c

#include "scheduling_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

void srtf(Process *processes, int n) {
    int total_wait_time = 0, total_turnaround_time = 0;
    int current_time = 0, remaining_processes = n;
    int *remaining_burst_time = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    while (remaining_processes > 0) {
        int min_remaining_time = 9999;
        int min_index = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && remaining_burst_time[i] > 0 && remaining_burst_time[i] < min_remaining_time) {
                min_remaining_time = remaining_burst_time[i];
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
            continue;
        }

        remaining_burst_time[min_index]--;
        current_time++;

        if (remaining_burst_time[min_index] == 0) {
            processes[min_index].waiting_time = current_time - processes[min_index].arrival_time - processes[min_index].burst_time;
            processes[min_index].turnaround_time = processes[min_index].waiting_time + processes[min_index].burst_time;
            total_wait_time += processes[min_index].waiting_time;
            total_turnaround_time += processes[min_index].turnaround_time;
            remaining_processes--;
        }
    }

    free(remaining_burst_time);
    calculate_wait_and_turnaround_times(processes, n);
    print_processes(processes, n);
}
