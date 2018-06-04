// Filename: arrayOpsOptim.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include "../inc/arrayOpsOptim.h"
#include <time.h>

int main( int argc, char *argv[] ) {

   // Set up timer
   clock_t t;

	printf("Get ready to multiply two 100x100 Arrays!\n");
   int row=500;
   int col=500;

   arrayOpsOptim aOpt;

// START: CASE 1

   // Start Clock
   t = clock();

   // Initialize Arrays
   // myArrayp2 is defined in aOpt. It is a tuple <double** array, int row, int col>

   myArrayp2 a1;
   myArrayp2 a2;
   myArrayp2 a3;
   a1 = aOpt.aInit_1(row,col);
   printf("Finished Initializing a1\n");
   a2 = aOpt.aInit_1(row,col);
   printf("Finished Initializing a2\n");
   a3 = aOpt.aInit_1(row,col);
   printf("Finished Initializing a3\n");
   
   // Run rudimentary MatMat multiplcation using [aOpt]

   // Set arrays being multiplied to 123 matricies
   aOpt.aSet123_1(a1);
   printf("Finished Setting a1 to 123\n");
   aOpt.aSet123_1(a2);
   printf("Finished Setting a2 to 123\n");
   aOpt.aSetZeros_1(a3);
   printf("Finished Setting a3 to Zeros\n");
   aOpt.sOps.printArray(a3,"a3");
   //aOpt.sOps.printArray(a6,"a6");

   printf("Starting a3=a1*a2 using [aOpt::aMatMat1]\n");
   aOpt.aMatMat_1(a3,a1,a2);
   printf("Finished a3=a1*a2\n");

   // Free memory
   aOpt.aFree_1(a1);
   aOpt.aFree_1(a2);
   aOpt.aFree_1(a3);

   // Get info from timer
   t = clock() - t;
   printf("Time to run aMatMat1: %f\n",((float)t)/CLOCKS_PER_SEC);

// END: CASE 1

// START: CASE 2

   // Initialize Arrays
   // myArrayp2 is defined in aOpt. It is a tuple <double** array, int row, int col>

   //myArrayp1* a4;
   //myArraySp1 sptr(new myArrayp1);
   //myArrayp1 a5;
   //myArrayp1 a6;
   //aOpt.aInit_2(a4, row, col);
   //printf("Row: %d | Col: %d\n",&get<1>(a4),&get<2>(a4));
   //printf("Finished Initializing a4\n");
   //aOpt.aInit_2(a5, row,col);
   //printf("Finished Initializing a5\n");
   //aOpt.aInit_2(a6, row,col);
   //printf("Finished Initializing a6\n");

   //printf("Starting a3=a1*a2 using [aOpt::aMatMat2]\n");
   //aOpt.aMatMat_2(a3,a1,a2);
   //printf("Finished a3=a1*a2\n");
   //aOpt.sOps.printArray(a2,"a2=a3*a6");

   // Free memory
   //aOpt.aFree_2(a4);
   //aOpt.aFree_2(a5);
   //aOpt.aFree_2(a6);

   // Get info from timer
   t = clock() - t;
   printf("Time to run aMatMat2: %f\n",((float)t)/CLOCKS_PER_SEC);

// END: CASE 2

   return 0;
}
