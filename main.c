#include "getopt.h"
#include "main.h"
#include "solver.h"
#include "bignum.h"

int main(int argc, char** argv) {
    int sides = 0;
    bool quiet_flag = false;
    bool bignum_flag = false;
    int only_row = 0;
    int only_col = 0;

    parse_opts(argc, argv, &quiet_flag, &bignum_flag, &sides, &only_row, &only_col);
    if(sides <= 0) {
        help(argv[0], 1);
    }
    if(sides >= 7 || bignum_flag) {
        output_bignums(sides, quiet_flag, only_row, only_col);
    } else {
        unsigned long long result;
        if(only_row != 0 && only_col != 0) {
            result = solve_single(only_row - 1, only_col - 1, sides, quiet_flag);
            printf("Cell (%d, %d) on a board with %d sides is the starting point of %llu paths\n",
                    only_col, only_row, sides, result);
        } else {
            result = solve(sides, quiet_flag);
            printf("A board with %d sides has %llu possible solutions\n", sides, result);
        }
    }
    exit(0);
}

void parse_opts(int argc, char** argv, bool* quiet_flag, bool* bignum_flag, int* sides,
        int* only_row, int* only_col) {
    int c;
    int ret;
    while((c = getopt(argc, argv, "qhbo:")) != -1) {
        switch(c) {
            case 'q':
                *quiet_flag = true;
                break;
            case 'h':
                help(argv[0], 0);
                break;
            case 'b':
                *bignum_flag = true;
                break;
            case 'o':
                ret = sscanf(optarg, "%d,%d", only_col, only_row);
                if(ret != 2 || *only_col <= 0 || *only_row <= 0) {
                    printf("-o requires COL,ROW (indexed starting from 1)\n");
                    help(argv[0], 1);
                }
                break;
            default:
                help(argv[0], 1);
        }
    }

    if(argc == optind) {
        *sides = 4;
    } else if(optind + 1 == argc) {
        *sides = atoi(argv[optind]);
    }
}

void output_bignums(int sides, bool quiet, int only_row, int only_col) {
    mpz_t answer;
    mpz_init(answer);
    if (only_row != 0 && only_col != 0) {
        solve_bignum_single(only_row - 1, only_col - 1, sides, quiet, answer);
        printf("Cell (%d, %d) on a board with %d sides is the starting point of %s paths\n",
                only_col, only_row, sides, mpz_get_str(NULL, 10, answer));
    } else {
        char* out_string;
        solve_bignum(sides, quiet, answer);
        out_string = mpz_get_str(NULL, 10, answer);
        printf("A board with %d sides has %s possible solutions\n", sides, out_string);
        free(out_string);
    }
    mpz_clear(answer);
    return;
}

void help(char* program_name, int code) {
    printf("%s [-qbh] [-o COL,ROW] <SIDES>\n", program_name);
    printf("   SIDES defaults to 4 if not specified\n\n");
    printf("   -q\t\tSuppress status output\n");
    printf("   -b\t\tForce using the GMP bignum library\n");
    printf("   -h\t\tThis help\n");
    printf("   -o\t\tOnly solve for cell specified by COL and ROW\n");
    printf("   \t\tBoard is indexed as follows:\n");
    print_board(6);
    exit(code);
}

void print_board(int sides) {
    printf("\t\t   ");
    for(int col = 1; col <= sides; col++) {
        printf("\e[4m%d \e[0m", col);
    }
    printf("\n");
    for(int row=0; row < sides; row++) {
        printf("\t\t%d |", row + 1);
        for(int col=0; col < sides; col++) {
            printf("\e[4m \e[0m");
            printf("\e[4m|\e[0m");
        }
        printf("\n");
    }
    printf("\n");
}

