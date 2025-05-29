#include <iostream>
#include "graph.hpp"
#include <memory>
using namespace std;

int main() {
    auto graph = make_unique<Graph>(4); // Create a graph with 4 vertices
    graph->addEdge(0, 1, 1.0);
    graph->addEdge(0, 2, 3.0);
    graph->addEdge(0, 3, 4.0);
    graph->addEdge(1, 2, 2.0);
    graph->addEdge(2, 3, 5.0);

    auto mst = graph->findMST(); // Find the Minimum Spanning Tree
    double totalWeight = 0.0;

    cout << "MST Edges:\n";
    for(const auto& e : mst) {
        cout << e.source << " -- " << e.destination << " (Weight: " << e.weight << ")\n";
        totalWeight += e.weight;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
    return 0;
}