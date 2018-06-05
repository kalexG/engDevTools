// Filename: vmaOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include "../../support/inc/supportOps.h"
using namespace std;
typedef tuple<double**,int,int> myArray;

class vmaOps {

   // Access: protected //
   protected:
   // Data: protected
   // Functions: protected

   // Access: private //
   private:
   // Data: private
   double** m;
   double** a;
   double tol=1.0e-10; // Tolerance Criteria
   bool wiTol; // Within Tolerance Flag
   // Functions: private

   // Access: public
   public:
   // Data: public

   // Classes: public
   supportOps sOps;
   // Functions: public

   // vectorOps Functions
   void vSetZeros(double* vOut);
   void vSetOnes(double* vOut);
   void vSet123(double* vOut);
   void vAdd(double* vOut, double* v1, double* v2);
   void vSub(double* vOut, double* v1, double* v2);
   void vMag(double* sOut, double* v1);
   void vUnit(double* vOut, double* v1);
   void crossProduct(double* vOut, double* v1, double* v2);
   void dotProduct(double* sOut, double* v1, double* v2);
   void vIsEqual(bool* isEqual, double* v1, double* v2);
   void ScaXVec(double* vOut, double s1, double* v1);
   // TODO: Vector Initialization

   // matrixOps Functions
   double** mInit(void);
   void mFree(double** mFree);
   void mSetZeros(double** mOut);
   void mSetOnes(double** mOut);
   void mSet123(double** mOut);
   void mSetIdentity(double** mOut);
   void mAdd(double** mOut, double** m1, double** m2);
   void mSub(double** mOut, double** m1, double** m2);
   void mMult(double** mOut, double** m1, double** m2);
   void mTrace(double* sOut, double** m1);
   void ScaXMat(double** mOut, double s1, double** m1);
   void mTran(double** mOut, double** m1);
   void mIsEqual(bool* isEqual, double** m1, double** m2);
   void mDet33(double* sOut, double** m1);
   void mMinor(double** mOut, double** m1);
   void mCofactor(double** mOut, double** m1);
   void mAdjugate(double** mOut, double** m1);
   void mInv(double** mOut, double** m1);
   // TODO: Vector*Matrix
   // TODO: Matrix*Vector
   
   // TODO arrayOps Functions
   myArray aInit(int row, int col);
   void aFree(myArray aFree);
   void aSetZeros(myArray aOut);
   void aSetOnes(myArray aOut);
   void aSet123(myArray aOut);
   void aSetIdentity(myArray aOut);
   void aAdd(myArray aOut, myArray a1, myArray a2);
   void aSub(myArray aOut, myArray a1, myArray a2);
   void aMult(myArray aOut, myArray a1, myArray a2);
   void ScaXArr(myArray aOut, double s1, myArray a1);
   void aTran(myArray aOut, myArray a1);
   void aIsEqual(bool* isEqual, myArray a1, myArray a2);
   void mDet22(double* sOut, double** m1);

   void printInfo()
   {
      printf("This is the vmaOps class!\n");
   }

};
