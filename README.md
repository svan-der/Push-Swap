Push_Swap
Efficiently sorting two stacks of integers with least amount of commands possible

How to build:
1) Git clone repository
2) Compile project with command: Make or make re


1. Checker
This program takes integers as arguments, reads instructions from the standard input and sorts the data.
Checker returns OK when integers are sorted. Otherwise it will display, KO.

Usage:
1) run checker with a (random) list of integers
2)then checker waits for instructions to sort the list 1 command per line: sa, sb, ss, pb, pa, rb, ra, rrr
$./checker 1 2 3 4 5
[enter] $(pb)

2. Push_swap
This program takes integers as arguments and calculates and displays the smallest list of instructions to sort this list.

Usage:
1) run push_swap with a (random) list of integers
./push_swap 540 23 5 9 10 32 54 42
