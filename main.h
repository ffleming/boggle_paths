#ifndef __MAINH__
#define __MAINH__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
void help(char* program_name, int code);
void output_bignums(int sides, bool quiet, int only_row, int only_col);
void parse_opts(int argc, char** argv, bool* quiet_flag, bool* bignum_flag,
        int* sides, int* only_row, int* only_col);
void print_board(int sides);
#endif
