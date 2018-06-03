// Filename: supportOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
using namespace std;
typedef tuple<double**,int,int> myArray;

class supportOps {

   // Access: protected //
   protected:
   // Data: protected
   // Functions: protected

   // Access: private //
   private:
   // Data: private
   // Functions: private

   // Access: public
   public:
   // Data: public
   // Functions: public

   // printOps Functions
   void printBool(bool boolean, string str1);
   void printScalar(double scalar, string str1);
   void printVector(double* vector, string str1);
   void printMatrix(double** matrix, string str1);
   void printArray(myArray arr, string str1);

   // TODO readOps Functions

   // TODO writeOps Functions

   void wStdout();
   void wStdin();
   void wStderr();
   void wRecord();
   void wArray2Csv();

   void printInfo()
   {
      printf("This is the supportOps class!\n");
   }


};
