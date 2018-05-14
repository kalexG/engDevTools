// Filename: vectorOps.h
// Created: 04/07/2018
// Last Modified: 04/07/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class vectorOps {

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

   void vAdd(double* vOut, double* v1, double* v2);
   void vSub(double* vOut, double* v1, double* v2);
   void vMag(double* sOut, double* v1);
   void vUnit(double* vOut, double* v1);
   void crossProduct(double* vOut, double* v1, double* v2);
   void dotProduct(double* sOut, double* v1, double* v2);

   void printInfo()
   {
      cout << "This is the vectorOps class!\n";
   }

   void printVector(double* vector)
   {
      printf("[%f, %f, %f]\n", vector[0], vector[1], vector[2]);
   }

};
