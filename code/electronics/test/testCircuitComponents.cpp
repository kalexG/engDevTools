// Filename: testCircuitComponents.cpp
// Created: 07/29/2018
// Last Modified: 07/29/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/circuitComponents.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for circuitComponenets!\n\n");

   // Creating circuitComponents objects
   resistor r1(100, 5);
   resistor r2(50, 1);
   resistor r3(10, 1);
   // Declaring variables


   // circuitComponents testing
   printf("STARTING OPS TESTS\n\n");
   // Check resistance
   r1.printResistance();
   r2.printResistance();
   r3.printResistance();

   printf("\nENDING OPS TESTS\n\n");

   return 0;
}
