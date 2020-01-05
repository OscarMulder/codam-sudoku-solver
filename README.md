# Codam - Piscine C Rush01 - Sudoku Solver
This sudoku solver isn't the one I wrote during my own piscine. I wrote this one
to refresh my mind in preparation of evaluating pisciners on their solvers, and
also to see what I would do differently after almost a year of coding in C.

I gave it a small optimization to make sure it is really fast, while still
solving the sudoku twice (to check if it has only one solution).

### Compiling
```
gcc -Wall -Wextra -Werror -o sudoku *.c
```

### Running
From the subject
```
./sudoku "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
```
From wikipedia, goes against recursive backtracking algorith, I optimized the
slowness away by recognizing if it should start solving from the front or the
back. The second one is the same but reversed.
```
./sudoku "........." ".....3.85" "..1.2...." "...5.7..." "..4...1.." ".9......." "5......73" "..2.1...." "....4...9"
./sudoku "9...4...." "....1.2.." "37......5" ".......9." "..1...4.." "...7.5..." "....2.1.." "58.3....." "........."
```
Most difficult sudoku for humans (according to some website)
``` 
./sudoku "8........" "..36....." ".7..9.2.." ".5...7..." "....457.." "...1...3." "..1....68" "..85...1." ".9....4.."
```

### Notes
Since the grid is a one dimensional array, it helps to have a little reference
to the indexes.
```
00 01 02	03 04 05	06 07 08
09 10 11	12 13 14	15 16 17
18 19 20	21 22 23	24 25 26

27 28 29	30 31 32	33 34 35
36 37 38	39 40 41	42 43 44
45 46 47	48 49 50	51 52 53

54 55 56	57 58 59	60 61 62
63 64 65	66 67 68	69 70 71
72 73 74	75 76 77	78 79 80
```