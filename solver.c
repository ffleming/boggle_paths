#include "solver.h"
#include "helper.h"

unsigned long long solve_single(int row, int col, int sides, bool quiet) {
    bool* visited = calloc(sides*sides, sizeof(bool));
    if(!quiet) {
        printf("Solving for (%d, %d) on a %dx%d grid...\n",col+1, row+1, sides, sides);
    }
    unsigned long long ret = solve_recursive(row, col, sides, visited, 1);
    free(visited);
    return ret;
}

unsigned long long solve(int sides, bool quiet) {
    unsigned long long sum = 0;
    unsigned long long adder = 1;
    int use_rows = sides / 2 > 1 ? sides / 2 : 1;
    int use_cols = sides / 2 > 1 ? sides / 2 : 1;
    bool sides_even = (sides % 2 == 0);
    bool sides_large_odd = (!sides_even && sides > 1);
    if(sides_large_odd){
      use_rows += 1;
      use_cols += 1;
    }
    if(!quiet) {
        printf("Solving for %dx%d grid...\n", sides, sides);
    }

    for(int row = 0; row < sides; row++) {
        for(int col = 0; col < sides; col++) {
            if(is_duplicate(row, col, sides)) {
                continue;
            }
            adder = solve_single(row, col, sides, quiet);
            if(!quiet) {
                printf("\tSolved square at row %d, column %d: %lld\n", row+1, col+1, adder);
            }
            adder *= multiplier_for(row, col, sides, quiet);
            sum += adder;
        }
    }
    return(sum);
}

unsigned long long solve_recursive(int cur_row, int cur_col, int sides, bool* visited, unsigned long long sum) {
    unsigned long long old_sum = sum;

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
            sum += (solve_recursive(row, col, sides, visited, old_sum));
        }
    }

    set_false(visited, sides, cur_row, cur_col);
    return(sum);
}

