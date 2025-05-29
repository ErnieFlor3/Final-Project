# Final-Project
# MST Implementation- Using Kruskal's Algorithm

# Ernesto Flores

# This final project implements a weighted, undirected graph and computes its Minimum Spanning Tree (MST) using Kruskal's Algorithm. This includes:
 A custom graph and edge structures. Disjoint Set Union (DSU) for the cycle detection. A test suite using Catch2 (as explained in the instructions)


## Build and run Instructions
# to build and run main program: 
    g++ -std=c++17 graph.cpp main.cpp -o run
    ./run

## For building and run Tests
    g++ -std=c++17 graph.cpp tests.cpp -o test
    ./test

## Sample Input/Output
# Graph
    4 vertices
    5 edges: (0-1, 1), (0-2. 3), (0-3, 4), (1-2, 2), (2-3, 5)
# output
MST Edges:
0 -- 1 (Weight: 1)
1 -- 2 (Weight: 2)
0 -- 3 (Weight: 4)
Total Weight of MST: 7
(directly from output in terminal)
# 