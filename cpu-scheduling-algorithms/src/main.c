// main.c

#include "scheduling_algorithms.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process*)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter arrival time and burst time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    printf("\nChoose scheduling algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. SRTF\n4. Round Robin\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            srtf(processes, n);
            break;
        case 4:
            printf("Enter quantum time: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    free(processes);
    return 0;
}
