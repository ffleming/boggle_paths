#ifndef __SOLVERH__
#define __SOLVERH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/queue.h>
unsigned long long solve(int sides, bool quiet);
unsigned long long solve_single(int row, int col, int sides, bool quiet);
unsigned long long solve_recursive(int row, int col, int sides, bool* visited, unsigned long long sum);
void *threaded_solve_single(void* t_state);
#endif
