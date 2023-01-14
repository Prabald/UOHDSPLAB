# Saddle Point
 Due date: Saturday, 10 December 2022, 11:59 PM
 Requested files: SaddlePoint.c ( Download)
Type of work:  Individual work
## An m X n matrix is said to have a saddle point if there is an element a[i][j] of the array such that a[i][j] is the smallest value in ith row and largest value in jth column. Write a modularized C program that displays the location of the saddle point. If the matrix has more than one saddle point display the first location of the saddle point starting from row 0 and column 0 (elements are visited from left to right and row by row). Remember array index starts from 0.

## Note: Array elements can be both positive or negative integers.

For example, for the following 3 X 3 matrix element a[2][0] (7) is a saddle point

1 2 3

4 5 6

7 8 9

Where as the following 3 X 4 matrix does not have a saddle point.
1 2 3 4

5 6 7 8

10 11 12 6

The following matrix has more than one saddle points (a[2][0] and a[2][1])

1 2

3 4

5 5

## Input/Output Specification:
- Your program should read the dimension of the matrix and followed by the elements of the matrix.
- Display -1 if the matrix does not have a saddle point.
- Display the row and column indices of the first saddle point.
- matrix dimensions should be > 0, otherwise display -2
## Sample Input/Output:
### Input:

3 3

1 2 3

4 5 6

7 8 9

### Output

2 0

### Input:

3 3

1 2 3

4 5 6

9 8 5

### Output:

-1

### Input:

1 3

3 4 1

### Output:

0 2

### Input:

3 2

1 2

3 4

5 5

### Output:

2 0

### Input:

0 4

### Output:

-2
