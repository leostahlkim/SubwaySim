/*
 *  unit_tests.h
 *  Name: Leo Kim
 *  Date: 2/10/22
 *
 *  Purpose: Unit testing for the Metro Simulator.
 *
 */

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Station.h"
#include "Train.h"
#include "MetroSim.h"
#include <cassert>
#include <sstream>

/*
void Test_Test() {
    assert(1 == 1);
}

// TEST GROUP Passenger Print

void PassengerPrint_Test1() {
    Passenger test1(2, 5, 6);
    test1.print(std::cout);
    //std::cout << "testo";
    assert(true);
}

void PassengerPrint_Test2() {
    Passenger p(2, 5, 6);
    std::ostringstream res;
    p.print(res);
    assert(res.str() == "[2, 5->6]");
}

void PassengerPrint_Test3() {
    Passenger p(23, 59, 605);
    std::ostringstream res;
    p.print(res);
    assert(res.str() == "[23, 59->605]");
}

void PassengerPrint_Test4() {
    Passenger p(23, 59, 605);
    Passenger j(3, 12, 23);
    std::ostringstream res1;
    std::ostringstream res2;
    p.print(res1);
    assert(res1.str() == "[23, 59->605]");
    j.print(res2);
    assert(res2.str() == "[3, 12->23]");
} 

// TEST GROUP front

void Front_Test1() {
    PassengerQueue test;
    Passenger p(2, 3, 4);
    std::ostringstream res;
    test.enqueue(p);
    test.front().print(res);
    assert(res.str() == "[2, 3->4]");
}

void Front_Test2() {
    PassengerQueue test;
    Passenger p(2, 3, 4);
    Passenger a(3, 4, 5);
    Passenger b(4, 5, 6);
    Passenger c(5, 6, 7);
    std::ostringstream res;
    test.enqueue(p);
    test.enqueue(a);
    test.enqueue(b);
    test.enqueue(c);
    test.front().print(res);
    assert(res.str() == "[2, 3->4]");
}

void Front_Test3() {
    PassengerQueue test;
    Passenger a(3, 4, 5);
    test.enqueue(a);
    for (int i = 0; i < 100; i++) {
        Passenger temp(i, i, i);
        test.enqueue(temp);
    }
    std::ostringstream res;
    test.front().print(res);
    assert(res.str() == "[3, 4->5]");
}

// TEST group dequeue

void dequeue_Test1() {
    PassengerQueue test;
    Passenger p(23, 59, 605);
    Passenger j(3, 12, 23);
    std::ostringstream res;
    test.enqueue(p);
    test.enqueue(j);
    test.dequeue();
    test.front().print(res);
    //assert(res.str() == "[23, 59->605]");
    assert(res.str() == "[3, 12->23]");
}

void dequeue_Test2() {
    PassengerQueue test;
    for (int i = 0; i < 100; i++) {
        Passenger temp(i, i, i);
        test.enqueue(temp);
    }
    for (int i = 0; i < 99; i++) {
        test.dequeue();
    }
    std::ostringstream res;
    test.front().print(res);
    assert(res.str() == "[99, 99->99]");
}

// TEST GROUP size

void size_Test1() {
    PassengerQueue test;
    assert(test.size() == 0);
}

void size_Test2() {
    PassengerQueue test;
    Passenger p(23, 59, 605);
    Passenger j(3, 12, 23);
    test.enqueue(p);
    test.enqueue(j);
    assert(test.size() == 2);
}

void size_Test3() {
    PassengerQueue test;
    for (int i = 0; i < 100; i++) {
        Passenger temp(i, i, i);
        test.enqueue(temp);
    }
    assert(test.size() == 100);
}


// TEST GROUP print

void print_test1() {
    PassengerQueue test;
    std::ostringstream res;
    test.print(res);
    assert(res.str() == "");
}

void print_test2() {
    PassengerQueue test;
    std::ostringstream res;
    for (int i = 0; i < 3; i++) {
        Passenger p(i, i, i);
        test.enqueue(p);
    }
    test.print(res);
    test.print(std::cerr);
    assert(res.str() == "[0, 0->0][1, 1->1][2, 2->2]");
}

void print_test3() {
    PassengerQueue test;
    std::ostringstream res;
    std::ostringstream res1;
    for (int i = 0; i < 5; i++) {
        Passenger p(i, i, i);
        test.enqueue(p);
    }
    test.print(res);
    assert(res.str() == "[0, 0->0][1, 1->1][2, 2->2][3, 3->3][4, 4->4]");
    test.dequeue();
    test.print(res1);
    //std::cerr << res.str();
    assert(res1.str() == "[1, 1->1][2, 2->2][3, 3->3][4, 4->4]");
}


// TEST GROUP station constructor
void stationConstructor_Test1() {
    Station test;
}

void stationConstructor_Test2() {
    Station test;
    assert(test.name() == "");
    assert(test.number() == -1);
}


// TEST GROUP station name and num constructor
void stationNNConstructor_Test1() {
    Station test("beans", 7);
}

void stationNNConstructor_Test2() {
    Station test("beans", 9);
    assert(test.name() == "beans");
    assert(test.number() == 9);
}


// TEST GROUP station print
void stationPrint_Test1() {
    Station test("Beanz", 2);
    std::ostringstream out;
    test.print(out);
    assert(out.str() == "[2] Beanz {}");
}


// TEST GROUP station addPassenger
void addPassenger_Test1() {
    Station test("Big", 8);
    Passenger p(1, 2, 3);
    std::ostringstream out;
    test.addPassenger(p);
    test.print(out);
    assert(out.str() == "[8] Big {[1, 2->3]}");
}

void addPassenger_test2() {
    Station test("Burrito", 6);
    std::ostringstream res;
    for (int i = 0; i < 3; i++) {
        Passenger p(i, i, i);
        test.addPassenger(p);
    }
    test.print(res);
    //test.print(std::cerr);
    assert(res.str() == "[6] Burrito {[0, 0->0][1, 1->1][2, 2->2]}");
}

void addPassenger_test3() {
    Station test("Bowser", 9);
    std::ostringstream res;
    for (int i = 0; i < 3; i++) {
        Passenger p(i, i, i);
        test.addPassenger(p);
    }
    Passenger p(6, 9, 6);
    test.addPassenger(p);
    test.print(res);
    //test.print(std::cerr);
    assert(res.str() == "[9] Bowser {[0, 0->0][1, 1->1][2, 2->2][6, 9->6]}");
}


// TEST GROUP Station loadPassengers
void loadPassengers_test1() {
    Station test("Bowser", 8);
    Passenger p(1, 2, 3);
    test.addPassenger(p);
    test.loadPassengers();
}

void loadPassengers_test2() {
    Station test("Big", 8);
    Passenger p(1, 2, 3);
    test.addPassenger(p);
    test.loadPassengers();
    std::ostringstream out;
    test.print(out);
    assert(out.str() == "[8] Big {}");
}

void loadPassenger_test3() {
    Station test("Bean", 23);
    std::ostringstream res;
    for (int i = 0; i < 42; i++) {
        Passenger p(i, i, i);
        test.addPassenger(p);
    }
    test.loadPassengers();
    test.print(res);
    //test.print(std::cerr);
    assert(res.str() == "[23] Bean {}");
}


void loadPassenger_test4() {
    Station test("Burrito", 2);
    std::ostringstream res;
    std::ostringstream res1;
    for (int i = 0; i < 4; i++) {
        Passenger p(i, i, i);
        test.addPassenger(p);
    }
    Station test1("Burrito", 2);
    //test1.queue = test.loadPassengers();
    test.print(res);
    test1.print(res1);
    assert(res.str() == "[2] Burrito {}");
    assert(res1.str() == "[2] Burrito {[0, 0->0][1, 1->1][2, 2->2][3, 3->3]}");

}


// TEST GROUP train default constructor
void TrainDefCon_Test1() {
    Train t;
    Train b;
}

void TrainDefCon_Test2() {
    Train t;
    assert(t.location() == 0);
}

void TrainDefCon_Test3() {
    std::ostringstream res;
    Train t;
    t.print(res);
    assert(res.str() == "Passengers on the train: {}");
}

// TEST GROUP train numStations constructor
void TrainStCon_Test1() {
    Train t(12);
    Train b(0);
    Train k(30);
}

void TrainStCon_Test2() {
    Train t(12);
    assert(t.passengers.size() == 12);
    Train b(0);
    assert(b.passengers.size() == 0);
    Train k(30);
    assert(k.passengers.size() == 30);
}


void TrainStCon_Test3() {
    std::ostringstream res;
    Train t(12);
    t.print(res);
    assert(res.str() == "Passengers on the train: {}");
}

// TEST GROUP Train LoadPassengers
void loadPs_test1() {
    Train t;
    PassengerQueue q;
    t.loadPassengers(q);
}

void loadPs_test2() {
    Train t;
    PassengerQueue q;
    t.loadPassengers(q);
    std::ostringstream res;
    t.print(res);
    assert(res.str() == "Passengers on the train: {}");
}

void loadPs_test3() {
    Train t(7);
    PassengerQueue q;
    for (int i = 0; i < 5; i++) {
        Passenger p(i, i, i);
        q.enqueue(p);
    }
    
    t.loadPassengers(q);
    std::ostringstream res;
    t.print(res);
    //std::cout << res.str();
    assert(res.str() == "Passengers on the train: {[0, 0->0][1, 1->1][2, 2->2]
    [3, 3->3][4, 4->4]}");
}

void loadPs_test4() {
    Train t(7);
    PassengerQueue q;
    for (int i = 0; i < 20; i++) {
        Passenger p(i, i, 5);
        q.enqueue(p);
    }
    
    t.loadPassengers(q);
    std::ostringstream res;
    t.print(res);
    std::cout << res.str();
    assert(false);
}

void loadPs_test4() {
    Train t(23);
    for (int j = 0; j < 4; j++){
        PassengerQueue q;
        for (int i = 0; i < 3; i++) {
            Passenger p(i, i, j);
            q.enqueue(p);
        }
        t.loadPassengers(q);
    }
    std::ostringstream res;
    t.print(res);
    assert(res.str() == "Passengers on the train: {[0, 0->0][1, 1->0][2, 2->0]
    [0, 0->1][1, 1->1][2, 2->1][0, 0->2][1, 1->2][2, 2->2][0, 0->3][1, 1->3][2, 
    2->3]}" );
}

// TEST GROUP Train unload passengers
void unloadPs_Test1() {
    Train t(23);
    std:: ostringstream res;
    t.unloadPassengers(res);
    assert(res.str() == "");
}

void unloadPs_test2() {
    Train t(7);
    PassengerQueue q;
    for (int i = 0; i < 5; i++) {
        Passenger p(i, i, i);
        q.enqueue(p);
    }
    
    t.loadPassengers(q);
    std::ostringstream res;
    t.unloadPassengers(res);
    std::cout << res.str();
    assert(res.str() == "Passenger 0 left train at station PLACEHOLDER\n");
}

void unloadPs_test3() {
    Train t(7);
    PassengerQueue q;
    for (int i = 0; i < 5; i++) {
        Passenger p(i, i, 0);
        q.enqueue(p);
    }
    
    t.loadPassengers(q);
    std::ostringstream res;
    t.unloadPassengers(res);
    std::cout << res.str();
    assert(res.str() == "Passenger 0 left train at station 
    PLACEHOLDER\nPassenger 1 left train at station PLACEHOLDER\nPassenger 2 
    left train at station PLACEHOLDER\nPassenger 3 left train at station 
    PLACEHOLDER\nPassenger 4 left train at station PLACEHOLDER\n");
}

void unloadPs_test4() {
    Train t(7);
    PassengerQueue q;
    for (int i = 0; i < 5; i++) {
        Passenger p(i, i, i);
        Passenger r(i + 1, i, i);
        q.enqueue(p);
        q.enqueue(r);
    }
    //t.move();
    t.loadPassengers(q);
    std::ostringstream res;
    t.unloadPassengers(res);
    std::cout << res.str();
    //assert(res.str() == "Passenger 1 left train at station 
    //PLACEHOLDER\nPassenger 2 left train at station PLACEHOLDER\n");
}

// TEST GROUP Train move
void move_test1() {
    Train t(8);
    t.move();
}

void move_test2() {
    Train t(8);
    for (int i = 0; i < 100; i++) {
        t.move();
    }
    t.move();
}

// TEST GROUP Check Command line
void CCL_Test1() {
    MetroSim m;
    m.checkCommandLine(2);
}

void CCL_Test2() {
    MetroSim m;
    m.checkCommandLine(2);
}

void CCL_Test3() {
    MetroSim m;
    m.checkCommandLine(34);
}
*/