# 42-philosophers

[![42 Porto](https://img.shields.io/badge/42%20Porto-School-blue?style=for-the-badge&logo=42)](https://www.42porto.com)
[![Language](https://img.shields.io/badge/Language-C-blue.svg?style=for-the-badge)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg?style=for-the-badge)](https://projects.intra.42.fr/)

## About

**Philosophers** is a project at 42 School that introduces the basics of threading a process and how to work on the same memory space. The goal is to learn how to create threads and discover the use of **mutexes** to manage concurrent access to shared resources.

It is a classic computer science problem: The Dining Philosophers Problem.

> *I never thought philosophy would be so deadly.*

### The Problem

- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively **eat**, **think**, or **sleep**.
- There are as many forks as there are philosophers.
- A philosopher needs **two forks** to eat.
- If a philosopher doesn't eat within a certain timeframe, they die of starvation.

## Tech Stack

- **Language:** C
- **Key Concepts:** Threads (pthread), Mutexes, Deadlocks, Race Conditions, Synchronization.

## Screenshots & Evaluation

![Screenshot Evaluation](screenshots/screenshot.png)

*Validated with 100/100*

## Instructions

### Compiling

To compile the mandatory part of the project, run:

```bash
make
```

This will generate an executable named `philo`.

### How to Use

The program takes the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
| :--- | :--- |
| **number_of_philosophers** | The number of philosophers and also the number of forks. |
| **time_to_die** (ms) | If a philosopher doesn't start eating *time_to_die* milliseconds after the beginning of their last meal (or the beginning of the simulation), they die. |
| **time_to_eat** (ms) | The time it takes for a philosopher to eat. During this time, they will need to hold two forks. |
| **time_to_sleep** (ms) | The time a philosopher will spend sleeping. |
| **[number_of_times...]** | (Optional) If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies. |

### Examples

Run with 5 philosophers, who die if they don't eat for 800ms, take 200ms to eat and 200ms to sleep:

```bash
./philo 5 800 200 200
```

Run with 4 philosophers, ensuring they survive (eating takes less time than starvation limit) and ensuring the simulation stops after each has eaten 7 times:

```bash
./philo 4 410 200 200 7
```

## Testing

I used this tester for debugging my code

- [dantonik/42-philosophers-tester](https://github.com/dantonik/42-philosophers-tester)

## Resources

- [Unix Threads in C (YouTube Playlist)](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [The Dining Philosophers Problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

