//----------------------------
// Filename: Array_devTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//----------------------------

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <chrono>
#include "../inc/Array.h"

using std::vector;

int main( int argc, char *argv[] ) {

    printf("Boost Comparison Test\n\n");

    int n = 2048;
    // Create instances of Array class
    Array arr1(n, n);
    Array arr2(n, n);
    Array arr3(n, n);

    printf("Construct Boost Matricies!\n");
    boost::numeric::ublas::matrix<double> A(n,n,1.0), B(n,n,1.0), C(n,n,0.0);

    // Initialize arrays for testing
    printf("Set arr1!\n");
    arr1.setOnes();
    printf("Set arr2!\n");
    arr2.setOnes();
    printf("Set arr3!\n");
    arr2.setZeros();
	
    auto t1 = std::chrono::high_resolution_clock::now();
    printf("Matrix Multiply (Array)!\n");
    arr3 = arr1 * arr2;
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("Matrix Multiply (Boost)!\n");
    boost::numeric::ublas::axpy_prod(A, B, C);
    auto t3 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> ms1 = t2 - t1;
    std::chrono::duration<double, std::milli> ms2 = t3 - t2;

    std::cout << ms1.count() << " ms\n";
    std::cout << ms2.count() << " ms\n";

	return 0;
}
