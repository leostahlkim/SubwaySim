/*
 *  Station.cpp
 *  Name: Leo Kim
 *  Date: 2/15/22
 *
 *  CS 15 Proj1 A Metro Simulator
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
    //Passenger p(0, 0, 0);
    //queue.enqueue(p);
    //queue.dequeue();
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
 * purpose:   print the Station in the correct format to the given ostream
 * arguments: an ostream
 * returns:   none
 * effects:   none
 
void Station::print(std::ostream &output) {
    output << "[" << stationNum << "] " << stationName << " {";
    queue.print(output);
    output << "}";
}
*/

/*
 * name:      print
 * purpose:   print the Station in the correct format to cout
 * arguments: none
 * returns:   none
 * effects:   none
 */
void Station::print() {
    std::cout << "[" << stationNum << "] " << stationName << " {";
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
    PassengerQueue temp;
    size_t size = queue.size();

    for (size_t i = 0; i < size; i++) {
        temp.enqueue(queue.front());
        queue.dequeue();
    }
    return temp;
}