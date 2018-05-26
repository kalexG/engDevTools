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
   // TODO: Vector Initialization
   // TODO: Scalar * Vector

   // matrixOps Functions
   double** mInit(void);
   void mSetZeros(double** mOut);
   void mSetOnes(double** mOut);
   void mSet123(double** mOut);
   void mSetIdentity(double** mOut);
   void mAdd(double** mOut, double** m1, double** m2);
   void mSub(double** mOut, double** m1, double** m2);
   void mMult(double** mOut, double** m1, double** m2);
   void mTrace(double* sOut, double** m1);
   void mScaXMat(double** mOut, double s1, double** m1);
   void mTran(double** mOut, double** m1);
   void mIsEqual(bool* isEqual, double** m1, double** m2);
   void mDet33(double* sOut, double** m1);
   // TODO: Inverse
   // TODO: Adjugate
   // TODO: Cofactor
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
   void aMult(myArray aOut, myArray a1, myArray a2); // [NOT DONE]
   void aScaXArr(myArray aOut, double s1, myArray a1);
   void aTran(myArray aOut, myArray a1);
   void aIsEqual(bool* isEqual, myArray a1, myArray a2);
   void mDet22(double* sOut, double** m1);

   void printInfo()
   {
      printf("This is the vmaOps class!\n");
   }

   // TODO:
   // 1. Maybe add a string input to all these functions to allow for putting in the variable name
   // 2. Move these into standard library

   /*void printBool(bool boolean, string str1 = "")
   {
      if (str1.empty())
      {
         printf(">>>\n");
      }
      else
      {
         printf(">>> %s\n",str1.c_str());
      }
      printf("%s\n", boolean ? "True" : "False");
   }

   void printScalar(double scalar, string str1 = "")
   {
      if (str1.empty())
      {
         printf(">>>\n");
      }
      else
      {
         printf(">>> %s\n",str1.c_str());
      }
      printf("%f\n", scalar);
   }

   void printVector(double* vector, string str1 = "")
   {
      if (str1.empty())
      {
         printf(">>>\n");
      }
      else
      {
         printf(">>> %s\n",str1.c_str());
      }
      printf("| %f %f %f |\n", vector[0], vector[1], vector[2]);
   }

   void printMatrix(double** matrix, string str1 = "")
   {
      if (str1.empty())
      {
         printf(">>>\n");
      }
      else
      {
         printf(">>> %s\n",str1.c_str());
      }
      printf("| %f %f %f |\n", matrix[0][0], matrix[0][1], matrix[0][2]);
      printf("| %f %f %f |\n", matrix[1][0], matrix[1][1], matrix[1][2]);
      printf("| %f %f %f |\n", matrix[2][0], matrix[2][1], matrix[2][2]);
   }

   void printArray(myArray arr, string str1 = "")
   {
      if (str1.empty())
      {
         printf(">>>\n");
      }
      else
      {
         printf(">>> %s\n",str1.c_str());
      }

      for (int i=0;i<get<1>(arr);i++)
      {
         printf("| ");
         for(int j=0;j<get<2>(arr);j++)
         {
            printf("%f ",get<0>(arr)[i][j]);
         }
         printf("|\n");
      }
   }*/

};
