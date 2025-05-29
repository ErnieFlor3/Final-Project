#ifndef GRAHP_HPP
#define GRAHP_HPP
using namespace std;
#include <iostream>
#include <vector>

struct Edge {
    int source, destination;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n);
    int find(int x);
    void unite(int x, int y);
    
};

class Graph {
private: 
    int vertices;
    vector<Edge> edges;
public:
    Graph(int v);
    void addEdge( int u, int v, double w);
    vector<Edge> findMST();
};

#endif

