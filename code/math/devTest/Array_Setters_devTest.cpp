#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/Array.h"

int main( int argc, char *argv[] ) {

    printf("Array Class Development Test: Setters\n\n");

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
    printf("arr1 set to Ones:\n%s", arr1.printArray().c_str());
    printf("\n\n");
	
    // Test function: setIncrement
    printf("arr2 incremented from 1.0 by 1.0:\n%s", arr2.printArray().c_str());
    printf("\n\n");
    
    // Test function: setZeros
    printf("arr3 set to Zeros:\n%s", arr3.printArray().c_str());
    printf("\n\n");

    // Test function: setTranspose
    arr3.setIncrement();
    printf("Try transpose: square matrix nxn\n");
    printf("arr3 before:\n%s\n", arr3.printArray().c_str());
    arr3.setTranspose();
    printf("arr3 after:\n%s\n", arr3.printArray().c_str());
    
    arr4.setIncrement();
    printf("\nTry transpose: matrix mxn, m>n\n");
    printf("arr4 before:\n%s\n", arr4.printArray().c_str());
    arr4.setTranspose();
    printf("arr4 after:\n%s\n", arr4.printArray().c_str());
    
    arr5.setIncrement();
    printf("\nTry transpose: matrix mxn,n>m\n");
    printf("arr5 before:\n%s\n", arr4.printArray().c_str());
    arr5.setTranspose();
    printf("arr5 after:\n%s\n", arr4.printArray().c_str());
   
	return 0;
}
