#include "getopt.h"
#include "main.h"
#include "solver.h"
#include "bignum.h"

int main(int argc, char** argv) {
    int sides = 0;
    bool quiet_flag = false;
    int only_row = 0;
    int only_col = 0;

    parse_opts(argc, argv, &quiet_flag, &sides, &only_row, &only_col);
    if(sides <= 0) {
        help(argv[0], 1);
    }
    if(sides >= 7) {
        output_bignums(sides, quiet_flag);
    } else {
        printf("A board with %d sides has %llu possible solutions\n", sides, solve(sides, quiet_flag));
    }
    exit(0);
}

void parse_opts(int argc, char** argv, bool* quiet_flag, int* sides, int* only_row, int* only_col) {
    int c;
    int ret;
    while((c = getopt(argc, argv, "qho:")) != -1) {
        switch(c) {
            case 'q':
                *quiet_flag = true;
                break;
            case 'h':
                help(argv[0], 0);
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

void output_bignums(int sides, bool quiet) {
    mpz_t answer;
    mpz_init(answer);
    solve_bignum(sides, quiet, answer);
    printf("A board with %d sides has %s possible solutions\n", sides, mpz_get_str(NULL, 10, answer));
    mpz_clear(answer);
    return;
}

void help(char* program_name, int code) {
    printf("%s [-h] [-q] [-o COL,ROW] <SIDES>\n", program_name);
    printf("   SIDES defaults to 4 if not specified\n\n");
    printf("   -q\t\tSuppress status output\n");
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

