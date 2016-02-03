#include "bignum.h"
#include "solver.h"

void solve_bignum(int sides, mpz_t result) {
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

    printf("Solving with bignums for %dx%d grid...\n", sides, sides);

    for(int row = 0; row < use_rows; row++) {
        for(int col = 0; col < use_cols; col++) {
            if(sides_large_odd && (row == (use_rows-1) && col != (use_cols-1))) {
                continue;
            }
            bool* visited = calloc(sides*sides, sizeof(bool));
            mpz_set_ui(adder, 1);
            solve_bignum_recursive(row, col, sides, visited, adder);
            free(visited);
            printf("\tSolved square at row %d, column %d: %s\n", row+1, col+1, mpz_get_str(NULL, 10, adder));
            if(sides_even) {
                printf("\t\tEven sides; square will be used four times\n");
                mpz_mul_ui(adder, adder, 4);
            } else if(sides_large_odd) {
                if(row != use_rows-1 || col != use_cols-1) {
                    printf("\t\tOdd sides; square will be used four times\n");
                    mpz_mul_ui(adder, adder, 4);
                } else {
                    printf("\t\tCenter square is only used once\n");
                }
            }
            mpz_add(result, result, adder);
        }
    }
    mpz_clear(adder);
    return;
}

void solve_bignum_recursive(int cur_row, int cur_col, int sides, bool* visited, mpz_t sum) {
    bool* new_visited = malloc(sides * sides * sizeof(bool));
    mpz_t old_sum;
    mpz_init_set(old_sum, sum);
    mpz_t adder;
    mpz_init(adder);

    memcpy(new_visited, visited, sizeof(bool) * sides * sides);
    set_true(new_visited, sides, cur_row, cur_col);

    for(int row=0; row < sides; row++) {
        for(int col=0; col < sides; col++) {
            // Make sure cell at row&col is unvisited
            if(get_visited(visited, sides, row, col) == true) {
                continue;
            }
            // Make sure cell at row&col is a neighbor
            if(abs(cur_row - row) > 1) {
                continue;
            }
            if(abs(cur_col - col) > 1) {
                continue;
            }
            if(row == cur_row && col == cur_col) {
                continue;
            }

            // Code below this is only called for unvisited neighbors
            mpz_set(adder, old_sum);
            solve_bignum_recursive(row, col, sides, new_visited, adder);
            mpz_add(sum, sum, adder);
        }
    }
    mpz_clear(adder);
    free(new_visited);
    mpz_clear(old_sum);
    return;
}
