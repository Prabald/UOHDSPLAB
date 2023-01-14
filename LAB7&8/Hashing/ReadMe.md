# Hashing
 Due date: Saturday, 10 December 2022, 11:59 PM
 Maximum number of files: 1
Type of work:  Individual work
### The aim of this exercise is to remove duplicate strings from the attached file (emailList.txt) using a hash table.
You can assume that the size of the final set of strings is less than 100.

Implement a hash table using open addressing to resolve collisions. Internally you should use a fixed sized array as a hash table to store strings.
When there are collisions use open addressing scheme to resolve the collisions.
To get hash code, you need to convert a string to an integer;
Choose a suitable way to do this and when collision occurs, compare the strings to detect duplicates.

The input file name and the output file name will be provided as command line arguments.
Your program should read strings from input file and output (strings after removing duplicates) should be written to the output file.

https://scislearn2.uohyd.ac.in/moodle/pluginfile.php/11450/mod_vpl/intro/emailList.txt