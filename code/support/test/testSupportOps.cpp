// Filename: testSupportOps.cpp
// Created: 05/25/2018
// Last Modified: 05/25/2018
// Author: Kevin Gomez

#include "../../math/inc/vmaOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for supportOps!\n\n");

   vmaOps vmaOps;
   //sOps.printInfo();

   // Declaring variables
   bool cBool;
   double cScalar;
   double cVector[3];
   double **cMatrix;
   myArray cArray1, cArray2;

   //// Run MEM Tests
   
   printf("STARTING PRINT TESTS\n\n");

   cMatrix = vmaOps.mInit();
   cArray1 = vmaOps.aInit(3,5);
   cArray2 = vmaOps.aInit(5,3);

   printf("Set Bool=true, scalar=10, Vector=Matrix=Array=123\n");
   cBool=true;
   cScalar=10;
   vmaOps.vSet123(cVector);
   vmaOps.mSet123(cMatrix);
   vmaOps.aSet123(cArray1);
   vmaOps.aSet123(cArray2);

   printf("Printing out variables.\n");
   vmaOps.sOps.printBool(cBool,"Check printBool");
   vmaOps.sOps.printScalar(cScalar,"Check printScalar");
   vmaOps.sOps.printVector(cVector,"Check printVector");
   vmaOps.sOps.printMatrix(cMatrix,"Check printMatrix");
   vmaOps.sOps.printArray(cArray1,"Check printArray: col>row");
   vmaOps.sOps.printArray(cArray2,"Check printArray: row>col");

   printf("\nENDING PRINT TESTS\n\n");
   

   vmaOps.sOps.wDppArray2Csv(cArray2,"testOut.csv");

   vmaOps.mFree(cMatrix);
   vmaOps.aFree(cArray1);
   vmaOps.aFree(cArray2);


   return 0;
}
