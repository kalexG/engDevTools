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
    Array arr4(4, 5);
    Array arr5(arr4);
    Matrix mat1;
    Vector vec1;
    printf("Size of arr4 = %dx%d\n", arr4.getRows(), arr4.getCols());
    printf("Size of arr5 = %dx%d\n", arr5.getRows(), arr5.getCols());

    arr1.setOnes();
    arr2.setIncrement(1.0, 1.0);
    arr3.setZeros();
	
	printf("\n");
	printf("| %f %f %f |\n", arr1(0,0), arr1(0,1), arr1(0,2));
	printf("| %f %f %f |\n", arr1(1,0), arr1(1,1), arr1(1,2));
	printf("| %f %f %f |\n", arr1(2,0), arr1(2,1), arr1(2,2));
	
	printf("\n");
	printf("| %f %f %f |\n", arr2(0,0), arr2(0,1), arr2(0,2));
	printf("| %f %f %f |\n", arr2(1,0), arr2(1,1), arr2(1,2));
	printf("| %f %f %f |\n", arr2(2,0), arr2(2,1), arr2(2,2));

    arr3 = (arr2 * 2.0) - arr1;
    arr3 = -arr3;
    arr3 = 3.0 * arr3;
    printf("\n");
	printf("| %f %f %f |\n", arr3(0,0), arr3(0,1), arr3(0,2));
	printf("| %f %f %f |\n", arr3(1,0), arr3(1,1), arr3(1,2));
	printf("| %f %f %f |\n", arr3(2,0), arr3(2,1), arr3(2,2));
    //printf("\n");
	//printf("| %f %f %f |\n", vec1(0), vec1(1), vec1(2));
    try
    {
        printf("Try accessing cols OOB: %f\n", mat1(0,3)); // Works
    }
    catch(const runtime_error& error1)
    {
        printf("Ya got caught 1!\n");
    }
    catch (const std::out_of_range& error2)
    {
        printf("Ya got caught 2!\n");
    }
	//printf("Try accessing rows OOB: %f\n", vec1(3,0)); // Breaks

	return 0;
}
