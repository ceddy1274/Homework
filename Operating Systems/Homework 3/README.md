# Homework 3
In this homework, the primary goal was to gain a deeper understanding of multi-thread programming by using mutex locks to protect the critical section. This was achieved by simulating vehicles crossing a bridge. The vehicles would include trucks and cars from North and South directions. Restrictions had to be followed including:

* Only one truck or three cars could be on the road at a time
* Trucks would have priority over cars
* Truck priority would switch directions to have a balanced flow of traffic
* Car priority would not switch directions

A vehicle would cross the road and sleep for two seconds to simulate crossing the road. Once they finished crossing, they would signal for another vehicle to cross the bridge until all vehicles had crossed.

# How to run
This program was run on the Linux operating system. To run the program type this in your terminal:

* $make
* $./bridge_crossing

This will compile and run the bridge_crossing.c code. Once the code runs, a menu of options will pop up for users to select which simulation they want to run. When the user selects a simulation, vehicles will begin crossing the bridge printing the output of the current traffic state so the user can observe what is occurring.

# Description of files
The files included in this program are:

* bridge_crossing.c (the C file of the program)
* output.txt (a text file of a simulation for all outputs)
* makefile (the makefile used to compile the program)
  
