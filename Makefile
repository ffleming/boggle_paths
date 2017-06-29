CC=gcc
CFLAGS=-std=c99 -Ofast -Wall
LIBS=-lpthread
GMP=-lgmp
BIN=boggle_paths
PROFILE_FLAGS=-q 4
all: clean bignum.o solver.o main.o helper.o
	$(CC) $(CFLAGS) -o $(BIN) bignum.o solver.o main.o helper.o $(LIBS) $(GMP)

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.c

solver.o:
	$(CC) $(CFLAGS) -c -o solver.o solver.c

bignum.o:
	$(CC) $(CFLAGS) -c -o bignum.o bignum.c

helper.o:
	$(CC) $(CFLAGS) -c -o helper.o helper.c

clean:
	-rm *.o $(BIN)

test: clean all
	./test.sh

profile: clean all
	./profile.sh

profile-long: clean all
	./profile.sh --long
