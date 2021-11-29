//----------------------------
// Filename: Array_devTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//----------------------------

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/Array.h"
#include "../../support/inc/PrintOps.h"
using namespace PrintOps;

int main( int argc, char *argv[] ) {

    printf("Array Class Development Test\n\n");

    // Create instances of Array class
    Array arr1(3, 3);
    Array arr2(3, 3);
    Array arr3(3, 3);
    Array arr4(4, 2);
    Array arr5(2, 4);

    // Initialize arrays for testing
    arr1.setOnes();
    arr2.setIncrement(1.0, 1.0);
    arr3.setZeros();
    arr4.setZeros();
    arr5.setZeros();
	
    // Test function: setOnes
    printf("arr1 set to Ones:\n%s", PrintOps::printArray( arr1 ).c_str());
    printf("\n");
	
    // Test function: setIncrement
    printf("arr2 incremented from 1.0 by 1.0:\n%s", PrintOps::printArray( arr2 ).c_str());
    printf("\n");
    
    // Test function: setZeros
    printf("arr3 set to Zeros:\n%s", PrintOps::printArray( arr3 ).c_str());
    printf("\n");
    
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
    
    printf("Start 3x3 determinant testing\n");
    Array arr9(3,3);
    arr9(0,0) = 6;
    arr9(0,1) = 1;
    arr9(0,2) = 1;
    arr9(1,0) = 4;
    arr9(1,1) = -2;
    arr9(1,2) = 5;
    arr9(2,0) = 2;
    arr9(2,1) = 8;
    arr9(2,2) = 7;
    printf("arr9 initialized!:\n%s\n", PrintOps::printArray( arr9 ).c_str());
    double det9 = arr9.getDeterminant();
    printf("Determinant of arr9 is: %f\n",det9);
    
    printf("Start 4x4 determinant testing\n");
    Array arr10(4,4);
    arr10(0,0) = 4;
    arr10(0,1) = 3;
    arr10(0,2) = 2;
    arr10(0,3) = 2;
    arr10(1,0) = 0;
    arr10(1,1) = 1;
    arr10(1,2) = -3;
    arr10(1,3) = 3;
    arr10(2,0) = 0;
    arr10(2,1) = -1;
    arr10(2,2) = 3;
    arr10(2,3) = 3;
    arr10(3,0) = 0;
    arr10(3,1) = 3;
    arr10(3,2) = 1;
    arr10(3,3) = 1;
    printf("arr10 initialized!:\n%s\n", PrintOps::printArray( arr10 ).c_str());
    double det10 = arr10.getDeterminant();
    printf("Determinant of arr10 is: %f\n",det10);
    
    Array arr11(4,4);
    arr11(0,0) = 4;
    arr11(0,1) = 3;
    arr11(0,2) = 2;
    arr11(0,3) = 2;
    arr11(1,0) = 0;
    arr11(1,1) = 1;
    arr11(1,2) = 0;
    arr11(1,3) = -2;
    arr11(2,0) = 1;
    arr11(2,1) = -1;
    arr11(2,2) = 3;
    arr11(2,3) = 3;
    arr11(3,0) = 2;
    arr11(3,1) = 3;
    arr11(3,2) = 1;
    arr11(3,3) = 1;
    printf("arr11 initialized!:\n%s\n", PrintOps::printArray( arr11 ).c_str());
    double det11 = arr11.getDeterminant();
    printf("Determinant of arr11 is: %f\n",det11);
    
    printf("Start 5x5 determinant testing\n");
    Array arr12(5,5);
    arr12(0,0) = 0;
    arr12(0,1) = 6;
    arr12(0,2) = -2;
    arr12(0,3) = -1;
    arr12(0,4) = 5;
    arr12(1,0) = 0;
    arr12(1,1) = 0;
    arr12(1,2) = 0;
    arr12(1,3) = -9;
    arr12(1,4) = -7;
    arr12(2,0) = 0;
    arr12(2,1) = 15;
    arr12(2,2) = 35;
    arr12(2,3) = 0;
    arr12(2,4) = 0;
    arr12(3,0) = 0;
    arr12(3,1) = -1;
    arr12(3,2) = -11;
    arr12(3,3) = -2;
    arr12(3,4) = 1;
    arr12(4,0) = -2;
    arr12(4,1) = -2;
    arr12(4,2) = 3;
    arr12(4,3) = 0;
    arr12(4,4) = -2;
    printf("arr12 initialized!:\n%s\n", PrintOps::printArray( arr12 ).c_str());
    double det12 = arr12.getDeterminant();
    printf("Determinant of arr12 is: %f\n",det12);

	return 0;
}
