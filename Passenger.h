/*
 *  Passengers.h
 *  Name: Leo Kim
 *  Date: 2/10/22
 *
 *  CS 15 Proj1 A Metro Simulator
 *
 *  Purpose: Struct declaration for the Passenger struct. A Passenger is
 *           comprised of an id, an intial boarding station, and a final
 *           destination station. The passenger struct also contains a few
 *           member functions.
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);
};

#endif
