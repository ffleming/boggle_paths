#ifndef __MAINH__
#define __MAINH__
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
void help(char*, int);
void output_bignums(int, bool, int, int);
void parse_opts(int argc, char** argv, bool*, int*, int*, int*);
void print_board(int);
#endif
