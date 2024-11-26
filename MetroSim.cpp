/*
 *  MetroSim.cpp
 *  Name: Leo Kim
 *  Date: 2/17/22
 *
 *  Purpose: Class implementation for the MetroSim class. A MetroSim
 *           contains a list of Stations and a Train along with some other 
 *           member variables. It contains member functions that 
 *           can read in information from files and run the complete
 *           metro simulation.
 */

#include "MetroSim.h"

/*
 * name:      MetroSim command line constructor
 * purpose:   initialize the MetroSim private member variables based on the
 *            given files
 * arguments: int for number of command line arguments and string array of
 *            the arguments
 * returns:   none
 * effects:   populates the stations list, initializes the output and 
 *            and command files, creates the train and sets the train location
 */
MetroSim::MetroSim(int numCommands, char *cmmdline[]) {
    // Checks the command line by running member function
    checkCommandLine(numCommands);
    // Reads in and populates the station list by running member function
    readStations(cmmdline[1]);
    // Opens the output file named after the given name
    output.open(cmmdline[2]);
    // If a commands file was provided, opens it
    if (numCommands == 4) {
        commands = openInFile(cmmdline[3]);
    }
    // Initialize the Train variable based on the given number of stations
    Train t(stations.size());
    train = t;
    // Initialize the train location and number of passengers
    trainLoc = 0;
    numPassengers = 0;
}

/*
 * name:      MetroSim destructor
 * purpose:   close the files associated with the MetroSim class
 * arguments: none
 * returns:   none
 * effects:   closes the necessary files
 */
MetroSim::~MetroSim() {
    // Checks to see if files are still open, and if so closes them
    if (output.is_open()) {
        output.close();
    }
    if (commands.is_open()) {
        commands.close();
    }
}

/*
 * name:      runSim
 * purpose:   run the metro simulation
 * arguments: none
 * returns:   none
 * effects:   runs the simulation
 */
void MetroSim::runSim() {
    // Prints the intial state of the game
    printState();
    // Runs a given command and then prints the simulation state until the user
    // asks to quit
    while (readCommand()) {
        printState();
    }
    // Prints the correct end message
    std::cout << "Thanks for playing MetroSim. Have a nice day!\n";
}

/*
 * name:      printState
 * purpose:   print the current state of the simulation to the terminal
 * arguments: none
 * returns:   none
 * effects:   none
 */
void MetroSim::printState() {
    // Prints the train followed by an endline
    train.print();
    std::cout << std::endl;
    // Prints each station on its own line
    for (size_t i = 0; i < stations.size(); i++) {
        // If the train is at the given station, prints "TRAIN:" before the
        // station. If not it fills the area with blank space.
        if (i == trainLoc) {
            std::cout << "TRAIN: ";
        } else {
            std::cout << "       ";
        }
        // Prints the Station
        stations[i].print();
        std::cout << std::endl;
    }
    // Prints a question asking the user for the next command
    std::cout << "Command? ";
}

/*
 * name:      checkCommandLine
 * purpose:   check to make sure the correct amount of arguments are input
 * arguments: an int for the number of command line arguments
 * returns:   none
 * effects:   none
 */
void MetroSim::checkCommandLine(int numCommands) {
    // Ensure that the correct amount of arguments are given
    // If not, print the correct error message, then exit the program
    if ((numCommands != 3) and (numCommands != 4)) {
        std::cerr << "Usage: ./MetroSim stationsFile outputFile";
        std::cerr << " [commandsFile]\n";
        exit(1);
    }
}

/*
 * name:      readStations
 * purpose:   Open the stations file and read in the station names to the
 *            list of Station variables
 * arguments: a string with the file name
 * returns:   none
 * effects:   populates the list of Stations
 */
void MetroSim::readStations(std::string filename) {
    // Variable to store the station names file
    std::ifstream inFile = openInFile(filename);
    // Variable to store the name being read it
    std::string stationName;
    // Variable to store the amount of stations read in
    int size = 0;
    // Read in the station name and store it. Repeat this until you reach
    // the end of the file
    while (getline(inFile, stationName)) {
        // Create a station with the given name and number
        Station s(stationName, size);
        // Add it to the list of stations
        stations.push_back(s);
        size++;
    }
    // Close the stations file
    inFile.close();
}

