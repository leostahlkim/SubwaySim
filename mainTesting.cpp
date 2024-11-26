/*
 *  mainTesting.cpp
 *  Name: Leo Kim
 *  Date: 2/17/22
 *
 *  CS 15 Proj1 A Metro Simulator
 *
 *  Purpose: Testing for the MetroSim class
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include <cassert>

using namespace std;

int main(int argc, char *argv[])
//int main()
{
    //MetroSim m(argc, argv);
    MetroSim m(argc, argv);

    m.runSim();
    //for (int i = 0; i < 100; i++){
      //  m.newPassenger(2, 5);
   //}
    //m.pCommand();
    
    //for (int i = 0; i <100; i++) {
       // m.newPassenger(3, 4);
    //}
    
    //Train t(10);

    //for (int i = 0; i < 10; i++) {
      //  Passenger p(i, i, i);
       // (t.passengers[i]).enqueue(p);
    //}

    //Station test("test", 8);
    //for (int i = 0; i < 10; i++) {
      //  Passenger p(i, i, i);
        //test.addPassenger(p);
    //}
    //m.runSim();
    /*
    while (true) {
        //m.printState();
        m.readCommand();
    }
    */
    /*
    m.printState();
    m.newPassenger(2,3);
    m.printState();
    m.newPassenger(2,8);
    m.printState();
    m.newPassenger(5,9);
    m.printState();
    m.newPassenger(3,6);
    m.printState();
    m.newPassenger(1,4);
    m.printState();
    m.newPassenger(7,23);
    m.printState();
    */
    /*
    PassengerQueue q;
    for (int i = 0; i < 3; i++) {
        Passenger p(i + 1, 1, 6);
        q.enqueue(p);
    }

    m.stations[1].queue = q;
    
    m.moveTrain();
    m.moveTrain();
    m.moveTrain();
    m.moveTrain();
    m.moveTrain();
    m.printState();
`*/
    /*for (size_t i = 0; i < m.stations.size(); i++) {
        assert(m.stations[i].queue.size() == 0);
    } */
    //for (int i = 0; i < 100; i++) {
    //    m.moveTrain();
    //}
    /*
    m.printState();
    //int test;
    //std::cin >> test;
    m.trainLoc = m.trainLoc + 1;
    m.printState();
    m.trainLoc = m.trainLoc + 1;
    m.printState();
    m.trainLoc = m.trainLoc + 1;
    m.printState();
    */
    //std::cout << "Thanks for playing MetroSim. Have a nice day!\n";
    
    //m.output << "Bowser'sBigBeans\n";
    /*
    MetroSim m;
    //std::cout << "test1\n";
    assert(argc > 0);

    //assert(false);
    //m.openOutputFile(argv[1]);
    m.readStations(argv[1]);
    //std::cout << "ready\n";
    for (int i = 0; i < 26; i++){
        //std::cout << i << "F\n";
        assert((m.stations[i]).number() == i);
        //std::cout << i << endl;
    }
    
    assert(m.stations[0].name() == "Heath St");
    assert(m.stations[10].name() == "Prudential");
    assert(m.stations[25].name() == "College Ave");
    assert(m.stations.size() == 26);

    std::cout << "sucess\n";

    assert(m.stations[0].name() == "Bowser's");
    assert(m.stations[1].name() == "Big");
    assert(m.stations[3].name() == "Burrito");
    */

    return 0;
}
