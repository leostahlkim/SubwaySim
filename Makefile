#########################################################
#             MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# ***TODO***
# Metrosim rule - you need to fill in the linking command,
# add any new dependencies, and add target rules for 
# Passenger.o, MetroSim.o, main.o, and any new dependencies.
# Please use the rules provided below for PassengerQueue.o as an example for
# what to do.
# If you add other classes, you'll have to add their .o files as dependencies 
# here.
# Don't forget:  the clang++ command must be indented with a TAB character
# and be all on one line.
MetroSim: main.o MetroSim.o PassengerQueue.o Passenger.o Train.o Station.o
	$(CXX) $(LDFLAGS) -o MetroSim $^

# This rule builds mainTesting, a program I used for testing my code
mainTesting: mainTesting.o MetroSim.o Train.o Station.o PassengerQueue.o \
			 Passenger.o
	$(CXX) $(LDFLAGS) -o mainTesting $^


# This rule builds mainTesting.o
mainTesting.o: mainTesting.cpp MetroSim.h Train.h Station.h PassengerQueue.h \
			   Passenger.h
	$(CXX) $(CXXFLAGS) -c mainTesting.cpp

# This rule builds MetroSim.o
MetroSim.o: MetroSim.cpp MetroSim.h Train.h Station.h PassengerQueue.h \
						 Passenger.h
	$(CXX) $(CXXFLAGS) -c MetroSim.cpp

# This rule builds Train.o
Train.o: Train.cpp Train.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c Train.cpp

# This rule builds Station.o
Station.o: Station.cpp Station.h PassengerQueue.h Passenger.h
	$(CXX) $(CXXFLAGS) -c Station.cpp

# This rule builds Passenger.o
Passenger.o:

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

# This rule is used for the unit testing framework
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o Station.o Train.o \
		   MetroSim.o
	$(CXX) $(CXXFLAGS) $^


# This rule provides my final submission
provide:
	provide comp15 proj1_MetroSim PassengerQueue.h main.cpp MetroSim.cpp \
				    PassengerQueue.cpp mainTesting.cpp MetroSim.h Station.cpp \
				    Passenger.h Passenger.cpp Station.h Train.cpp Train.h \
				    unit_tests.h Makefile README 

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm *.o *~ a.out
