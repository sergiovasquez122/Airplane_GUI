#include "bellmanford.h"
BellmanFord::BellmanFord(const Graph &G, int source)
{
    disto.resize(G.V(),inf);
    predecessor.resize(G.V(),DirectedEdge(INT8_MIN,-INT8_MIN,"",0));
    solutionExists = true;
    disto[source] = 0;
    BF(G);
}

void BellmanFord::BF(const Graph &G)
{
    //Continously update the edges
    for(int pass = 0;pass<G.V();++pass)
        for(int v = 0;v<G.V();++v)
            relax(G,v);
    //If there are negative cycles report it
    solutionExists = negativeCycle(G);
}

bool BellmanFord::negativeCycle(const Graph& G)
{
    for(int v = 0;v<G.V();++v)
        for(DirectedEdge e : G.adj(v))
        {
            int w  = e.to();
            if(disto[w]>disto[v]+e.Weight())
            {
                return false;
            }
        }
    return true;
}

double BellmanFord::distTo(int v)
{
    return disto[v];
}

void BellmanFord::relax(const Graph &G, int current)
{
    for(DirectedEdge e : G.adj(current))
    {
        int w  = e.to();
        if(disto[w]>disto[current]+e.Weight())
        {
            disto[w]  = disto[current] + e.Weight();
            predecessor[w] = e;
        }
    }
}

deque<DirectedEdge> BellmanFord::pathTo(int v)
{
    deque<DirectedEdge> path;
    for(DirectedEdge e = predecessor[v];e.from()!=INT8_MIN;e = predecessor[e.from()])
        path.push_front(e);
    return path;
}

bool BellmanFord::hasSolution()
{
    return solutionExists;
}

