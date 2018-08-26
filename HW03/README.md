# Josephus Problem

Learning Goals 
==============

This assignment asks you to solve the Josephus problem using an array. 


Problem Description
===================

History (based on Wikipedia): Flavius Josephus and 40 soldiers were
trapped in a cave. They chose suicide over capture, and decided the
order is determined by the following method: they form a circle and
set an integer k greater than one.  Then, the group starts with 1, 2,
... The person that counts k is eliminated.  The process continues
until all are eliminated.  The question is where Josephus should stand
so that he is the last remaining person.

More precisely, this is how the method works: There are n elements in
a array. The elements are counted as 1, 2, 3, ... When the value k is
counted, this element is removed in future counting and the next
element starts as 1 again. When reaching the end of the array, the
counting *wrap around* to the beginning of the array (skipping the
elements that have already been eliminated).  Please notice that in C
arrays, indexes *always* start at zero but in the Josephus problem
counting starts at one. Both n and k have to be greater than one.  It
is possible that k is greater than n.

The following is an example when the array has 6 elements and k is 3.
The eliminated elements in each round are mared by `X`.  The elements eliminated
earlier are marked by  `Y`.

Please notice that there are different definitions of this
problem. Your solution must follow the definition here.


array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | X | 1 | 2 | X 


array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | Y | X | 1 | Y 


array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 2 | X | Y | Y | 1 | Y 

array index | 0 | 1 | 2 | 3 | 4 | 5
------------|---|---|---|---|---|---
count       | 2 | Y | Y | Y | X | Y

The element of index 0 is left.

This is another example. The array has 6 elements and k is 4.

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 1 | 2 | 3 | X | 1 | 2 

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | 3 | X | 1 | Y | 2 | 3 

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | X | Y | 1 | Y | 2 | 3

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | Y | Y | X | Y | 1 | 2

array index | 0 | 1 | 2 | 3 | 4 | 5 
------------|---|---|---|---|---|---
count       | Y | Y | Y | Y | 3 | X

The element of index 4 is left.

This is the third example. The array has 25 elements and k is 7.

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 1 | 2 | 3 | 4 | 5 | 6 | X | 1 | 2 | 3 | 4  | 5  | 6  | X  |  1 | 2  |  3 |  4 | 5  | 6  | X  |  1 | 2  |  3 |  4 


array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 5 | 6 | X | 1 | 2 | 3 | Y | 4 | 5 | 6 | Y  |  1 | 2  | Y  |  3 | 4  | 5  | 6  |  X |  1 | Y  |  2 | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | X | Y | 1 | 2 | 3 | Y | 4 | 5 | 6 | Y  | X  | 1  | Y  | 2  | 3  | 4  | 5  |  Y |  6 | Y  |  X | 1  | 2  |  3

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 4 | Y | Y | 5 | 6 | X | Y | 1 | 2 | 3 | Y  | Y  | 4  | Y  | 5  | 6  | X  | 1  | Y  |  2 | Y  |  Y | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | Y | Y | X | 1 | Y | Y | 2 | 3 | 4 | Y  | Y  | 5  | Y  | 6  | X  | Y  | 1  | Y  |  2 | Y  |  Y | 3  | 4  |  5

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 6 | Y | Y | Y | X | Y | Y | 1 | 2 | 3 | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | X  | Y  |  Y | 1  | 2  |  3

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | 4 | Y | Y | Y | Y | Y | Y | 5 | 6 | X | Y  | Y  | 1  | Y  | 2  | Y  | Y  | 3  | Y  | Y  | Y  |  Y | 4  | 5  |  6

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | X | Y | Y | Y | Y | Y | Y | 1 | 2 | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | 5  | Y  | Y  | Y  |  Y | 6  | X  |  1

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 2 | 3 | Y | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | Y  | Y  |  Y | X  | Y  |  1

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 2 | 3 | Y | Y  | Y  | 4  | Y  | 5  | Y  | Y  | 6  | Y  | Y  | Y  |  Y | Y  | Y  |  X

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 1 | 2 | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | 5  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 6 | X | Y | Y  | Y  | 1  | Y  | 2  | Y  | Y  | 3  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 4 | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | X  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 1 | Y | Y | Y  | Y  | 2  | Y  | 3  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | 4 | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | X | Y | Y | Y  | Y  | 1  | Y  | 2  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | 3  | Y  | 4  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | 5  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

array index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 
------------|---|---|---|---|---|---|---|---|---|---|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----
count       | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y | Y  | Y  | X  | Y  | 6  | Y  | Y  | Y  | Y  | Y  | Y  |  Y | Y  | Y  |  Y

The element of index 14 is left.

The table uses `X` and `Y` for clarity.  Your program should use only `X`.

What Do You Need to Do
======================

Write the `josephus` function and print the index of the eliminated elements.

In the first example, the output is
```
2
5
3
1
4
0
```

In the second example, the output is

```
3
1
0
2
5
4
```

In the third example, the output is

```
6
13
20
2
10
18
1
11
21
5
16
3
15
4
19
9
0
23
22
24
8
17
7
12
14
```

Submission
==========

```
zip josephus.zip josephus.c
```

Upload josephus.zip to Blackboard.

Additional Reading
==================

A mathematical question is to determine which element is left
*without* counting 1, 2, ...  If you are interested in this topic,
please read the book Concrete Mathematics.  
