#include "bignum.h"
#include "helper.h"

void solve_bignum_single(int row, int col, int sides, bool quiet, mpz_t result) {
    mpz_t placeholder;
    /* mpz_t adders[sides * sides]; */
    mpz_t* adders = malloc(sides * sides * sizeof(mpz_t));
    /* printf("%lu\n", sizeof(placeholder)); */
    /* mpz_array_init(adders, sides * sides, 16); */
    for(int i = 0; i < sides * sides; i++) {
        mpz_init(adders[i]);
    }
    mpz_init(placeholder);
    mpz_set_ui(result, 1);
    bool* visited = calloc(sides*sides, sizeof(bool));
    if(!quiet) {
        printf("Solving with bignums for (%d, %d) on a %dx%d grid...\n",col+1, row+1, sides, sides);
    }
    solve_bignum_recursive(row, col, sides, visited, result, placeholder, 0, adders);
    free(visited);
    mpz_clear(placeholder);
    return;
}

void solve_bignum(int sides, bool quiet, mpz_t result) {
    mpz_set_ui(result, 0);
    mpz_t adder;
    mpz_init(adder);

    if(!quiet) {
        printf("Solving with bignums for %dx%d grid...\n", sides, sides);
    }
    for(int row = 0; row < sides; row++) {
        for(int col = 0; col < sides; col++) {
            if(is_duplicate(row, col, sides)) {
                continue;
            }
            solve_bignum_single(row, col, sides, quiet, adder);
            if(!quiet) {
                char* out_string = mpz_get_str(NULL, 10, adder);
                printf("\tSolved square at row %d, column %d: %s\n", row+1, col+1, out_string);
                free(out_string);
            }
            mpz_mul_si(adder, adder, multiplier_for(row, col, sides, quiet));
            mpz_add(result, result, adder);
        }
    }
    mpz_clear(adder);
    return;
}

void solve_bignum_recursive(int cur_row, int cur_col, int sides, bool* visited, mpz_t sum, mpz_t old_sum, int depth, mpz_t* adders) {
    mpz_set(old_sum, sum);
    mpz_ptr adder = adders[depth];
    /* mpz_t adder; */
    /* mpz_init(adder); */

    int row, col;
    //set current cell to visited
    visited[(sides * cur_row) + cur_col] = true;
    for(int row_offset=-1; row_offset <= 1; row_offset++) {
        row = cur_row + row_offset;
        if(row < 0 || row >= sides) {
            continue;
        }
        for(int col_offset=-1; col_offset <= 1; col_offset++) {
            col = cur_col + col_offset;
            if(col < 0 || col >= sides) {
                continue;
            }
            if(row_offset == 0 && col_offset == 0) {
                continue;
            }
            //Continue if the cell has been visited
            if(visited[(sides * row) + col] == true) {
                continue;
            }
            // Code below this is only called for unvisited neighbors
            mpz_set(adder, old_sum);
            solve_bignum_recursive(row, col, sides, visited, adder, old_sum, depth + 1, adders);
            mpz_add(sum, sum, adder);
        }
    }
    /* mpz_clear(adder); */
    //Unvisit current cell
    visited[(sides * cur_row) + cur_col] = false;
    return;
}
