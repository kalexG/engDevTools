// Filename: testArrays.cpp
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/Array.h"
#include "../../support/inc/prwOps.h"
using namespace prwOps;

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for Array!\n\n");

	Array arr1(3, 3);
	Array arr2(3, 3);
	Array arr3(3, 3);
    Matrix mat1;
    Vector vec1;

    arr1.setOnes();
    arr2.setIncrement(1.0, 1.0);
    arr3 = arr1 + arr2;

	
	printf("\n");
	printf("| %f %f %f |\n", arr1(0,0), arr1(0,1), arr1(0,2));
	printf("| %f %f %f |\n", arr1(1,0), arr1(1,1), arr1(1,2));
	printf("| %f %f %f |\n", arr1(2,0), arr1(2,1), arr1(2,2));
	
	printf("\n");
	printf("| %f %f %f |\n", arr2(0,0), arr2(0,1), arr2(0,2));
	printf("| %f %f %f |\n", arr2(1,0), arr2(1,1), arr2(1,2));
	printf("| %f %f %f |\n", arr2(2,0), arr2(2,1), arr2(2,2));
	
    printf("\n");
	printf("| %f %f %f |\n", arr3(0,0), arr3(0,1), arr3(0,2));
	printf("| %f %f %f |\n", arr3(1,0), arr3(1,1), arr3(1,2));
	printf("| %f %f %f |\n", arr3(2,0), arr3(2,1), arr3(2,2));

    printf("%f\n",arr3[0]);
	
    //printf("\n");
	//printf("| %f %f %f |\n", vec1(0), vec1(1), vec1(2));
    
    //printf("Try accessing cols OOB: %f\n", mat1(0,3)); // Works
	//printf("Try accessing rows OOB: %f\n", vec1(3,0)); // Breaks

	return 0;
}
