#ifndef DIJSKTRA_H
#define DIJSKTRA_H
#include "directededge.h"
#include "graph.h"
#include "airline.h"
#include "airplane.h"
#include <queue>
#include <vertex.h>
#include <limits>
class Dijsktra
{
public:
    Dijsktra(const Graph& G,int source);
    double distTo(int v);
    bool hasPathTo(int v);
    deque<DirectedEdge> path(int v);
    void relax(const Graph&,int current);
private:
    vector<double> disto;
    vector<DirectedEdge> predecessor;
    priority_queue<vertex> pq;
    const double infinite = numeric_limits<double>::infinity();
};

#endif // DIJSKTRA_H
