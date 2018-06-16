// Filename: logicGates.h
// Created: 06/16/2018
// Last Modified: 06/16/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class NOTgate {
   protected:
   private:
   int out;
   public:
   int in1;
   void runNOTgate(int bin1, int* binOut);

   void printInfo()
   {
      cout << "This is the NOTgate class!\n";
   }
};

class ANDgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runANDgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class NANDgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runNANDgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class ORgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runORgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class NORgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runNORgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class XORgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runXORgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class XNORgate {
   protected:
   private:
   int out;
   public:
   int in1;
   int in2;
   void runXNORgate(int bin1, int bin2, int* binOut);

   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};
