#include "solver.h"
#include "helper.h"

typedef struct thread_state {
    unsigned long long adder;
    int row;
    int col;
    int sides;
    bool quiet;
    int multiplier;
    pthread_t thread_id;
    SLIST_ENTRY(thread_state) next;
} thread_state;

unsigned long long solve_single(int row, int col, int sides, bool quiet) {
    bool* visited = calloc(sides*sides, sizeof(bool));
    if(!quiet) {
        printf("Solving for (%d, %d) on a %dx%d grid...\n",col+1, row+1, sides, sides);
    }
    unsigned long long ret = solve_recursive(row, col, sides, visited, 1);
    free(visited);
    return ret;
}

void *threaded_solve_single(void* t_state) {
    thread_state* args = t_state;
    args->adder = solve_single(args->row, args->col, args->sides, args->quiet);
    return &args->adder;
}

unsigned long long solve(int sides, bool quiet) {
    unsigned long long sum = 0;

    SLIST_HEAD(slist_thread_state, thread_state) head = SLIST_HEAD_INITIALIZER(head);
    SLIST_INIT(&head);

    if(!quiet) {
        printf("Solving for %dx%d grid...\n", sides, sides);
    }

    for(int row = 0; row < sides; row++) {
        for(int col = 0; col < sides; col++) {
            thread_state* t_state = malloc(sizeof(thread_state));
            t_state->adder = 0;
            t_state->row = row;
            t_state->col = col;
            t_state->sides = sides;
            t_state->quiet = quiet;
            t_state->thread_id = 0;

            if(is_duplicate(row, col, sides)) {
                continue;
            }

            SLIST_INSERT_HEAD(&head, t_state, next);
            pthread_create(&(t_state->thread_id), NULL, threaded_solve_single, t_state);

            if(!quiet) {
                printf("\tSolved square at row %d, column %d: %lld\n", row+1, col+1, t_state->adder);
            }
            t_state->multiplier = multiplier_for(row, col, sides, quiet);
        }
    }

    thread_state* el;
    SLIST_FOREACH(el, &head, next) {
        unsigned long long res;
        pthread_join(el->thread_id, (void*)&res);
        sum += (el->adder * el->multiplier);
        free(el);
    }
    free(&head);
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

