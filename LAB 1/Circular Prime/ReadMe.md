# Circular Prime
 Due date: Saturday, 10 December 2022, 11:59 PM
 Requested files: CircularPrime.c ( Download)
Type of work:  Individual work
## Write a modularized C Program to check if a given positive integer number is a circular prime or not.
## A number is circular prime if the number and all its cyclic permutations are prime.

For example:
The number 3779 is circular prime because all the cyclic permutations
3779, 9377, 7937, 7793 are prime numbers.

Where as the number 3877 is not circular prime because one of its cyclic permutation 7738 is not a prime number.

##Input/Output Specification:
 - Any input <= 0 to be treated as invalid input. Any input > 0 to be treated as valid input
 - If the number <= 0, your program should print -1
 - If the number is circular prime, your program should print 1
 - If the number is not circular prime, your program should print 0

Sample Input/Output:
Input:
 -100
 Output:
 -1

Input:
 0
 Output:
 -1

Input:
 3779
 Output:
 1

 Input:
 3877
 Output:
 0