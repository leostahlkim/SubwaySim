/*
 *  MetroSim.cpp
 *  Name: Leo Kim
 *  Date: 2/21/22
 *
 *  CS 15 Proj1 A Metro Simulator
 *
 *  Purpose: The main function for the metro simulation.
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
        // Create a MetroSim based on the command line arguments
        MetroSim m(argc, argv);
        // Run the simulation
        m.runSim();

        return 0;
}