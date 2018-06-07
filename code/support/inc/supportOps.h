// Filename: supportOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include <stdio.h>
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
   FILE * fileWrite;
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
   void rCompOut();

   // TODO writeOps Functions

   void wDppArray2Csv(tuple<double**,int,int> arr, string fileName);

   void printInfo()
   {
      printf("This is the supportOps class!\n");
   }


};
