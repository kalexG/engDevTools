// Filename: testArrays.cpp
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/Array.h"
//using namespace PrintOps;

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for Array!\n\n");

	Array arr1(3, 3);
	Array arr2(3, 3);
	Array arr3(3, 3);
    Array arr4(4, 2);
    Array arr5(2, 4);

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
    arr3.setIncrement();
    printf("Try transpose: square matrix nxn\n");
	printf("Before\n");
    printf("| %f %f %f |\n", arr3(0,0), arr3(0,1), arr3(0,2));
	printf("| %f %f %f |\n", arr3(1,0), arr3(1,1), arr3(1,2));
	printf("| %f %f %f |\n", arr3(2,0), arr3(2,1), arr3(2,2));
   
    arr3.setTranspose();
    printf("\n");
    printf("After\n");
	printf("| %f %f %f |\n", arr3(0,0), arr3(0,1), arr3(0,2));
	printf("| %f %f %f |\n", arr3(1,0), arr3(1,1), arr3(1,2));
	printf("| %f %f %f |\n", arr3(2,0), arr3(2,1), arr3(2,2));
    printf("End transpose\n");
    
    printf("\n");
    arr4.setIncrement();
    printf("Try transpose: matrix mxn, m>n\n");
	printf("Before: rows = %d, cols = %d\n", arr4.getMyRows(), arr4.getMyCols());
    printf("| %f %f |\n", arr4(0,0), arr4(0,1));
	printf("| %f %f |\n", arr4(1,0), arr4(1,1));
	printf("| %f %f |\n", arr4(2,0), arr4(2,1));
	printf("| %f %f |\n", arr4(3,0), arr4(3,1));
   
    arr4.setTranspose();
    printf("\n");
	printf("After: rows = %d, cols = %d\n", arr4.getMyRows(), arr4.getMyCols());
    printf("| %f %f %f %f|\n", arr4(0,0), arr4(0,1), arr4(0,2), arr4(0,3));
	printf("| %f %f %f %f|\n", arr4(1,0), arr4(1,1), arr4(1,2), arr4(1,3));
    printf("End transpose\n");
    
    printf("\n");
    arr5.setIncrement();
    printf("Try transpose: matrix mxn, m>n\n");
	printf("Before: rows = %d, cols = %d\n", arr4.getMyRows(), arr4.getMyCols());
    printf("| %f %f %f %f|\n", arr5(0,0), arr5(0,1), arr5(0,2), arr5(0,3));
	printf("| %f %f %f %f|\n", arr5(1,0), arr5(1,1), arr5(1,2), arr5(1,3));
   
    arr5.setTranspose();
    printf("\n");
	printf("After: rows = %d, cols = %d\n", arr5.getMyRows(), arr5.getMyCols());
    printf("| %f %f |\n", arr5(0,0), arr5(0,1));
	printf("| %f %f |\n", arr5(1,0), arr5(1,1));
	printf("| %f %f |\n", arr5(2,0), arr5(2,1));
	printf("| %f %f |\n", arr5(3,0), arr5(3,1));
    printf("End transpose\n");
    
    std::vector<double> get1DVec = arr5.getStdVector1D();
    printf("| %f %f |\n", get1DVec.at(0), get1DVec.at(1));
	printf("| %f %f |\n", get1DVec.at(2), get1DVec.at(3));
	printf("| %f %f |\n", get1DVec.at(4), get1DVec.at(5));
	printf("| %f %f |\n", get1DVec.at(6), get1DVec.at(7));
    printf("\n");
    std::vector<std::vector<double>> get2DVec = arr5.getStdVector2D();
    printf("| %f %f |\n", get2DVec.at(0).at(0), get2DVec.at(0).at(1));
	printf("| %f %f |\n", get2DVec.at(1).at(0), get2DVec.at(1).at(1));
	printf("| %f %f |\n", get2DVec.at(2).at(0), get2DVec.at(2).at(1));
	printf("| %f %f |\n", get2DVec.at(3).at(0), get2DVec.at(3).at(1));

    Array arr6(4,3);
    Array arr7(3,2);
    Array arr8(4,2);
    arr6.setIncrement(1.0, 1.0);
    arr7.setOnes();
    arr8.setZeros();
    arr8 = arr6 * arr7;
    printf("Matrix Multiply (*)!\n");
    printf("| %f %f |\n", arr8(0,0), arr8(0,1));
	printf("| %f %f |\n", arr8(1,0), arr8(1,1));
	printf("| %f %f |\n", arr8(2,0), arr8(2,1));
	printf("| %f %f |\n", arr8(3,0), arr8(3,1));
    
    try
    {
        printf("Try accessing cols OOB: %f\n", arr1(0,3));
    }
    catch(const std::length_error& error1)
    {
        printf("Caught runtime_error exception!\n");
    }
    catch (const std::out_of_range& error2)
    {
        printf("Caught out_of_range exception!\n");
    }
    try
    {   
        Array arr(0, 0);
    }
    catch (const std::invalid_argument& error3)
    {
        printf("Caught invalid_argument exception!\n");
    }
	//printf("Try accessing rows OOB: %f\n", vec1(3,0)); // Breaks

	return 0;
}
