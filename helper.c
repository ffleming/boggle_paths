#include "helper.h"

bool is_duplicate(int row, int col, int sides) {
    int use_rows = sides / 2 > 1 ? sides / 2 : 1;
    int use_cols = sides / 2 > 1 ? sides / 2 : 1;
    bool sides_even = (sides % 2 == 0);
    bool sides_large_odd = (!sides_even && sides > 1);
    if(sides_large_odd){
      use_rows += 1;
      use_cols += 1;
    }
    if(row >= use_rows || col >= use_cols) {
        return true;
    }
    if(sides_large_odd && (row == (use_rows-1) && col != (use_cols-1))) {
        return true;
    }
    return false;
}

int multiplier_for(int row, int col, int sides, bool quiet) {
    int use_rows = sides / 2 > 1 ? sides / 2 : 1;
    int use_cols = sides / 2 > 1 ? sides / 2 : 1;
    bool sides_even = (sides % 2 == 0);
    bool sides_large_odd = (!sides_even && sides > 1);
    if(sides_even) {
        if(!quiet) {
            printf("\t\tEven sides; square will be used four times\n");
        }
        return 4;
    } else if(sides_large_odd) {
        if(row != use_rows-1 || col != use_cols-1) {
            if(!quiet) {
                printf("\t\tOdd sides; square will be used four times\n");
            }
            return 4;
        } else {
            if(!quiet) {
                printf("\t\tCenter square is only used once\n");
            }
            return 1;
        }
    }
    return 1;
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
