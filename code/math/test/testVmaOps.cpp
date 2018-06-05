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
	printf("You made it to test function for vmaOps!\n\n");

   // Creating vmaOps object
   vmaOps vmaOps;

   // Declaring variables
   bool testIsE;
   double s1, s2, det;
   double v1[3], v2[3], v3[3], v4[3];
   double **m1, **m2, **m3, **m4;
   myArray a1, a2, a3, a4, a5, a6;

   //// Run MEM Tests
   
   printf("STARTING MEM TESTS\n\n");

   printf("Initializing matricies m[1-4]\n");
   m1 = vmaOps.mInit();
   m2 = vmaOps.mInit();
   m3 = vmaOps.mInit();
   m4 = vmaOps.mInit();

   printf("Initializing arrays a[1-6]\n");
   a1 = vmaOps.aInit(3,5);
   a2 = vmaOps.aInit(3,5);
   a3 = vmaOps.aInit(3,5);
   a4 = vmaOps.aInit(5,5);
   a5 = vmaOps.aInit(5,5);
   a6 = vmaOps.aInit(2,2);

   printf("\nENDING MEM TESTS\n\n");

   // Run SET Tests
   printf("STARTING SET TESTS\n\n");

   printf("vectorOps: Zeros->Ones->123\n");
   vmaOps.vSetZeros(v1);
   vmaOps.sOps.printVector(v1,"Check Zeros (v1)");
   vmaOps.vSetOnes(v1);
   vmaOps.sOps.printVector(v1,"Check Ones (v1)");
   vmaOps.vSet123(v1);
   vmaOps.sOps.printVector(v1,"Check 123 (v1)");

   printf("\nmatrixOps: Zeros->Ones->123->Identity\n");
   vmaOps.mSetZeros(m1);
   vmaOps.sOps.printMatrix(m1,"Check Zeros (m1)");
   vmaOps.mSetOnes(m1);
   vmaOps.sOps.printMatrix(m1,"Check Ones (m1)");
   vmaOps.mSet123(m1);
   vmaOps.sOps.printMatrix(m1,"Check 123 (m1)");
   vmaOps.mSetIdentity(m1);
   vmaOps.sOps.printMatrix(m1,"Check Identity (m1)");

   printf("\narrayOps: Zeros->Ones->123->Identity\n");
   vmaOps.aSetZeros(a1);
   vmaOps.sOps.printArray(a1,"Check Zeros (a1)");
   vmaOps.aSetOnes(a1);
   vmaOps.sOps.printArray(a1,"Check Ones (a1)");
   vmaOps.aSet123(a1);
   vmaOps.sOps.printArray(a1,"Check 123 (a1)");
   printf("Check Identity (a1) (Non-Square Matrix: Shouldn't Work)\n");
   vmaOps.aSetIdentity(a1);
   vmaOps.aSetIdentity(a4);
   vmaOps.sOps.printArray(a1,"Check Identity (a4) [Square Matrix: Should Work]");

   printf("\nENDING SET TESTS\n\n");

   // Run CHECK TESTS

   printf("STARTING CHECK TESTS\n\n");

   printf("vectorOps: isEqual\n");
   vmaOps.vSetOnes(v1);
   vmaOps.ScaXVec(v1,2,v1);
   vmaOps.vSetOnes(v2);
   vmaOps.sOps.printVector(v1,"v1");
   vmaOps.sOps.printVector(v2,"v2");
   printf("Check: isEqual -> v1 & v2\n");
   vmaOps.vIsEqual(&testIsE,v1,v2);
   printf("Check: isEqual -> v1 & v1\n");
   vmaOps.vIsEqual(&testIsE,v1,v1);

   printf("\nmatrixOps: isEqual\n");
   vmaOps.mSetOnes(m1);
   vmaOps.ScaXMat(m1,2,m1);
   vmaOps.mSetOnes(m2);
   vmaOps.sOps.printMatrix(m1,"m1");
   vmaOps.sOps.printMatrix(m2,"m2");
   printf("Check: isEqual -> m1 & m2\n");
   vmaOps.mIsEqual(&testIsE,m1,m2);
   printf("Check: isEqual -> m1 & m1\n");
   vmaOps.mIsEqual(&testIsE,m1,m1);

   printf("\narrayOps: isEqual\n");
   vmaOps.aSetOnes(a1);
   vmaOps.ScaXArr(a1,2,a1);
   vmaOps.aSetOnes(a2);
   vmaOps.aSetOnes(a4);
   vmaOps.sOps.printArray(a1,"a1");
   vmaOps.sOps.printArray(a2,"a2");
   vmaOps.sOps.printArray(a4,"a3");
   printf("Check isEqual (a1 & a4) [Different Dimensions: Shouldn't Work]\n");
   vmaOps.aIsEqual(&testIsE,a1,a4);
   printf("Check: isEqual -> a1 & a2\n");
   vmaOps.aIsEqual(&testIsE,a1,a2);
   printf("Check: isEqual -> a1 & a1\n");
   vmaOps.aIsEqual(&testIsE,a1,a1);

   printf("\nENDING CHECK TESTS\n\n");

   // RUN OPS TESTS

   printf("STARTING OPS TESTS\n\n");

   printf("vectorOps: Add, Subtract, Magnitude, Unit Vector, Cross Product, Dot Product\n");
   vmaOps.sOps.printVector(v1,"v1 = 2*Ones");
   vmaOps.sOps.printVector(v2,"v2");
   vmaOps.vAdd(v3, v1, v2);
   vmaOps.sOps.printVector(v3,"v3=v1+v2");
   vmaOps.vSub(v3, v1, v2);
   vmaOps.sOps.printVector(v3,"v3=v1-v2");
   vmaOps.vMag(&s1, v1);
   vmaOps.sOps.printScalar(s1,"Vector Magnitude of v1");
   vmaOps.vUnit(v3, v1);
   vmaOps.sOps.printVector(v3,"Unit Vector of v1");
   vmaOps.vSet123(v4);
   vmaOps.sOps.printVector(v4,"v4");
   vmaOps.crossProduct(v3, v2, v4);
   vmaOps.sOps.printVector(v3,"Cross Product of v2 & v4 = v3");
   vmaOps.dotProduct(&s1, v2, v4);
   vmaOps.sOps.printScalar(s1,"Dot Product of v2 & v4 = s1");

   printf("\nmatrixOps: Add, Subtract, Multiplication, Transpose, Trace\n");
   vmaOps.sOps.printMatrix(m1,"m1=2*Ones");
   vmaOps.sOps.printMatrix(m2,"m2");
   vmaOps.mAdd(m3, m1, m2);
   vmaOps.sOps.printMatrix(m3,"m3=m1+m2");
   vmaOps.mSub(m3, m1, m2);
   vmaOps.sOps.printMatrix(m3,"m3=m1-m2");
   vmaOps.mSet123(m1);
   vmaOps.mSet123(m2);
   vmaOps.sOps.printMatrix(m1,"m1");
   vmaOps.sOps.printMatrix(m2,"m2");
   vmaOps.mMult(m3, m1, m2);
   vmaOps.sOps.printMatrix(m3,"m3=m1*m2");
   vmaOps.mTran(m1, m3);
   vmaOps.sOps.printMatrix(m1,"Tanspose of m3");
   vmaOps.mSetIdentity(m1);
   vmaOps.mSetIdentity(m2);
   vmaOps.ScaXMat(m2,2,m2);
   vmaOps.sOps.printMatrix(m1,"m1");
   vmaOps.sOps.printMatrix(m2,"m2");
   vmaOps.mTrace(&s1, m1);
   vmaOps.mTrace(&s2, m2);
   vmaOps.sOps.printScalar(s1,"Trace of m1");
   vmaOps.sOps.printScalar(s2,"Trace of m2");
   m4[0][0]=6; m4[0][1]=1;  m4[0][2]=1;
   m4[1][0]=4; m4[1][1]=-2; m4[1][2]=5;
   m4[2][0]=2; m4[2][1]=8;  m4[2][2]=7;
   vmaOps.sOps.printMatrix(m4,"m4");
   vmaOps.mDet33(&det, m4);
   vmaOps.sOps.printScalar(det,"det(m4) should be -306. det(m4) is:");
   vmaOps.mSet123(m4);
   vmaOps.sOps.printMatrix(m4,"m4");
   printf("Check Inverse (m4) [123 Matrix is NOT invertible: Shouldn't Work]\n");
   vmaOps.mInv(m3,m4);
   m4[0][0]=3; m4[0][1]=0;  m4[0][2]=2;
   m4[1][0]=2; m4[1][1]=0;  m4[1][2]=-2;
   m4[2][0]=0; m4[2][1]=1;  m4[2][2]=1;
   vmaOps.sOps.printMatrix(m4,"m4");
   vmaOps.mMinor(m2,m4);
   vmaOps.sOps.printMatrix(m2,"Matrix of Minors of m4");
   vmaOps.mCofactor(m2,m4);
   vmaOps.sOps.printMatrix(m2,"Matrix of Cofactors of m4");
   vmaOps.mAdjugate(m2,m4);
   vmaOps.sOps.printMatrix(m2,"Adjoint of m4");
   vmaOps.mDet33(&det, m4);
   det=1/det;
   vmaOps.ScaXMat(m2,det,m2);
   vmaOps.sOps.printMatrix(m2,"Inverse from Adjoint/det of m4");   
   vmaOps.mInv(m3,m4);
   m2[0][0]=0.2;  m2[0][1]=0.2;   m2[0][2]=0;
   m2[1][0]=-0.2; m2[1][1]=0.3;   m2[1][2]=1;
   m2[2][0]=0.2;  m2[2][1]=-0.3;  m2[2][2]=0;
   vmaOps.sOps.printMatrix(m2,"m2 = inv(m4) [Actual]");
   vmaOps.sOps.printMatrix(m3,"m3 = inv(m4) [Calculated]");
   vmaOps.mIsEqual(&testIsE,m3,m2);

   printf("\narrayOps: Add, Subtract, Multiplication, Transpose, Det2X2\n");
   vmaOps.sOps.printArray(a1,"a1=2*Ones");
   vmaOps.sOps.printArray(a2,"a2");
   vmaOps.sOps.printArray(a4,"a4");
   printf("Check Add/Subtract (a1 & a4) [Different Dimensions: Shouldn't Work]\n");
   vmaOps.aAdd(a5,a1,a4);
   vmaOps.aSub(a5,a1,a4);
   vmaOps.aAdd(a3,a1,a2);
   vmaOps.sOps.printArray(a3,"a3=a1+a2");
   vmaOps.aSub(a3,a1,a2);
   vmaOps.sOps.printArray(a3,"a3=a1-a2");
   vmaOps.aSet123(a2);
   vmaOps.sOps.printArray(a2,"a2");
   vmaOps.aSet123(a4);
   vmaOps.sOps.printArray(a4,"a4");
   printf("Check Multiplication (a4 & a2) [nxm * nxn: Shouldn't Work]\n");
   vmaOps.aMult(a3,a4,a2);
   vmaOps.aMult(a3,a2,a4);
   vmaOps.sOps.printArray(a3,"a3=a2*a4");
   vmaOps.aTran(a5,a4);
   vmaOps.sOps.printArray(a5,"Transpose of a4");
   get<0>(a6)[0][0]=1; get<0>(a6)[0][1]=2; get<0>(a6)[1][0]=3; get<0>(a6)[1][1]=4;
   vmaOps.sOps.printArray(a6,"a6");
   vmaOps.mDet22(&det, get<0>(a6));
   vmaOps.sOps.printScalar(det,"det(a6) is:");

   printf("\nENDING OPS TESTS\n\n");

   // RUN FREE TESTS

   printf("STARTING FREE TESTS\n\n");

   printf("Freeing matricies m[1-4]\n");
   vmaOps.mFree(m1);
   vmaOps.mFree(m2);
   vmaOps.mFree(m3);
   vmaOps.mFree(m4);

   printf("Freeing arrays a[1-6]\n");
   vmaOps.aFree(a1);
   vmaOps.aFree(a2);
   vmaOps.aFree(a3);
   vmaOps.aFree(a4);
   vmaOps.aFree(a5);
   vmaOps.aFree(a6);

   printf("\nENDING FREE TESTS\n\n");

   return 0;
}