/*
 * name:      openInFile
 * purpose:   Open the given file. If the file won't open, exit with cerr
 * arguments: a file name
 * returns:   an open ifstream
 * effects:   opens the given file 
 */
std::ifstream MetroSim::openInFile(std::string filename) {
    std::ifstream file;
    file.open(filename);

    if (not file.is_open()) {
        std::cerr << "Error: could not open file ";
        std::cerr << filename << std::endl;
        exit(1);
    }

    return file;
}

/*
 * name:      moveTrain
 * purpose:   move the train forward one station and perform the necessary
 *            loading and unloading 
 * arguments: none
 * returns:   none
 * effects:   loads the train from the stations, moves Passengers 
 */
void MetroSim::moveTrain() {
    // Calls the loadPassengers member functions for both the 
    // train and the station the train is currently at
    train.loadPassengers(stations[trainLoc].loadPassengers());
    // Moves the train forward one space
    trainLoc = train.move();
    // Calls the unloadPassengers member function for the Train
    // with the correct output file and station name
    train.unloadPassengers(output, stations[trainLoc].name());
}

/*
 * name:      newPassenger
 * purpose:   add a new passenger to the simulation 
 * arguments: passenger's starting and ending stations
 * returns:   none
 * effects:   adds a passenger to the simulation 
 */
void MetroSim::newPassenger(int start, int end) {
    // Increases the number of passengers by 1
    numPassengers++;
    // Creates the passenger being added
    Passenger p(numPassengers, start, end);
    // Adds it to the correct station
    stations[start].addPassenger(p);    
}

/*
 * name:      readCommand
 * purpose:   read in a command from the given istream and perform the
 *            requested action 
 * arguments: none
 * returns:   none
 * effects:   runs a given command 
 */
bool MetroSim::readCommand() {
    // Variable to store the command being read
    char firstCmmd;
    // Check if the simulation is being run with a command file
    if (commands.is_open()) {
        // If the end of the command file is reached, return false
        if (commands.eof()) {
            return false;
        }
        // If not, read in the given command
        commands >> firstCmmd;
    } 
    // If the simulation is not being run with a command file, read in
    // the command through cin
    else {
        std::cin >> firstCmmd;
    }
    // Run the correct helper function based on the given command
    if (firstCmmd == 'p') {
        // Run the helper function associated with adding passengers
        pCommand();
        return true;
    } if (firstCmmd == 'm') {
        // Run the helper function associated with moving the train
        // and quitting the simulation
        return mCommand();
    }
    
    return true;
}

/*
 * name:      pCommand
 * purpose:   perform the given reading in and action associated with the p
 *            command
 * arguments: none
 * returns:   none
 * effects:   runs the newPassenger command
 */
void MetroSim::pCommand() {
    // Variables to store the station numbers of the passenger being added
    int from;
    int to;
    // If the simulation is using a command file, read in the station numbers
    // from the file
    if (commands.is_open()){
        commands >> from >> to;
    } 
    // If not, read them in from cin
    else {
        std::cin >> from >> to;
    }
    // Add a new passenger to the simulation based on the given station numbers
    newPassenger(from, to);
}

/*
 * name:      mCommand
 * purpose:   perform the given reading in and action associated with the m
 *            command
 * arguments: none
 * returns:   none
 * effects:   either moves the train forward or quits
 */
//void MetroSim::mCommand() {
bool MetroSim::mCommand() {
    // Variable to store the given command
    char cmmd;
    // If the simulation is using a command file, read in the command from
    // the file
    if (commands.is_open()){
        commands >> cmmd;
    } 
    // If not, read it in from cin
    else {
        std::cin >> cmmd;
    }
    // Do the action corresponding to the given command
    if (cmmd == 'f') {
        return false;
    } if (cmmd == 'm') {
        moveTrain();
    }
    return true;
}