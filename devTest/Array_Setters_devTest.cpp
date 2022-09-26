#include "Array.h"
#include "ArrayUtilities.h"

int main( int argc, char *argv[] ) {

    printf("Array Class Development Test: Setters\n\n");

    // Create instances of Array class
    Array<double> arr1(3, 3);
    Array<double> arr2(3, 3);
    Array<double> arr3(3, 3);
    Array<double> arr4(4, 2);
    Array<double> arr5(2, 4);

    // Initialize arrays for testing
    arr1.ones();
    arr2.set(1.0, 1.0);
    arr3.zeros();
    arr4.zeros();
    arr5.zeros();
	
    // Test function: setOnes
    printf("arr1 set to Ones:\n%s", Utilities::printArray(arr1).c_str());
    printf("\n\n");
	
    // Test function: setIncrement
    printf("arr2 incremented from 1.0 by 1.0:\n%s", Utilities::printArray(arr2).c_str());
    printf("\n\n");
    
    // Test function: setZeros
    printf("arr3 set to Zeros:\n%s", Utilities::printArray(arr3).c_str());
    printf("\n\n");

    // Test function: setTranspose
    arr3.set(0.0, 1.0);
    printf("Try transpose: square matrix nxn\n");
    printf("arr3 before:\n%s\n", Utilities::printArray(arr3).c_str());
    arr3.s_transpose();
    printf("arr3 after:\n%s\n", Utilities::printArray(arr3).c_str());
    
    arr4.set(0.0, 1.0);
    printf("\nTry transpose: matrix mxn, m>n\n");
    printf("arr4 before:\n%s\n", Utilities::printArray(arr4).c_str());
    arr4.s_transpose();
    printf("arr4 after:\n%s\n", Utilities::printArray(arr4).c_str());
    
    arr5.set(0.0, 1.0);
    printf("\nTry transpose: matrix mxn,n>m\n");
    printf("arr5 before:\n%s\n", Utilities::printArray(arr5).c_str());
    arr5.s_transpose();
    printf("arr5 after:\n%s\n", Utilities::printArray(arr5).c_str());
   
	return 0;
}
