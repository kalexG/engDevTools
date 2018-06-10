// Filename: vmaOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include "../inc/vmaOps.h"
using namespace std;
typedef tuple<double**,int,int> myArray;

class numericalMethods {

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

   // Classes: public
   class vmaOps vmaOps;
   
   // Functions: public

   // Numerical Integration
   void integrate();

   // Numerical Differntiation
   void differentiate();

   void printInfo()
   {
      printf("This is the numericalMethods class!\n");
   }

};
