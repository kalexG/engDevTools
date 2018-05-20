// Filename: mvOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class mvOps {

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
   bool isEqual;
   string str_tmp;
   // Functions: private

   // Access: public
   public:
   // Data: public
   // Functions: public

   // vectorOps Functions
   void vAdd(double* vOut, double* v1, double* v2);
   void vSub(double* vOut, double* v1, double* v2);
   void vMag(double* sOut, double* v1);
   void vUnit(double* vOut, double* v1);
   void crossProduct(double* vOut, double* v1, double* v2);
   void dotProduct(double* sOut, double* v1, double* v2);
   // TODO: Vector isEqual
   // TODO: Vector Initialization

   // matrixOps Functions
   double** mInit(void);
   void mSetZeros(double** mOut);
   void mSetIdentity(double** mOut);
   void mAdd(double** mOut, double** m1, double** m2);
   void mSub(double** mOut, double** m1, double** m2);
   void mMult(double** mOut, double** m1, double** m2);
   void mTrace(double* sOut, double** m1);
   void mScaXMat(double** mOut, double s1, double** m1);
   void mTran(double** mOut, double** m1);
   void misEqual(bool* isEqual, double** m1, double** m2);
   // TODO: Inverse
   // TODO: Determinant
   // TODO: Adjugate
   // TODO: Vector*Matrix
   // TODO: Matrix*Vector
   
   // TODO arrayOps Functions

   void printInfo()
   {
      printf("This is the mvOps class!\n");
   }

   // TODO:
   // 1. Maybe add a string input to all these functions to allow for putting in the variable name
   // 2. Move these into standard library

   void printBool(bool boolean, string str1 = "")
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
      printf("[%f, %f, %f]\n", vector[0], vector[1], vector[2]);
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
      printf("|%f %f %f|\n", matrix[0][0], matrix[0][1], matrix[0][2]);
      printf("|%f %f %f|\n", matrix[1][0], matrix[1][1], matrix[1][2]);
      printf("|%f %f %f|\n", matrix[2][0], matrix[2][1], matrix[2][2]);
   }

};
