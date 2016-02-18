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

unsigned long long solve_recursive(int cur_row, int cur_col, int sides,
        bool* visited, unsigned long long sum) {
    unsigned long long old_sum = sum;

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
            sum += (solve_recursive(row, col, sides, visited, old_sum));
        }
    }

    //set current cell to unvisited
    visited[(sides * cur_row) + cur_col] = false;
    return(sum);
}

