#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H
#include <graph.h>
#include <dijsktra.h>
class BreadthFirstSearch
{
public:
    BreadthFirstSearch(const Graph& G,int source);
    void bfs(const Graph &G, int s);
    bool hasPathTo(int vertex);
    deque<DirectedEdge> pathTo(int v);
private:
    int source;
    queue<DirectedEdge> theQueue;
    vector<DirectedEdge> edgeTo;
    deque<bool> marked;
};

#endif // BREADTHFIRSTSEARCH_H
