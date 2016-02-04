#ifndef __SOLVERH__
#define __SOLVERH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long long solve(int sides, bool quiet);
unsigned long long solve_recursive(int, int, int, bool*, unsigned long long);
void set_true(bool*, int, int, int);
bool get_visited(bool*, int, int, int);
void print_board(bool*, int);
#endif
