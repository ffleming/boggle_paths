#include "main.h"
#include "solver.h"
#include "bignum.h"

int main(int argc, char** argv) {
    int sides = 0;
    switch(argc) {
        case 1:
            sides = 4;
            break;
        case 2:
            if(strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0) {
                help(argv[0], 0);
            }
            sides = atoi(argv[1]);
            if(sides == 0) {
                printf("Can't parse %s as an integer\n", argv[1]);
                help(argv[0], 2);
            }
            break;
        default:
            help(argv[0], 1);
    }
    if(sides >= 6) {
      output_bignums(sides);
    } else {
        printf("A board with %d sides has %llu possible solutions\n", sides, solve(sides));
    }
    exit(0);
}

void output_bignums(int sides) {
    mpz_t answer;
    mpz_init(answer);
    mpz_set_ui(answer, 0);
    solve_bignum(sides, answer);
    printf("A board with %d sides has %s possible solutions\n", sides, mpz_get_str(NULL, 10, answer));
    mpz_clear(answer);
    return;
}

void help(char* program_name, int code) {
    printf("%s [-h] <SIDES>\n", program_name);
    printf("   SIDES defaults to 4 if not specified\n\n");
    printf("   -h, --help\t\tThis help\n");
    exit(code);
}
