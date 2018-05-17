// Filename: testVectorOps.cpp
// Created: 04/07/2018
// Last Modified: 04/07/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/vectorOps.h"

int main( int argc, char *argv[] ) {
 
	// Check if the number of inputs is correct
/*	if (argc != 2 ) {
	   cout << "Incorrect Number of Input Arguments. \n";
		return 0;
	}
*/

	// Inputs
	printf("You made it to test function for vectorOps!\n");

   vectorOps vOps;

   double v1[3] = {2,2,2};
   double v2[3] = {1,1,1};
   double v3[3];
   double v4[3] = {1,2,3};
   double s1 = 0;
   vOps.vAdd(v3, v1, v2);
   vOps.printVector(v3);
   vOps.vSub(v3, v1, v2);
   vOps.printVector(v3);
   vOps.vMag(&s1, v1);
   printf("Vector Magnitude is: [%f]\n", s1);
   vOps.vUnit(v3, v1);
   vOps.printVector(v3);
   vOps.crossProduct(v3, v2, v4);
   vOps.printVector(v3);
   vOps.dotProduct(&s1, v2, v4);
   printf("Dot Product is: [%f]\n", s1);
	
   return 0;
}
