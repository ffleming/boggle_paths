CC=gcc
CFLAGS=-std=c99 -Ofast
LIBS=
GMP=-lgmp
BIN=boggle_paths
PROFILE_FLAGS=-q
all: clean bignum.o solver.o main.o helper.o
	$(CC) $(CFLAGS) -o $(BIN) bignum.o solver.o main.o helper.o $(LIBS) $(GMP)

main.o:
	$(CC) $(CFLAGS) -c -o main.o main.c $(LIBS)

solver.o:
	$(CC) $(CFLAGS) -c -o solver.o solver.c $(LIBS)

bignum.o:
	$(CC) $(CFLAGS) -c -o bignum.o bignum.c $(LIBS)

helper.o:
	$(CC) $(CFLAGS) -c -o helper.o helper.c $(LIBS)

clean:
	-rm *.o $(BIN)

profile: clean all
	for arg in 1 2 3 4 ; do \
		echo "\n$$arg sides:"; \
		time ./$(BIN) $(PROFILE_FLAGS) $$arg; \
	done
