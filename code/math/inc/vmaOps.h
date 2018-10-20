// Filename: vmaOps.h
// Created: 05/19/2018
// Last Modified: 10/08/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include <typeinfo>
using namespace std;
typedef tuple<double**,int,int> arr;
typedef double** mat;
typedef double* vec;

class vmaOps 
{

   protected:

   private:

   public:

   class myArr
   {
      protected:
      private:
      public:
   };

   class myMat : public myArr
   {
      protected:
      private:
      public:
   };

   class myVec : public myArr
   {
      protected:
      private:
      public:
   };

   // vectorOps Functions
   static void vInit(double** vInit);
   static void vFree(double** vFree);
   static void vSetZeros(vec vOut);
   static void vSetOnes(vec vOut);
   static void vSet123(vec vOut);
   static void vAdd(vec vOut, vec v1, vec v2);
   static void vSub(vec vOut, vec v1, vec v2);
   static void vMag(double* sOut, vec v1);
   static void vUnit(vec vOut, vec v1);
   static void crossProduct(vec vOut, vec v1, vec v2);
   static void dotProduct(double* sOut, vec v1, vec v2);
   static void vIsEqual(bool* isEqual, vec v1, vec v2);
   static void ScaXVec(vec vOut, double s1, vec v1);

   // matrixOps Functions
   static void mInit(double*** mInit);
   static void mFree(double*** mFree);
   static void mSetZeros(mat mOut);
   static void mSetOnes(mat mOut);
   static void mSet123(mat mOut);
   static void mSetIdentity(mat mOut);
   static void mAdd(mat mOut, mat m1, mat m2);
   static void mSub(mat mOut, mat m1, mat m2);
   static void mMult(mat mOut, mat m1, mat m2);
   static void mTrace(double* sOut, mat m1);
   static void ScaXMat(mat mOut, double s1, mat m1);
   static void mTran(mat mOut, mat m1);
   static void mIsEqual(bool* isEqual, mat m1, mat m2);
   static void mDet33(double* sOut, mat m1);
   static void mMinor(mat mOut, mat m1);
   static void mCofactor(mat mOut, mat m1);
   static void mAdjugate(mat mOut, mat m1);
   static void mInv(mat mOut, mat m1);
   // TODO: Vector*Matrix
   // TODO: Matrix*Vector
   
   // TODO arrayOps Functions
   static void aInit(arr* aInit, int row, int col);
   static void aFree(arr* aFree);
   static void aSetZeros(arr aOut);
   static void aSetOnes(arr aOut);
   static void aSet123(arr aOut);
   static void aSetIdentity(arr aOut);
   static void aAdd(arr aOut, arr a1, arr a2);
   static void aSub(arr aOut, arr a1, arr a2);
   static void aMult(arr aOut, arr a1, arr a2);
   static void ScaXArr(arr aOut, double s1, arr a1);
   static void aTran(arr aOut, arr a1);
   static void aIsEqual(bool* isEqual, arr a1, arr a2);
   static void mDet22(double* sOut, double** m1);

};
