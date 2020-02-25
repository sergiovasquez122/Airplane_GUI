#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "graph.h"
#include "dijsktra.h"
class BellmanFord
{
public:
    BellmanFord(const Graph& G,int source);
    deque<DirectedEdge> pathTo(int i);
        double distTo(int v);
    bool hasSolution();
private:
    bool negativeCycle(const Graph& G);
    void BF(const Graph& G);
    void relax(const Graph& G,int v);
    bool solutionExists;
    vector<double> disto;
    vector<DirectedEdge> predecessor;
    priority_queue<vertex> pq;
    const double inf = numeric_limits<double>::infinity();
};
#endif // BELLMANFORD_H
