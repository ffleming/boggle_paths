be2a28e (Initial commit)
--
```
1 sides:
Solving for 1x1 grid...
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

2 sides:
Solving for 2x2 grid...
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

3 sides:
Solving for 3x3 grid...
A board with 3 sides has 10305 possible solutions
0.01user 0.00system 0:00.01elapsed 83%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

4 sides:
Solving for 4x4 grid...
A board with 4 sides has 12029640 possible solutions
10.10user 0.00system 0:10.10elapsed 99%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps
```

2995195 (Remove duplicate work - slice board into quadrants)
--
```
1 sides:
Solving for 1x1 grid...
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

2 sides:
Solving for 2x2 grid...
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

3 sides:
Solving for 3x3 grid...
A board with 3 sides has 10305 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

4 sides:
Solving for 4x4 grid...
A board with 4 sides has 12029640 possible solutions
2.52user 0.00system 0:02.52elapsed 99%CPU (0avgtext+0avgdata 1112maxresident)k
0inputs+0outputs (0major+75minor)pagefaults 0swaps
```

963833c (Don't copy visited array - just set/unset relevant values)
--
```
1 sides:
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1332maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

2 sides:
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1224maxresident)k
0inputs+0outputs (0major+76minor)pagefaults 0swaps

3 sides:
A board with 3 sides has 10305 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

4 sides:
A board with 4 sides has 12029640 possible solutions
1.04user 0.00system 0:01.04elapsed 99%CPU (0avgtext+0avgdata 1412maxresident)k
0inputs+0outputs (0major+80minor)pagefaults 0swaps
```

0507340 (Use offsets for neighbor selection)
--
```
1 sides:
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+77minor)pagefaults 0swaps

2 sides:
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

3 sides:
A board with 3 sides has 10305 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+78minor)pagefaults 0swaps

4 sides:
A board with 4 sides has 12029640 possible solutions
0.60user 0.00system 0:00.60elapsed 98%CPU (0avgtext+0avgdata 1244maxresident)k
0inputs+0outputs (0major+79minor)pagefaults 0swaps
```

f009981 (Add single cell)
--
```
1 sides:
A board with 1 sides has 1 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
0inputs+0outputs (0major+81minor)pagefaults 0swaps

2 sides:
A board with 2 sides has 64 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1248maxresident)k
0inputs+0outputs (0major+79minor)pagefaults 0swaps

3 sides:
A board with 3 sides has 10305 possible solutions
0.00user 0.00system 0:00.00elapsed 0%CPU (0avgtext+0avgdata 1412maxresident)k
0inputs+0outputs (0major+83minor)pagefaults 0swaps

4 sides:
A board with 4 sides has 12029640 possible solutions
0.73user 0.00system 0:00.73elapsed 98%CPU (0avgtext+0avgdata 1288maxresident)k
0inputs+0outputs (0major+80minor)pagefaults 0swaps
```
