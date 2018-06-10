// Filename: vmaOps.h
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include <memory>
#include "../../support/inc/prwOps.h"
using namespace std;
typedef tuple<double**,int,int> myArrayp2;
typedef tuple<double*,int,int> myArrayp1;
typedef shared_ptr<myArrayp1> myArraySp1;

class arrayOpsOptim {

   // Access: protected //
   protected:
   // Data: protected
   // Functions: protected

   // Access: private //
   private:
   // Data: private
   double** a; // For initialization (See aInit)
   // Functions: private

   // Access: public
   public:
   // Data: public

   // Classes: public
   class prwOps prwOps;
   // Functions: public

   // TODO arrayOps Functions
   myArrayp2 aInit_1(int row, int col);
   void aFree_1(myArrayp2 aFree);
   void aSetZeros_1(myArrayp2 aOut);
   void aSetOnes_1(myArrayp2 aOut);
   void aSet123_1(myArrayp2 aOut);
   void aMatMat_1(myArrayp2 aOut, myArrayp2 a1, myArrayp2 a2);

//   void aInit_2(myArrayp1* aIn, int row, int col);
//   void aFree_2(myArrayp1* aFree);
   void aSetZeros_2(myArrayp2 aOut);
   void aSetOnes_2(myArrayp2 aOut);
   void aSet123_2(myArrayp2 aOut);
   void aMatMat_2(myArrayp2 aOut, myArrayp2 a1, myArrayp2 a2);

   void printInfo()
   {
      printf("This is the arrayOpsOptim class!\n");
   }

};
