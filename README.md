# CPU Scheduling Simulation

This project simulates advanced CPU scheduling algorithms using C: First Come First Serve (FCFS), Shortest Job First (SJF), Shortest Remaining Time First (SRTF), and Round Robin (RR). The program calculates performance metrics like waiting time and turnaround time for each algorithm and provides insights into optimizing multi-threaded processing systems.

## Features
- **FCFS Scheduling**: Processes are executed in the order they arrive.
- **SJF Scheduling**: The process with the shortest burst time is selected next.
- **SRTF Scheduling**: A preemptive version of SJF where the process with the shortest remaining burst time is executed next.
- **Round Robin Scheduling**: Processes are executed in a cyclic order with a fixed time quantum.
- **Performance Metrics**: Computes and displays waiting time, turnaround time, and average metrics for each algorithm.

## Prerequisites
- A C compiler (e.g., `gcc`) should be installed.
- Basic understanding of CPU scheduling algorithms.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cpu-scheduling-simulation.git
   cd cpu-scheduling-simulation
2. Compile the program using make:
    ```bash
    make
3. Run the program:
    ```bash
    ./scheduling_simulation
4. To run predefined test cases, use:
    ```bash
    make test