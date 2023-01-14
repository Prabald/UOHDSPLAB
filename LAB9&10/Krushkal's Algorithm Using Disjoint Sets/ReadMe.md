# Krushkal's Algorithm Using Disjoint Sets
 Due date: Saturday, 10 December 2022, 11:59 PM
 Maximum number of files: 1
Type of work:  Individual work

A disjoint -set data structure maintains a collection of disjoint sets. Each set is identified by a representative.

The disjoint-set data structure has the following operations.
- MAKE-SET(x) : Create a set with single tone element x. x will be the representative of the set.
- UNION(x,y): Unite the sets containing x and y, say S_x and S_y into a new set S_x U S_y. This operation destroys S_x and S_y and adds the union.
            Representative of S_x (or S_y) will be the representative of the union.
- FIND-SET(x): Returns the representative of the set S_x.

Implement Disjoint Sets data structure. You should implement the data structure as a disjoint-set forests along with the heuristics union by rank and path compression.

Using the Disjoint-Set data structure implement Krushkal's Algorithm for Minimum Spanning Tree for a weighted undirected graph.

The graph will be passed through a text file as command line argument. You need to display the edges of the MST along with total weight.
For example graph will be in the following format (for K_4, complete graph on 4 vertices)

4 6

1 2 5

1 3 10

1 4 2

2 3 20

2 4 15

3 4 6

Edges of the MST  {(1, 2), (1, 4), (3, 4)}, Total Weight: 13

Reference: Chapter-21. Data Structures for Disjoint Sets, (Introduction to Algorithms, CLRS)