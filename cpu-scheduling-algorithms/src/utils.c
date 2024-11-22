// utils.c

#include "scheduling_algorithms.h"
#include <stdio.h>

void calculate_wait_and_turnaround_times(Process *processes, int n) {
    int total_wait_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_wait_time += processes[i].waiting_time;
    }

    float average_wait_time = (float) total_wait_time / n;
    float average_turnaround_time = (float) total_turnaround_time / n;

    printf("Average Wait Time: %.2f\n", average_wait_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

void print_processes(Process *processes, int n) {
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}
