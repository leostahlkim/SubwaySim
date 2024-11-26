/*
 *  Station.cpp
 *  Name: Leo Kim
 *  Date: 2/15/22
 *
 *  Purpose: Class implementation for the Station class. A Station class
 *           contains a PassengerQueue of passengers at the station,
 *           a station number and a station name. It also contains a
 *           variety of member functions.
 */

#include "Station.h"

/*
 * name:      Station default constructor
 * purpose:   initialize the Station private member variables
 * arguments: none
 * returns:   none
 * effects:   stationName to "" and stationNum to -1
 */
Station::Station() {
    stationName = "";
    stationNum = -1;
}

/*
 * name:      Station name and number constructor
 * purpose:   initialize the Station private member variables
 * arguments: none
 * returns:   none
 * effects:   stationName and stationNum to input values
 */
Station::Station(std::string name, int num) {
    stationName = name;
    stationNum = num;
}

/*
 * name:      name
 * purpose:   return the name of the station
 * arguments: none
 * returns:   the name of the station
 * effects:   none
 */
std::string Station::name() {
    return stationName;
}

/*
 * name:      number
 * purpose:   return the number of the station
 * arguments: none
 * returns:   the number of the station
 * effects:   none
 */
int Station::number() {
    return stationNum;
}

/*
 * name:      print
 * purpose:   print the Station in the correct format to cout
 * arguments: none
 * returns:   none
 * effects:   none
 */
void Station::print() {
    // Print the station name and number in the correct format
    std::cout << "[" << stationNum << "] " << stationName << " {";
    // Print the Station's PassengerQueue
    queue.print(std::cout);
    std::cout << "}";
}

/*
 * name:      addPassenger
 * purpose:   add a Passenger to the Station's PassengerQueue
 * arguments: a Passenger variable
 * returns:   none
 * effects:   adds a Passenger to the Station's PassengerQueue
 */
void Station::addPassenger(const Passenger &pass) {
    queue.enqueue(pass);
}

/*
 * name:      loadPassengers
 * purpose:   clear the Station Passenger queue and return it for addition
 *            to the train
 * arguments: none
 * returns:   The PassengerQueue that was at the station
 * effects:   clears the Station PassengerQueue
 */
PassengerQueue Station::loadPassengers() {
    // Variable to store the PassengerQueue being unloaded
    PassengerQueue temp;
    // Variable to store the size of the PassengerQueue being unloaded
    size_t size = queue.size();
    // For each passenger being unloaded, remove it from the Station's
    // PassengerQueue and store it in the PassengerQueue of unloaded
    // Passengers
    for (size_t i = 0; i < size; i++) {
        temp.enqueue(queue.front());
        queue.dequeue();
    }
    // Return the PassengerQueue that was just unloaded
    return temp;
}