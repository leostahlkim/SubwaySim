/*
 *  Train.cpp
 *  Name: Leo Kim
 *  Date: 2/16/22
 *
 *  CS 15 Proj1 A Metro Simulator
 *
 *  Purpose: Class implementation for the Train class. A Train class
 *           contains a list of PassengerQueues with the passengers,
 *           on the train sorted by station and an int variable to 
 *           track the train's location. It also contains a
 *           variety of member functions.
 */

#include "Train.h"

/*
 * name:      Train default constructor
 * purpose:   initialize the Train private member variables
 * arguments: none
 * returns:   none
 * effects:   loc and totalStations to 0
 */
Train::Train() {
    // Initialize the location and number of stations
    loc = 0;
    totalStations = 0;
}

/*
 * name:      Train numStations constructor
 * purpose:   initialize the Train private member variables
 * arguments: none
 * returns:   none
 * effects:   loc to 0, and initialize empty list of stations
 *            and totalStations
 */
Train::Train(int numStations) {
    // Initialize the location and number of stations
    loc = 0;
    totalStations = numStations;
    // Create a corresponding PassengerQueue for each stations
    for (int i = 0; i < numStations; i++) {
        PassengerQueue p;
        passengers.push_back(p);
    }
}

/*
 * name:      location
 * purpose:   return the location of the train
 * arguments: none
 * returns:   int for the location of the train
 * effects:   none
 */
int Train::location() {
    return loc;
}

/*
 * name:      print
 * purpose:   print the Train in the correct format to cout
 * arguments: none
 * returns:   none
 * effects:   none
 */
void Train::print() {
    std::cout << "Passengers on the train: {";
    // Print every PassengerQueue on the train
    for (size_t i = 0; i < passengers.size(); i++) {
        passengers[i].print(std::cout);
    }
    std::cout << "}";
}

/*
 * name:      loadPassengers
 * purpose:   load passengers from a given PassengerQueue to their 
 *            corresponding spots on the Train
 * arguments: a PassengerQueue
 * returns:   none
 * effects:   populates the Passengers list with the passengers being loaded
 */
void Train::loadPassengers(PassengerQueue queue) {
    // Variable to store the size of the PassengerQueue being added
    size_t size = queue.size();
    // Add each Passenger to their correct PassengerQueues on the train
    for (size_t i = 0; i < size; i++) {
        Passenger p = queue.front();
        passengers[p.to].enqueue(p);
        queue.dequeue();
    }
}

/*
 * name:      unloadPassengers
 * purpose:   unload passengers from the train and output a record to the given 
 *            file
 * arguments: a fstream
 * returns:   none
 * effects:   clears the Passengers from the corresponding PassengerQueue and
 *            outputs them to the file
 */
void Train::unloadPassengers(std::ostream &file, std::string stationName) {
    // Variable to store the number of passengers being unloaded
    size_t numPassengers = passengers[loc].size();
    // Unload and record every passenger being unloaded
    for (size_t i = 0; i < numPassengers; i++) {
        // Take the front passenger in the PassengerQueue being unloaded
        Passenger p = passengers[loc].front();
        // Output the information to the given file
        file << "Passenger " << p.id << " left train at station ";
        file << stationName;
        file << std::endl;
        // Unload the passenger
        passengers[loc].dequeue();
    }
}

/*
 * name:      move
 * purpose:   move the train forward a station
 * arguments: none
 * returns:   none
 * effects:   loc increases by 1, if train is at the final station loc loops
 *            back to 0
 */
int Train::move() {
    // If the train is at the final station loop back to the first station
    if (loc == totalStations - 1) {
        loc = 0;
    } 
    // If not, move forward one station
    else {
        loc++;
    }

    return loc;
}