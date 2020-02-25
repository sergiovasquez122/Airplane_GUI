#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <airline.h>
class Airport
{
public:
    Airport(int id = -2,string name= string(),
             string city = string(),
             string country = string(),string iata = string(),string icao = string(),
            double latitude = double(),
             double longitude = double(),int altitude = int(),int timezone = int(),
             char dst = 'A',string tz = string());
    int getID() const;
    string getName() const;
    string getCity();
    string getCountry();
    string getIata()const;
    double lat()const;
    double lng()const;
private:
    int id;
    string name;
    string city;
    string country;
    string iata;
    string icao;
    double latitude;
    double longitude;
    int altitude;
    int timezone;
    char dst;
    string tz;
};

#endif // AIRPLANE_H
