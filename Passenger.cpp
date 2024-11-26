/*
 *  Passenger.cpp
 *  Name: Leo Kim
 *  Date: 2/10/2022
 *
 *  Purpose: Implementation for the Passenger struct. A Passenger is
 *           comprised of an id, an intial boarding station, and a final
 *           destination station. The passenger struct also contains a few
 *           member functions.
 */

#include "Passenger.h"

/*
 * name:      print
 * purpose:   print a Passenger struct to a given output stream
 * arguments: output stream
 * returns:   none
 * effects:   none
 */
void Passenger::print(std::ostream &output) {
        output << "[" << id << ", " << from << "->" << to << "]";
}
