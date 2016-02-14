#ifndef __HELPERH__
#define __HELPERH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void set_true(bool*, int, int, int);
void set_false(bool*, int, int, int);
void set_val(bool*, int, int, int, bool);
bool get_visited(bool*, int, int, int);
void print_board(bool*, int);
bool is_duplicate(int row, int col, int sides);
int multiplier_for(int row, int col, int sides, bool quiet);
#endif
