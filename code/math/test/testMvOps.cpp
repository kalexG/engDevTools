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
   mvOps.printVector(v3,"v1+v2=v3");
   mvOps.vSub(v3, v1, v2);
   mvOps.printVector(v3,"v1-v2=v3");
   mvOps.vMag(&s1, v1);
   mvOps.printScalar(s1,"Vector Magnitude of Vector 1");
   mvOps.vUnit(v3, v1);
   mvOps.printVector(v3,"Unit Vector of Vector 1");
   mvOps.crossProduct(v3, v2, v4);
   mvOps.printVector(v3,"Cross Product of Vector 2 and Vector 4");
   mvOps.dotProduct(&s1, v2, v4);
   mvOps.printScalar(s1,"Dot Product of Vector 2 & Vector 4");

   //// Run matrixOps tests

   printf("Running matrixOps tests\n");

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
   mvOps.printMatrix(m1,"Initialize Matrix 1");
   mvOps.printMatrix(m2,"Initialize Matrix 2");
   mvOps.printMatrix(m3,"Initialize Matrix 3");
   mvOps.mAdd(m3, m2, m1);
   mvOps.printMatrix(m3,"m1+m2=m3");
   mvOps.mSub(m3, m2, m1);
   mvOps.printMatrix(m3,"m1-m2=m3");

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
   mvOps.printMatrix(m1,"Matrix 1");
   mvOps.printMatrix(m2,"Matrix 2");
   mvOps.mSetIdentity(m3);
   mvOps.printMatrix(m3,"Matrix 3");
   mvOps.mMult(m4, m1, m2);
   mvOps.printMatrix(m4,"m4=m1*m2");
   mvOps.mTran(m3, m1);
   mvOps.printMatrix(m3,"Tanspose of Matrix 1");

   // Test Trace, Adjugate & Determinant
   mvOps.mSetIdentity(m1);
   mvOps.mSetIdentity(m2);
   s1=2; s2=0;
   mvOps.mScaXMat(m2,s1,m2);
   mvOps.mTrace(&s1, m1);
   mvOps.mTrace(&s2, m2);
   mvOps.printScalar(s1,"Trace of Matrix 1");
   mvOps.printScalar(s2,"Trace of Matrix 2");

   // Test isEqual
   bool testIsE;
   mvOps.misEqual(&testIsE,m1,m2);
   mvOps.printBool(testIsE,"isEqual for m1 & m2:");
   mvOps.mSetIdentity(m2);
   mvOps.misEqual(&testIsE,m1,m2);
   mvOps.printBool(testIsE,"isEqual for m1 & m2:");
   m2[1][1]=0;
   mvOps.misEqual(&testIsE,m1,m2);
   mvOps.printBool(testIsE,"isEqual for m1 & m2:");

   return 0;
}
