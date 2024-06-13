# CPU Scheduling Algorithms

This repository contains various CPU scheduling algorithms implemented in C++. The following algorithms are included:

- **First-Come, First-Served (FCFS)**
- **Shortest Job First (SJF)**
  - Preemptive
  - Non-preemptive
- **Priority Scheduling**
  - Preemptive
  - Non-preemptive
- **Round Robin (RR)**

## Table of Contents

- [Introduction](#introduction)
- [Algorithms](#algorithms)
  - [First-Come, First-Served (FCFS)](#first-come-first-served-fcfs)
  - [Shortest Job First (SJF)](#shortest-job-first-sjf)
  - [Priority Scheduling](#priority-scheduling)
  - [Round Robin (RR)](#round-robin-rr)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

CPU scheduling is a vital part of an operating system's functionality. This project showcases different CPU scheduling algorithms, illustrating their differences and use cases. Each algorithm is implemented in C++.

## Algorithms

### First-Come, First-Served (FCFS)

The FCFS scheduling algorithm is the simplest type of CPU scheduling algorithm that schedules according to the arrival times of various processes.

### Shortest Job First (SJF)

The SJF scheduling algorithm selects the process with the smallest next burst time to execute next. It can be implemented in two ways:

- **Preemptive**: Also known as Shortest Remaining Time First (SRTF).
- **Non-preemptive**: The process which arrives first with the shortest burst time is selected.

### Priority Scheduling

Priority scheduling algorithm selects the process with the highest priority. It can also be implemented in two ways:

- **Preemptive**: If a new process arrives with a higher priority than the current running process, the CPU is preempted to the new process.
- **Non-preemptive**: The CPU is allocated to the process with the highest priority.

### Round Robin (RR)

Round Robin scheduling algorithm assigns a fixed time quantum per process and cycles through them, ensuring fair CPU allocation.

## Installation

To compile and run these algorithms, you need a C++ compiler installed on your system. You can use `g++`, which is a part of the GNU Compiler Collection (GCC).

1. Clone the repository:

   ```bash
   git clone https://github.com/AakashR-325/CPU-Scheduler
   ```

2. Enter the respective folder for the required algorithm:

   ```bash
   cd <name-of-desired-folder>
   ```

3. Run the executable file :

   ```bash
   ./<name-of-respective-executable> (FCFS , NPSJF , PSJF , NPP , PP , RR)
   ```

## Usage

After running the executable, you will be prompted to choose a scheduling algorithm and enter the details of the processes (such as arrival time, burst time, and priority). The program will then simulate the scheduling process and output the order of execution along with other relevant metrics.
