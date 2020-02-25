#include "directededge.h"


DirectedEdge::DirectedEdge(int s, int t, string ID, double w)
{
    source = s;
    target = t;
    airplaneID = ID;
    weight = w;
}

string DirectedEdge::getID()
{
    return airplaneID;
}

int DirectedEdge::from()const
{
   return source;
}

int DirectedEdge::to()const
{
    return target;
}

double DirectedEdge::Weight()const
{
    return weight;
}

ostream& operator<<(ostream& out,const DirectedEdge& e)
{
    out<<e.source<<"->"<<e.target<<" ["<<e.weight<<"]";
    return out;
}
