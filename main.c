#include "main.h"
#include "solver.h"
#include "bignum.h"
#include "getopt.h"

int main(int argc, char** argv) {
    int sides = 0;
    bool quiet_flag = false;

    parse_opts(argc, argv, &quiet_flag, &sides);
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

void parse_opts(int argc, char** argv, bool* quiet_flag, int* sides) {
    int c;
    while((c = getopt(argc, argv, "qh")) != -1) {
        switch(c) {
            case 'q':
                *quiet_flag = true;
                break;
            case 'h':
                help(argv[0], 0);
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
    printf("%s [-h] [-q] <SIDES>\n", program_name);
    printf("   SIDES defaults to 4 if not specified\n\n");
    printf("   -q\t\tSuppress status output\n");
    printf("   -h\t\tThis help\n");
    exit(code);
}
