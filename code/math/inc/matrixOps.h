// Filename: matrixOps.h
// Created: 04/21/2018
// Last Modified: 04/21/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/vectorOps.h"

class matrixOps {

   // Access: protected //
   protected:
   // Data: protected
   // Functions: protected

   // Access: private //
   private:
   // Data: private
   double** m;
   double** m_tmp;
   double tmp;
   // Functions: private

   // Access: public
   public:
   // Data: public
   // Functions: public

   double** mInit(void);
   void mSetZeros(double** mOut);
   void mSetIdentity(double** mOut);
   void mAdd(double** mOut, double** m1, double** m2);
   void mSub(double** mOut, double** m1, double** m2);
   void mMult(double** mOut, double** m1, double** m2);
   void mTrace(double s1, double** m1);
   // TODO: Inverse
   // TODO: Transpose
   // TODO: Determinant
   // TODO: Adjugate
   // TODO: IsEqual

   void printInfo()
   {
      printf("This is the matrixOps class!\n");
   }

   void printVector(double* vector)
   {
      printf("[%f, %f, %f]\n", vector[0], vector[1], vector[2]);
   }

   void printMatrix(double** matrix)
   {
      printf("|%f %f %f|\n", matrix[0][0], matrix[0][1], matrix[0][2]);
      printf("|%f %f %f|\n", matrix[1][0], matrix[1][1], matrix[1][2]);
      printf("|%f %f %f|\n", matrix[2][0], matrix[2][1], matrix[2][2]);
   }

};
