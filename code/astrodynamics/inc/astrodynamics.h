// Filename: astrodynamics.h
// Created: 03/31/2018
// Last Modified: 03/31/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
// Defines:
#define pi 3.141592653589793
#define G 0.0000000000667408 // (m^3)(kg^-1)(s^-2)
using namespace std;

class twoBodyOrbitalMech {

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
   double Fg[3]; // Force: gravity
   // Functions: public

   void newtonLawOfG(double* Fg, double m1, double m2, double r_mag, double* r);

   void printInfo()
   {
      cout << "This is the astrodynamics class!\n";
   }

   void printDefines()
   {
      cout << "pi = " << pi << "\n";
      cout << "G = " << G << "\n";
   }

   void printVector(double* vector)
   {
      int i;
      printf("[%f, %f, %f]\n", vector[0], vector[1], vector[2]);
   }

};
