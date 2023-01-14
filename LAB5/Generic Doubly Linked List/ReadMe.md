# Generic Doubly Linked List
 Due date: Saturday, 10 December 2022, 11:59 PM
 Requested files: DoublyList.c ( Download)
Type of work:  Individual work
### Implement a generic doubly linked list in C with the following functions:
- createList()
- insertFirst()
- insertLast()
- insertAtIndex()
- removeFirst()
- removeLast()
- removeAtIndex()

Now write a menu driven C test main() function to demonstrate the working of doubly linked list.
The following operations to be applied iteratively to the doubly linked list of integers.

1 e - insert element e at the head of the list.

2 e - insert element e at the tail of the list.

3 i e - insert element e at the index i. Index starts from 0. If linked list currently has n elements then 0 to n are the valid indices for i.

4 - delete element from head of the list and display the deleted element.

5 - delete element from tail of the list and display the deleted element.

6 i - delete element at index i. If linked list currently has n elements then 0 to n-1 are the valid indices for i.

7 - display the list from head to tail.

-1 - exit

 At any iteration if input is invalid display "INVALID INPUT" and stop the program.

At any time remove function is called on an empty list display "LE"

### Sample Input/Output:

input= 1 60 1 70 2 50 2 40 3 1 20 4 5 5 6 0 1 10 1 90 2 100 2 80 3 0 30 7 -1

output=70 40 50 20 30 90 10 60 100 80