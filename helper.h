#ifndef __HELPERH__
#define __HELPERH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void set_true(bool* board, int sides, int row, int col);
void set_false(bool* board, int sides, int row, int col);
void set_val(bool* board, int sides, int row, int col, bool val);
bool get_visited(bool* board, int sides, int row, int col);
bool is_duplicate(int row, int col, int sides);
int multiplier_for(int row, int col, int sides, bool quiet);
#endif
