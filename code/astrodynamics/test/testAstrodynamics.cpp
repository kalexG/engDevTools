// Filename: testAstrodynamics.cpp
// Created: 03/31/2018
// Last Modified: 03/31/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/astrodynamics.h"

int main( int argc, char *argv[] ) {
 
	// Check if the number of inputs is correct
	if (argc != 2 ) {
	   cout << "Incorrect Number of Input Arguments.\n";
	   cout << "Options:\n";
	   cout << "1. 'all': Run all class tests.\n";
	   cout << "2. 'className': Run tests for specific class\n";
		return 0;
	}


	// Inputs
	cout << "You made it!\n";

   twoBodyOrbitalMech test_twoBodyOrbitalMech;
   test_twoBodyOrbitalMech.printDefines();

   // Test function: newtonLawOfG
   // TODO: Make a function that allocates memory or multidimensional array pointers
   double r[3] = {1, 1, 1};
   double m1=5;
   double m2=5;
   // TODO: Make a vector magnitude function.
   double r_mag= sqrt(3);
   // Run Function
   test_twoBodyOrbitalMech.newtonLawOfG(test_twoBodyOrbitalMech.Fg, m1, m2, r_mag, r);
   // G is really small so divide it out to see result!
   for(int i=0;i<3;i++)
   {
      test_twoBodyOrbitalMech.Fg[i]=test_twoBodyOrbitalMech.Fg[i]/G;
   }
   test_twoBodyOrbitalMech.printVector(test_twoBodyOrbitalMech.Fg);

   return 0;
}
