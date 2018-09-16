// Filename: circuitComponents.h
// Created: 07/29/2018
// Last Modified: 07/29/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class resistor {
   protected:
   private:
   double resistance;
   double tolerance;
   public:
   double voltage;
   double current;

   resistor(double r, double tol)
   {
      cout << "Constucting resistor: " ;
      resistance = r;
      tolerance = tol;
      cout << "Resistance = " << resistance << " Ohms ";
      cout << "Tolerance = +-" << tolerance << "%\n";
   }

   void printInfo()
   {
      cout << "This is the resistor class!\n";
   }

   void printResistance()
   {
      cout << "Resistance = " << resistance << " Ohms\n";
   }
};

class powerDC {
   protected:
   private:
   double voltage;
   public:

   powerDC(double v)
   {
      cout << "Constucting powerDC: " ;
      voltage = v;
      cout << "Voltage = " << voltage << " Ohms ";
   }

   void printInfo()
   {
      cout << "This is the powerDC class!\n";
   }

   void printVoltage()
   {
      cout << "Voltage = " << voltage << " Volts\n";
   }
};
