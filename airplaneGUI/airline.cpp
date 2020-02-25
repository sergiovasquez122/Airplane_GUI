#include "airline.h"

Airline::Airline(int i, string n, string alias, string iata, string apu, string callsign, string country):
    id(i),name(n),alias(alias),IATA(iata),APU(apu),Callsign(callsign),Country(country)
{

}

int Airline::getID()
{
    return id;
}

string Airline::getName()
{
    return name;
}
