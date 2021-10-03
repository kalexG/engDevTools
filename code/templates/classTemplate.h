// Filename: classTemplate.h
// Created: XX/XX/XXXX
// Last Modified: XX/XX/XXXX
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class classTemplate {

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

   void printInfo()
   {
      cout << "This is the classTemplate class!\n";
   }

   void printVector(double* vector)
   {
      printf("[%f, %f, %f]\n", vector[0], vector[1], vector[2]);
   }

   void printMatrix(double** matrix)
   {
      printf("|%f %f %f|\n|%f %f %f|\n|%f %f %f|\n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
   }

};
