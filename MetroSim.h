/*
 *  MetroSim.h
 *  Name: Leo Kim
 *  Date: 2/17/22
 *
 *  CS 15 Proj1 A Metro Simulator
 *
 *  Purpose: Class declaration for the MetroSim class. A MetroSim
 *           contains a list of Stations, a Train, an int tracking
 *           the train's location, and an fstream to store the output.
 *           It contains member functions that can read in information from 
 *           files and run the complete metro simulation.
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <fstream>
#include "Station.h"
#include "Train.h"

class MetroSim
{
public:
    MetroSim(int numCommands, char *cmmdline[]);
    ~MetroSim();

    void runSim();
private:
    // Private member variables
    Train train;
    std::vector<Station> stations;
    size_t trainLoc;
    int numPassengers;
    std::ofstream output;
    std::ifstream commands;
    
    // Functions for initializing the simulation
    void checkCommandLine(int numCommands);
    void readStations(std::string filename);
    std::ifstream openInFile(std::string filename);
    // Print function
    void printState();
    // Functions that alter the simulation state
    void moveTrain();
    void newPassenger(int start, int end);
    // Command helper functions
    bool readCommand();
    void pCommand();
    bool mCommand();
};

#endif