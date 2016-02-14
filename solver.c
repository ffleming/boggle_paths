#include "solver.h"

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

    bool* visited = calloc(sides*sides, sizeof(bool));
    for(int row = 0; row < use_rows; row++) {
        for(int col = 0; col < use_cols; col++) {
            if(sides_large_odd && (row == (use_rows-1) && col != (use_cols-1))) {
                continue;
            }
            memset(visited, 0, sizeof(bool) * sides * sides);
            adder = solve_recursive(row, col, sides, visited, 1);
            if(!quiet) {
                printf("\tSolved square at row %d, column %d: %lld\n", row+1, col+1, adder);
            }
            if(sides_even) {
                if(!quiet) {
                    printf("\t\tEven sides; square will be used four times\n");
                }
                adder *= 4;
            } else if(sides_large_odd) {
                if(row != use_rows-1 || col != use_cols-1) {
                    if(!quiet) {
                        printf("\t\tOdd sides; square will be used four times\n");
                    }
                    adder *= 4;
                } else {
                    if(!quiet) {
                        printf("\t\tCenter square is only used once\n");
                    }
                }
            }
            sum += adder;
        }
    }
    free(visited);
    return(sum);
}

void print_board(bool* board, int sides) {
    for(int row=0; row < sides; row++) {
        printf("|");
        for(int col=0; col < sides; col++) {
            if(get_visited(board, sides, row, col)) {
                printf("X");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
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

void set_true(bool* board, int sides, int row, int col) {
    set_val(board, sides, row, col, true);
}

void set_false(bool* board, int sides, int row, int col) {
    set_val(board, sides, row, col, false);
}

void set_val(bool* board, int sides, int row, int col, bool val) {
    board[(sides * row) + col] = val;
}

bool get_visited(bool* board, int sides, int row, int col) {
    return( board[(sides * row) + col] );
}
