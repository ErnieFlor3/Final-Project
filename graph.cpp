#include "graph.hpp"
#include <algorithm>
using namespace std;

DSU::DSU(int n) {
    parent.resize(n);
    rank.resize(n,0);
    for (int i = 0; i < n; ++i) parent[i] = i;

}

int DSU::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

void DSU::unite(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr) return; // Already in the same set
    if (rank[xr] < rank[yr]) {
        parent[xr] = yr;
    } else if (rank[xr] > rank[yr]) {
        parent[yr] = xr;
    } else {
        parent[yr] = xr;
        rank[xr]++;
    }
}

Graph::Graph(int v) : vertices(v) {}
void Graph::addEdge(int u, int v, double w) {
    edges.push_back({u, v, w});
}

vector<Edge> Graph::findMST() {
    vector<Edge> mst;
    sort(edges.begin(), edges.end()); // Sort edges by weight
    DSU dsu(vertices);
    
    for (const auto& edge : edges) {
        if(dsu.find(edge.source) != dsu.find(edge.destination)) {
            mst.push_back(edge); // Include this edge in the MST
            dsu.unite(edge.source, edge.destination); // Union the sets
            if(mst.size() == vertices - 1) {
                break; // MST is complete
            }
        }
    }
    
    return mst;
}