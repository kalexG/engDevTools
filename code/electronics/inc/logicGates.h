// Filename: logicGates.h
// Created: 06/16/2018
// Last Modified: 06/16/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class logicGate {
   protected:
   private:
   public:
   int in1, in2, out;

   logicGate()
   {
      cout << "Constucting logic gate: ";
   }

   void printInfo()
   {
      cout << "This is the logicGate class!\n";
   }
};

class NOTgate : public logicGate {
   protected:
   private:
   public:

   void runNOTgate(int bin1, int* binOut);

   NOTgate()
   {
      cout << "NOT gate\n";
   }

   void printInfo()
   {
      cout << "This is the NOTgate class!\n";
   }
};

class ANDgate : public logicGate {
   protected:
   private:
   public:

   void runANDgate(int bin1, int bin2, int* binOut);

   ANDgate()
   {
      cout << "AND gate\n";
   }


   void printInfo()
   {
      cout << "This is the ANDgate class!\n";
   }
};

class NANDgate : public logicGate {
   protected:
   private:
   public:

   void runNANDgate(int bin1, int bin2, int* binOut);

   NANDgate()
   {
      cout << "NAND gate\n";
   }


   void printInfo()
   {
      cout << "This is the NANDgate class!\n";
   }
};

class ORgate : public logicGate {
   protected:
   private:
   public:

   void runORgate(int bin1, int bin2, int* binOut);

   ORgate()
   {
      cout << "OR gate\n";
   }


   void printInfo()
   {
      cout << "This is the ORgate class!\n";
   }
};

class NORgate : public logicGate {
   protected:
   private:
   public:

   void runNORgate(int bin1, int bin2, int* binOut);

   NORgate()
   {
      cout << "NOR gate\n";
   }


   void printInfo()
   {
      cout << "This is the NORgate class!\n";
   }
};

class XORgate : public logicGate {
   protected:
   private:
   public:

   void runXORgate(int bin1, int bin2, int* binOut);

   XORgate()
   {
      cout << "XOR gate\n";
   }


   void printInfo()
   {
      cout << "This is the XORgate class!\n";
   }
};

class XNORgate : public logicGate {
   protected:
   private:
   public:

   void runXNORgate(int bin1, int bin2, int* binOut);

   XNORgate()
   {
      cout << "XNOR gate\n";
   }


   void printInfo()
   {
      cout << "This is the XNORgate class!\n";
   }
};
