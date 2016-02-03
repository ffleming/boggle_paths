CC=gcc
CFLAGS=-std=c99 -Ofast
LIBS=
GMP=-lgmp
BIN=boggle_paths
all: clean bignum.o solver.o main.o
	$(CC) $(CFLAGS) -o $(BIN) bignum.o solver.o main.o $(LIBS) $(GMP)

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.c $(LIBS)

solver.o:
	$(CC) $(CFLAGS) -c -o solver.o solver.c $(LIBS)

bignum.o:
	$(CC) $(CFLAGS) -c -o bignum.o bignum.c $(LIBS)

clean:
	-rm *.o $(BIN)
