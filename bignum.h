#ifndef __BIGNUMH__
#define __BIGNUMH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
void solve_bignum(int sides, mpz_t result);
void solve_bignum_recursive(int row, int col, int sides, bool* visited, mpz_t sum);
#endif
