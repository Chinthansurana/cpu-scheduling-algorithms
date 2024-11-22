// scheduling_algorithms.h

#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int remaining_time;  // Used for SRTF
    int waiting_time;    // Added for calculating waiting time
    int turnaround_time; // Added for calculating turnaround time
} Process;

void fcfs(Process *processes, int n);
void sjf(Process *processes, int n);
void srtf(Process *processes, int n);
void round_robin(Process *processes, int n, int quantum);
void calculate_wait_and_turnaround_times(Process *processes, int n);
void print_processes(Process *processes, int n);

#endif
