Boggle paths
--

This simply calculates the number of possible paths given a board with a
particular number of sides.  Compile with
```
% make
```
and run with
```
./boggle_paths [-h] [-q] [-o COL,ROW] <SIDES>
   SIDES defaults to 4 if not specified

   -q		Suppress status output
   -h		This help
   -o		Only solve for cell specified by COL and ROW
   		Board is indexed as follows:
		   1 2 3 4 5 6
		1 | | | | | | |
		2 | | | | | | |
		3 | | | | | | |
		4 | | | | | | |
		5 | | | | | | |
		6 | | | | | | |
```

###Calculated results
Results calculated on a Raspberry Pi 2

```
fsf@arm ~/boggle_paths $ make profile
rm *.o boggle_paths
gcc -std=c99 -Ofast -Wall -c -o bignum.o bignum.c
gcc -std=c99 -Ofast -Wall -c -o solver.o solver.c
gcc -std=c99 -Ofast -Wall -c -o main.o main.c
gcc -std=c99 -Ofast -Wall -c -o helper.o helper.c
gcc -std=c99 -Ofast -Wall -o boggle_paths bignum.o solver.o main.o helper.o  -lgmp
for arg in 1 2 3 4 ; do \
	echo "\n$arg sides:"; \
	time ./boggle_paths -q $arg; \
done

1 sides:
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1412maxresident)k
0inputs+0outputs (0major+81minor)pagefaults 0swaps

2 sides:
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
0inputs+0outputs (0major+79minor)pagefaults 0swaps

3 sides:
A board with 3 sides has 10305 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

4 sides:
A board with 4 sides has 12029640 possible solutions
0.61user 0.00system 0:00.61elapsed 98%CPU (0avgtext+0avgdata 1224maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps
```

```
A board with 5 sides has 115066382913 possible solutions

real    110m23.925s
user    110m23.840s
sys     0m0.000s
```

###To Do

There's still some duplication of work:
(1, 2) and (2, 1) are duplicates for boards of both 4 and 5 side length

```
Solving for 4x4 grid...
	Solved square at row 1, column 1: 1012520
		Even sides; square will be used four times
	Solved square at row 1, column 2: 740111
		Even sides; square will be used four times
	Solved square at row 2, column 1: 740111
		Even sides; square will be used four times
	Solved square at row 2, column 2: 514668
		Even sides; square will be used four times
A board with 4 sides has 12029640 possible solutions
```

```
Solving for 5x5 grid...
        Solved square at row 1, column 1: 6771537049
                Odd sides; square will be used four times
        Solved square at row 1, column 2: 4862635371
                Odd sides; square will be used four times
        Solved square at row 1, column 3: 4622951793
                Odd sides; square will be used four times
        Solved square at row 2, column 1: 4862635371
                Odd sides; square will be used four times
        Solved square at row 2, column 2: 3211115249
                Odd sides; square will be used four times
        Solved square at row 2, column 3: 3410890339
                Odd sides; square will be used four times
        Solved square at row 3, column 3: 4099322225
                Center square is only used once
```


