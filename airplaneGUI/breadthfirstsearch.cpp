#include "breadthfirstsearch.h"
BreadthFirstSearch::BreadthFirstSearch(const Graph &G, int source)
{
    marked.resize(G.V(),false);
    edgeTo.resize(G.V());
    theQueue.push(source);
    marked[source] = true;
    while(!theQueue.empty()){
        DirectedEdge e = theQueue.front();
        theQueue.pop();
        bfs(G,e.from());
    }
}

void BreadthFirstSearch::bfs(const Graph &G, int s)
{
    for(DirectedEdge e: G.adj(s))
    {
        int w = e.to();
        if(!marked.at(w))
        {
            marked[w] = true;
            edgeTo[w] = e;
            theQueue.push(DirectedEdge(e.to()));
        }
    }
}


bool BreadthFirstSearch::hasPathTo(int vertex)
{
    return marked[vertex];
}

deque<DirectedEdge> BreadthFirstSearch::pathTo(int v)
{
    deque<DirectedEdge> path;
    if(hasPathTo(v))
    {

        for(DirectedEdge e(edgeTo[v].from());e.from()!= source;e=edgeTo[e.from()])
            path.push_front(e);
        path.push_front(DirectedEdge(-2,source));
    }
    return path;
}
