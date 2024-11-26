/*
 *  PassengerQueue.h
 *  Name: Leo Kim
 *  Date: 2/10/22
 *
 *  Purpose: Class declaration for the PassengerQueue class. A PassengerQueue
 *           is a queue made up of Passenger variables that can be acessed
 *           and altered by a variety of functions.
 */


#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include <iostream>
//#include <vector>
#include <list>
#include <iterator>

#include "Passenger.h"

class PassengerQueue {
public:
    // Functions that give/output information about the PassengerQueue state
    Passenger front();
    size_t size();
    void print(std::ostream &output);
    // Functions that alter the PassengerQueue state
    void dequeue();
    void enqueue(const Passenger &passenger);
private:
    std::list<Passenger> queue;
};

#endif
