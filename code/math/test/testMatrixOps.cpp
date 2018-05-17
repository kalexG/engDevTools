// Filename: testVectorOps.cpp
// Created: 04/07/2018
// Last Modified: 04/07/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/matrixOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for matrixOps!\n");

   matrixOps mOps;

   double** m1;
   double** m2;
   double** m3;
   double** m4;
   m1 = mOps.mInit();
   mOps.mSetIdentity(m1);
   m2 = mOps.mInit();
   mOps.mSetIdentity(m2);
   m3 = mOps.mInit();
   mOps.mSetIdentity(m3);
   m4 = mOps.mInit();
   mOps.mSetZeros(m4);
   
   // Test Addition & Subtraction
   printf("Initialize Matrix 1\n");
   mOps.printMatrix(m1);
   printf("Initialize Matrix 2\n");
   mOps.printMatrix(m2);
   printf("Initialize Matrix 3\n");
   mOps.printMatrix(m3);
   printf("m1+m2=m3\n");
   mOps.mAdd(m3, m2, m1);
   mOps.printMatrix(m3);
   printf("m1-m2=m3\n");
   mOps.mSub(m3, m2, m1);
   mOps.printMatrix(m3);

   // Test Multiplication
   printf("Set up for Multiplication Test\n");
   int k=0;
   for (int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         m1[i][j]=k;
         m2[j][i]=k;
         k++;
      }
   }
   printf("Matrix 1\n");
   mOps.printMatrix(m1);
   printf("Matrix 2\n");
   mOps.printMatrix(m2);
   printf("Matrix 3\n");
   mOps.mSetIdentity(m3);
   mOps.printMatrix(m3);
   mOps.mMult(m4, m1, m2);
   printf("m4=m1*m2\n");
   mOps.printMatrix(m4);

   return 0;
}
