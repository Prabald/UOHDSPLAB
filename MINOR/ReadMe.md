## A linked list is used to store a set of integer numbers. Implement the following operations on such sets.
- Union (A U B)
- Set Difference (A \ B)
- Symmetric Difference (A\B U B\A)

### Input/Output Specification:
n1 n2 e1 e2 ...

n1: number of elements of the set A

n2: number of elements of the set B

ei: elements of the set A followed by elements of the set B


Both n1 and n2 should >=0

Your program should read the elements of the set A and set B and should display A U B followed by A\B followed by Symmetric difference between A and B.

You can assume that there are no duplicate elements in the input set elements, and they are in ascending order. Output sets should also have no duplicates and they should be displayed in ascending order.

## # Sample Input/Output:
Input:4 4 2 4 6 7 1 2 3 4

Output: 1 2 3 4 6 7 6 7 1 3 6 7

Evaluation: 14 marks for correctness and 6 marks for efficiency, scalability, good coding practices and implementing data structure as ADT.