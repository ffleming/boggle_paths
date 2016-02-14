#include "bignum.h"
#include "helper.h"

void solve_bignum(int sides, bool quiet, mpz_t result) {
    mpz_set_ui(result, 0);
    mpz_t adder;
    mpz_init(adder);
    int use_rows = sides / 2 > 1 ? sides / 2 : 1;
    int use_cols = sides / 2 > 1 ? sides / 2 : 1;
    bool sides_even = (sides % 2 == 0);
    bool sides_large_odd = (!sides_even && sides > 1);
    if(sides_large_odd){
      use_rows += 1;
      use_cols += 1;
    }

    if(!quiet) {
        printf("Solving with bignums for %dx%d grid...\n", sides, sides);
    }
    bool* visited = calloc(sides*sides, sizeof(bool));
    for(int row = 0; row < use_rows; row++) {
        for(int col = 0; col < use_cols; col++) {
            if(sides_large_odd && (row == (use_rows-1) && col != (use_cols-1))) {
                continue;
            }
            mpz_set_ui(adder, 1);
            memset(visited, 0, sizeof(bool) * sides * sides);
            solve_bignum_recursive(row, col, sides, visited, adder);
            if(!quiet) {
                printf("\tSolved square at row %d, column %d: %s\n", row+1, col+1, mpz_get_str(NULL, 10, adder));
            }
            if(sides_even) {
                if(!quiet) {
                    printf("\t\tEven sides; square will be used four times\n");
                }
                mpz_mul_ui(adder, adder, 4);
            } else if(sides_large_odd) {
                if(row != use_rows-1 || col != use_cols-1) {
                    if(!quiet) {
                        printf("\t\tOdd sides; square will be used four times\n");
                    }
                    mpz_mul_ui(adder, adder, 4);
                } else {
                    if(!quiet){
                        printf("\t\tCenter square is only used once\n");
                    }
                }
            }
            mpz_add(result, result, adder);
        }
    }
    mpz_clear(adder);
    free(visited);
    return;
}

void solve_bignum_recursive(int cur_row, int cur_col, int sides, bool* visited, mpz_t sum) {
    mpz_t old_sum;
    mpz_init_set(old_sum, sum);
    mpz_t adder;
    mpz_init(adder);

    int row, col;
    set_true(visited, sides, cur_row, cur_col);
    for(int row_offset=-1; row_offset <= 1; row_offset++) {
        row = cur_row + row_offset;
        for(int col_offset=-1; col_offset <= 1; col_offset++) {
            col = cur_col + col_offset;
            if(col < 0 || row < 0 || col >= sides || row >= sides) {
                continue;
            }
            if(row_offset == 0 && col_offset == 0) {
                continue;
            }
            if(get_visited(visited, sides, row, col) == true) {
                continue;
            }
            // Code below this is only called for unvisited neighbors
            mpz_set(adder, old_sum);
            solve_bignum_recursive(row, col, sides, visited, adder);
            mpz_add(sum, sum, adder);
        }
    }
    mpz_clear(adder);
    mpz_clear(old_sum);
    set_false(visited, sides, cur_row, cur_col);
    return;
}
