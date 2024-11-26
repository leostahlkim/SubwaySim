/*
 *  Train.h
 *  Name: Leo Kim
 *  Date: 2/16/22
 *
 *
 *  Purpose: Class declaration for the Train class. A Train class
 *           contains a list of PassengerQueues with the passengers,
 *           on the train sorted by station and an int variable to 
 *           track the train's location. It also contains a
 *           variety of member functions.
 */

#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <vector>

#include "PassengerQueue.h"

class Train {
public:
    Train();
    Train(int numStations);

    // Functions that give/output information about the Train state
    int location();
    void print();
    // Functions that alter the Train state
    void loadPassengers(PassengerQueue queue);
    void unloadPassengers(std::ostream &file, std::string stationName);
    int move();
private:
    // Private member variables
    std::vector<PassengerQueue> passengers;
    int loc;
    int totalStations;
};

#endif