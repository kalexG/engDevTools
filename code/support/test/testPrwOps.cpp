// Filename: testPrwOps.cpp
// Created: 05/25/2018
// Last Modified: 05/25/2018
// Author: Kevin Gomez

#include "../../math/inc/vmaOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for prwOps!\n\n");

   vmaOps vmaOps;
   //prwOps.printInfo();

   // Declaring variables
   bool cBool;
   double cScalar;
   double cVector[3];
   double **cMatrix;
   myArray cArray1, cArray2;

   //// Run PRINT Tests
   
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
   vmaOps.prwOps.printBool(cBool,"Check printBool");
   vmaOps.prwOps.printScalar(cScalar,"Check printScalar");
   vmaOps.prwOps.printVector(cVector,"Check printVector");
   vmaOps.prwOps.printMatrix(cMatrix,"Check printMatrix");
   vmaOps.prwOps.printArray(cArray1,"Check printArray: col>row");
   vmaOps.prwOps.printArray(cArray2,"Check printArray: row>col");

   printf("\nENDING PRINT TESTS\n\n");

   //// Run READ Tests

   printf("STARTING READ TESTS\n\n");
   
   printf("Nothing here yet.\n");

   printf("\nENDING READ TESTS\n\n");

   //// Run WRITE Tests

   printf("STARTING WRITE TESTS\n\n");

   printf("Printing Array 1 to file \"testA1Out.csv\"\n");
   vmaOps.prwOps.wDppArray2Csv(cArray1,"testA1Out.csv");
   printf("Printing Array 2 to file \"testA2Out.csv\"\n");
   vmaOps.prwOps.wDppArray2Csv(cArray2,"testA2Out.csv");

   printf("\nENDING WRITE TESTS\n\n");

   vmaOps.mFree(cMatrix);
   cMatrix = NULL;
   vmaOps.aFree(cArray1);
   get<0>(cArray1) = NULL;
   vmaOps.aFree(cArray2);
   get<0>(cArray2) = NULL;

   return 0;
}
