// Filename: testMvmaOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/vmaOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for vmaOps!\n");

   vmaOps vmaOps;
   bool testIsE;

   //// Run vectorOps tests
   
   printf("Running vectorOps tests\n");

   double v1[3] = {2,2,2};
   double v2[3] = {1,1,1};
   // Test vIsEqual
   vmaOps.vIsEqual(&testIsE,v1,v2);
   vmaOps.vIsEqual(&testIsE,v1,v1);

   double v3[3];
   double v4[3] = {1,2,3};
   double s1, s2;
   s1=0;
   vmaOps.vAdd(v3, v1, v2);
   vmaOps.sOps.printVector(v3,"v1+v2=v3");
   vmaOps.vSub(v3, v1, v2);
   vmaOps.sOps.printVector(v3,"v1-v2=v3");
   vmaOps.vMag(&s1, v1);
   vmaOps.sOps.printScalar(s1,"Vector Magnitude of Vector 1");
   vmaOps.vUnit(v3, v1);
   vmaOps.sOps.printVector(v3,"Unit Vector of Vector 1");
   vmaOps.crossProduct(v3, v2, v4);
   vmaOps.sOps.printVector(v3,"Cross Product of Vector 2 and Vector 4");
   vmaOps.dotProduct(&s1, v2, v4);
   vmaOps.sOps.printScalar(s1,"Dot Product of Vector 2 & Vector 4");

   //// Run matrixOps tests

   printf("Running matrixOps tests\n");

   double** m1;
   double** m2;
   double** m3;
   double** m4;
   m1 = vmaOps.mInit();
   vmaOps.mSetIdentity(m1);
   m2 = vmaOps.mInit();
   vmaOps.mSetIdentity(m2);
   m3 = vmaOps.mInit();
   vmaOps.mSetIdentity(m3);
   m4 = vmaOps.mInit();
   vmaOps.mSetZeros(m4);
   
   // Test Addition & Subtraction
   vmaOps.sOps.printMatrix(m1,"Initialize Matrix 1");
   vmaOps.sOps.printMatrix(m2,"Initialize Matrix 2");
   vmaOps.sOps.printMatrix(m3,"Initialize Matrix 3");
   vmaOps.mAdd(m3, m2, m1);
   vmaOps.sOps.printMatrix(m3,"m1+m2=m3");
   vmaOps.mSub(m3, m2, m1);
   vmaOps.sOps.printMatrix(m3,"m1-m2=m3");

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
   vmaOps.sOps.printMatrix(m1,"Matrix 1");
   vmaOps.sOps.printMatrix(m2,"Matrix 2");
   vmaOps.mSetIdentity(m3);
   vmaOps.sOps.printMatrix(m3,"Matrix 3");
   vmaOps.mMult(m4, m1, m2);
   vmaOps.sOps.printMatrix(m4,"m4=m1*m2");
   vmaOps.mTran(m3, m1);
   vmaOps.sOps.printMatrix(m3,"Tanspose of Matrix 1");
   vmaOps.mSetOnes(m3);
   vmaOps.sOps.printMatrix(m3,"Set to Ones");

   // Test Trace, Adjugate & Determinant
   vmaOps.mSetIdentity(m1);
   vmaOps.mSetIdentity(m2);
   s1=2; s2=0;
   vmaOps.mScaXMat(m2,s1,m2);
   vmaOps.mTrace(&s1, m1);
   vmaOps.mTrace(&s2, m2);
   vmaOps.sOps.printScalar(s1,"Trace of Matrix 1");
   vmaOps.sOps.printScalar(s2,"Trace of Matrix 2");

   // Test isEqual
   vmaOps.mIsEqual(&testIsE,m1,m2);
   vmaOps.sOps.printBool(testIsE,"isEqual for m1 & m2:");
   vmaOps.mSetIdentity(m2);
   vmaOps.mIsEqual(&testIsE,m1,m2);
   vmaOps.sOps.printBool(testIsE,"isEqual for m1 & m2:");
   m2[1][1]=0;
   vmaOps.mIsEqual(&testIsE,m1,m2);
   vmaOps.sOps.printBool(testIsE,"isEqual for m1 & m2:");

   // Run arrayOps tests
   myArray a1;
   myArray a2;
   myArray a3;
   int row=3;
   int col=5;
   a1 = vmaOps.aInit(row,col);
   a2 = vmaOps.aInit(row,col);
   vmaOps.aSetOnes(a2);
   a3 = vmaOps.aInit(row,col);
   vmaOps.aScaXArr(a3,-1,a2);
   vmaOps.sOps.printArray(a1,"a1 Initialized");
   vmaOps.sOps.printArray(a2,"a2 Ones");
   vmaOps.sOps.printArray(a3,"a3 = -1*a2");
   vmaOps.aSetZeros(a3);
   vmaOps.sOps.printArray(a3,"a3 Zeros");
   printf("Test arithmetic\n");
   
   myArray a4;
   myArray a5;
   myArray a6;
   row=5;
   a4 = vmaOps.aInit(row,col);
   a5 = vmaOps.aInit(row,col);
   a6 = vmaOps.aInit(row,col);
   vmaOps.sOps.printArray(a4,"a4 Initialized");
   printf("Check Add/Sub dimension check\n");
   vmaOps.aAdd(a5,a1,a4);
   vmaOps.aSub(a5,a1,a4);
   vmaOps.aSetOnes(a5);
   vmaOps.aScaXArr(a5,2,a5); 
   vmaOps.sOps.printArray(a5,"a5 = 2*Ones");
   vmaOps.aSetOnes(a4);
   vmaOps.aAdd(a6,a5,a4);
   vmaOps.sOps.printArray(a6,"a6 = a5 + Ones");
   vmaOps.aSub(a6,a5,a4);  
   vmaOps.sOps.printArray(a6,"a6 = a5 - Ones");
   printf("Check identity setting error catch.\n");
   vmaOps.aSetIdentity(a1);
   vmaOps.aSetIdentity(a6);
   vmaOps.sOps.printArray(a6,"a6 = Identity");
   printf("Test Transpose\n");
   get<0>(a6)[0][1]=2; get<0>(a6)[0][2]=2; get<0>(a6)[0][3]=2; get<0>(a6)[0][4]=2;
   get<0>(a6)[1][2]=3; get<0>(a6)[1][3]=3; get<0>(a6)[1][4]=3;
   get<0>(a6)[2][3]=4; get<0>(a6)[2][4]=4;
   get<0>(a6)[3][4]=5;
   vmaOps.sOps.printArray(a6,"Before Transpose (a6)");
   vmaOps.aTran(a5,a6);
   vmaOps.sOps.printArray(a5,"After Transpose (a5)");
   printf("Test Array isEqual\n");
   vmaOps.aIsEqual(&testIsE,a5,a3);
   vmaOps.aIsEqual(&testIsE,a5,a6);
   vmaOps.aIsEqual(&testIsE,a6,a6);   

   vmaOps.aFree(a1);
   vmaOps.aFree(a2);
   vmaOps.aFree(a3);
   vmaOps.aFree(a4);
   vmaOps.aFree(a5);
   vmaOps.aFree(a6);
   return 0;
}
