/*
 *  PassengerQueue.h
 *  Name: Leo Kim
 *  Date: 2/10/22
 *
 *  Purpose: Class implementation for the PassengerQueue class. A 
 *           PassengerQueue is a queue made up of Passenger variables 
 *           that can be acessed and altered by a variety of functions.
 *
 */
 
#include "PassengerQueue.h"

/*
 * name:      front
 * purpose:   return the front Passenger element in the PassengerQueue
 * arguments: none
 * returns:   the front Passenger element
 * effects:   none
 */
Passenger PassengerQueue::front() {
    return queue.front();
}

/*
 * name:      dequeue
 * purpose:   remove the first Passenger element in the PassengerQueue
 * arguments: none
 * returns:   none
 * effects:   removes the first Passenger element in the PassengerQueue
 */
void PassengerQueue::dequeue() {
    queue.pop_front();
}


/*
 * name:      enqueue
 * purpose:   add a Passenger element to the back of the PassengerQueue
 * arguments: Passenger element, passed by reference
 * returns:   none
 * effects:   adds a Passenger element to the back of the PassengerQueue
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    queue.push_back(passenger);
}

/*
 * name:      size
 * purpose:   determine the number of items in the PassengerQueue
 * arguments: none
 * returns:   number of elements currently stored in the PassengerQueue
 * effects:   none
 */
size_t PassengerQueue::size() {
    return queue.size();
}

/*
 * name:      print
 * purpose:   print all the items in the PassengerQueue to the given ostream
 * arguments: an ostream
 * returns:   none
 * effects:   none
 */
void PassengerQueue::print(std::ostream &output) {
    // Iterator to move through the PassengerQueue    
    std::list<Passenger>::iterator curr = queue.begin();
    // Move through and print each Passenger in the PassengerQueue
    for (size_t i = 0; i < size(); i++) {
        curr->print(output);
        std::advance(curr, 1);
    }
}