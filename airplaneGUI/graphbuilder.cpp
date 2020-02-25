#include "graphbuilder.h"

GraphBuilder::GraphBuilder(const string& airlineFile,const string& airportFile,const string& route)
{
    loadAirports(airportFile);
    loadGraph(route);
}

bool GraphBuilder::countLatLng(ltlng x)
{
    return latLngName.count(x);
}

void GraphBuilder::loadAirports(const string &airportFile)
{
    ifstream input(airportFile);
    string line;
    int ID,altitude,timezone;
    string name,city,country,iata,icao,tz;
    char dst;
    double latitude,longitude;
    while(getline(input,line))
    {
        stringstream ss(line);
        ss>>ID>>name>>city
                >>country>>iata>>icao
                >>latitude>>longitude
                >>altitude>>timezone
                >>dst>>tz;
        airports[ID] = Airport(ID,name,city,country
                               ,iata,icao,latitude,longitude
                               ,altitude,timezone,dst
                               ,tz);
        domesticAirportID[iata] = ID;
        ltlng temp(latitude,longitude);
        latLngName[temp] = iata;
    }
}

const Graph& GraphBuilder::getGraph() const
{
    return G;
}

const Airport &GraphBuilder::getAirport(int v)const
{
    return airports.at(v);
}

bool GraphBuilder::count(const string &line)
{
    return domesticAirportID.count(line);
}

void GraphBuilder::loadGraph(const string &graphFile)
{
    //Total number of vertices
    G.resize(9541);
    ifstream input(graphFile);
    string line;
    while(getline(input,line))
    {
        int source,target;
        double weight;
        string ID;
        stringstream ss(line);
        ss>>source>>ID>>target>>weight;
        G.addEdge(DirectedEdge(source,target,ID,weight));
    }
}

int GraphBuilder::retrieveID(const string &line)
{
    return domesticAirportID[line];
}

string GraphBuilder::latlngToString(ltlng x)
{
    return latLngName[x];
}

map<int, Airport> &GraphBuilder::getMap()
{
    return airports;
}
