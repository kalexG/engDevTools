//-------------------------------
// Filename: PrintOps_devTest.cpp
// Created: 01/03/2018
// Last Modified: 01/03/2018
// Author: Kevin Gomez
//-------------------------------

#include <iostream>
#include "../inc/PrintOps.h"
#include "../../math/inc/Array.h"

int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for PrintOps!\n\n");

    Array arr1(3, 3);
    Array arr2(3, 5);
    Array arr3(5, 3);
    
    arr1.setIncrement(1.0, 1.0);
    arr2.setIncrement(1.0, 1.0);
    arr3.setIncrement(1.0, 1.0);
    
    std::string arr1_p = PrintOps::printArray(arr1);
    std::string arr2_p = PrintOps::printArray(arr2);
    std::string arr3_p = PrintOps::printArray(arr3);
    
    std::string arr1_i = PrintOps::printArrayInfo(arr1);
    std::string arr2_i = PrintOps::printArrayInfo(arr2);
    std::string arr3_i = PrintOps::printArrayInfo(arr3);
    
    printf("%s\n", arr1_p.c_str());
    printf("%s\n", arr2_p.c_str());
    printf("%s\n", arr3_p.c_str());
    
    printf("%s\n", arr1_i.c_str());
    printf("%s\n", arr2_i.c_str());
    printf("%s\n", arr3_i.c_str());

    return 0;
}
