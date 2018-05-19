// Filename: testMmvOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/mvOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for mvOps!\n");

   mvOps mvOps;

   //// Run vectorOps tests
   
   printf("Running vectorOps tests\n");

   double v1[3] = {2,2,2};
   double v2[3] = {1,1,1};
   double v3[3];
   double v4[3] = {1,2,3};
   double s1, s2;
   s1=0;
   mvOps.vAdd(v3, v1, v2);
   mvOps.printVector(v3);
   mvOps.vSub(v3, v1, v2);
   mvOps.printVector(v3);
   mvOps.vMag(&s1, v1);
   printf("Vector Magnitude is: [%f]\n", s1);
   mvOps.vUnit(v3, v1);
   mvOps.printVector(v3);
   mvOps.crossProduct(v3, v2, v4);
   mvOps.printVector(v3);
   mvOps.dotProduct(&s1, v2, v4);
   printf("Dot Product is: [%f]\n", s1);

   //// Run matrixOps tests

   printf("Running vectorOps tests\n");

   double** m1;
   double** m2;
   double** m3;
   double** m4;
   m1 = mvOps.mInit();
   mvOps.mSetIdentity(m1);
   m2 = mvOps.mInit();
   mvOps.mSetIdentity(m2);
   m3 = mvOps.mInit();
   mvOps.mSetIdentity(m3);
   m4 = mvOps.mInit();
   mvOps.mSetZeros(m4);
   
   // Test Addition & Subtraction
   printf("Initialize Matrix 1\n");
   mvOps.printMatrix(m1);
   printf("Initialize Matrix 2\n");
   mvOps.printMatrix(m2);
   printf("Initialize Matrix 3\n");
   mvOps.printMatrix(m3);
   printf("m1+m2=m3\n");
   mvOps.mAdd(m3, m2, m1);
   mvOps.printMatrix(m3);
   printf("m1-m2=m3\n");
   mvOps.mSub(m3, m2, m1);
   mvOps.printMatrix(m3);

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
   mvOps.printMatrix(m1);
   printf("Matrix 2\n");
   mvOps.printMatrix(m2);
   printf("Matrix 3\n");
   mvOps.mSetIdentity(m3);
   mvOps.printMatrix(m3);
   mvOps.mMult(m4, m1, m2);
   printf("m4=m1*m2\n");
   mvOps.printMatrix(m4);

   printf("Tanspose of Matrix 1 is:\n");
   mvOps.mTran(m3, m1);
   mvOps.printMatrix(m3);

   // Test Trace, Adjugate & Determinant
   mvOps.mSetIdentity(m1);
   mvOps.mSetIdentity(m2);
   s1=2; s2=0;
   mvOps.mScaXMat(m2,s1,m2);
   mvOps.mTrace(&s1, m1);
   mvOps.mTrace(&s2, m2);
   printf("Scalar values from trace are:\n");
   mvOps.printScalar(s1);
   mvOps.printScalar(s2);

   // Test isEqual
   bool testIsE;
   mvOps.misEqual(&testIsE,m1,m2);
   printf("isEqual for m1 & m2 is: %s\n", testIsE ? "True" : "False"); 
   mvOps.mSetIdentity(m2);
   mvOps.misEqual(&testIsE,m1,m2);
   printf("isEqual for m1 & m2 is: %s\n", testIsE ? "True" : "False"); 


   return 0;
}
