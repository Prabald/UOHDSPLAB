# Sparse Matrix Addition
 Due date: Saturday, 10 December 2022, 11:59 PM
 Requested files: SparseMatrixAdd.c ( Download)
Type of work:  Individual work
### Write a C program to perform addition of two sparse matrices.

If we use two dimensional array to store a sparse matrix there will be wastage of memory.
For a sparse matrix most of the elements are zeros. Instead of two dimensional array
we can use linked list to store <row, column, value> triplets of the non-zero elements of the matrix
in a node of the linked list. Such a linked list will represent a sparse matrix.

Input/Output Specification:

-First two numbers will be dimensions (m X n) of the matrix
-Third (n1) and fourth (n2) number will be number of non-zero elements of the sparse matrices A and B respectively. note that n1 and n2 can not be more than mxn.
-From the fifth number, you will get row, column and value triplets.
-Matrix dimensions should be non-zero positive integers
-number of non-zero elements of the matrix should be non-negative (including zero) integer
-row and column  index starts from zero
-For an m X n matrix valid row indices are 0 - m-1 and valid column indices are 0 - n-1
-If input is invalid display "INVALID INPUT"
-If input is valid, compute the addition two sparse matrices and display in traditional matrix format

Note: You are not allowed to create any two dimentional array in solving this problem.

Example

Matrix A:

0 0 0

0 10 0

1 0 0

Matrix B:

-1 0 0

11 0 0

0 0 20

Input/Output for the above example:

Input:

3 3

2 3

1 1 10

2 0 1

0 0 -1

1 0 11

2 2 20

Output:

-1 0 0

11 10 0

1 0 20
