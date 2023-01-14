# Post-Fix Expression Evaluation
 Due date: Saturday, 10 December 2022, 11:59 PM
 Requested files: PostFix.c ( Download)
Type of work:  Individual work
### Implement an efficient and scalable stack using arrays.
The stack should have the following features:
1. Initial size of the stack is 4 element
2. Stack in meant to hold integer values
3. Stack has the following functions:
    -createStack() - creates a stack dynamically
    -push(S, e) - push element e onto the stack
    -pop(S) - delete element from the stack using LIFO mechanism
    -getTop(S) - returns the top element of the stack
4. If push(S, e) is called when stack is full, stack size to be doubled and memory to be reallocated.
5. If there is division by zero display "DIVBYZERO"

Now write a test function main() which evaluates a post-fix expression. Only binary operators +, -, * and / (integer division) to be used in the post-fix expression.

Sample Input: 10 20 30 + +

Output: 60

Input: 10 20 30 / -

Output: 10
