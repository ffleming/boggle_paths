#ifndef __BIGNUMH__
#define __BIGNUMH__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
void solve_bignum(int sides, bool quiet, mpz_t result);
void solve_bignum_single(int row, int col, int sides, bool quiet, mpz_t result);
void solve_bignum_recursive(int row, int col, int sides, bool* visited, mpz_t sum,
        mpz_t placeholder, int depth, mpz_t* adder_array);
#endif
