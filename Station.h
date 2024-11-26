/*
 *  Station.h
 *  Name: Leo Kim
 *  Date: 2/15/22
 *
 *
 *  Purpose: Class declaration for the Station class. A Station class
 *           contains a PassengerQueue of passengers at the station,
 *           a station number and a station name. It also contains a
 *           variety of member functions.
 */


#ifndef STATION_H
#define STATION_H

#include <iostream>

#include "PassengerQueue.h"

class Station {
public:
    Station();
    Station(std::string name, int num);

    // Functions that give/output information about the Station state
    std::string name();
    int number();
    void print();
    // Functions that alter the Station state
    void addPassenger(const Passenger &pass);
    PassengerQueue loadPassengers();
private:
    // Private member variables
    PassengerQueue queue;
    std::string stationName;
    int stationNum;
};

#endif