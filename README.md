Boggle paths
--

This simply calculates the number of possible paths given a board with a
particular number of sides.  Compile with
```
% make
```
and run with
```
% ./boggle_paths [-h] <SIDES>
   SIDES defaults to 4 if not specified

   -h, --help		This help
```
###Todo
Don't recalculate cells unnecessarily. Since all corners will be the origin
of a particular number of paths, we should only calculate a corner once.
