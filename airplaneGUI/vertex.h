#ifndef VERTEX_H
#define VERTEX_H
#include "airplane.h"
struct vertex
{
public:
    vertex(int index = int(),double weight= int()):index(index),weight(weight){}
    int index;
    double weight;

    friend
    bool operator<(const vertex& x,const vertex& y)
    {
        return x.weight>y.weight;
    }

    friend
    ostream& operator<<(ostream& out,const vertex& v)
    {
        out<<v.index<<" ["<<v.weight<<"]";
        return out;
    }
};

#endif // VERTEX_H
