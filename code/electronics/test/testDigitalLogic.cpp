// Filename: testDigitalLogic.cpp
// Created: 06/10/2018
// Last Modified: 06/10/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/logicGates.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for electronics!\n\n");

   // Creating logicGates objects
   NOTgate not1;
   ANDgate and1;
   NANDgate nand1;
   ORgate or1;
   NORgate nor1;
   XORgate xor1;
   XNORgate xnor1;

   // Declaring variables
   int b1, b2, b3;

   printf("STARTING OPS TESTS\n\n");

   // digitalLogic Gates testing
   b1=0; b2=0;
   printf("In1=0 & In2=0\n");
   not1.runNOTgate(b1, &b3);
   printf("NOT gate Out: %d\n",b3);
   and1.runANDgate(b1, b2, &b3);
   printf("AND gate Out: %d\n",b3);
   nand1.runNANDgate(b1, b2, &b3);
   printf("NAND gate Out: %d\n",b3);
   or1.runORgate(b1, b2, &b3);
   printf("OR gate Out: %d\n",b3);
   nor1.runNORgate(b1, b2, &b3);
   printf("NOR gate Out: %d\n",b3);
   xor1.runXORgate(b1, b2, &b3);
   printf("XOR gate Out: %d\n",b3);
   xnor1.runXNORgate(b1, b2, &b3);
   printf("XNOR gate Out: %d\n",b3);
   b1=0; b2=1;
   printf("In1=0 & In2=1\n");
   not1.runNOTgate(b1, &b3);
   printf("NOT gate Out: %d\n",b3);
   and1.runANDgate(b1, b2, &b3);
   printf("AND gate Out: %d\n",b3);
   nand1.runNANDgate(b1, b2, &b3);
   printf("NAND gate Out: %d\n",b3);
   or1.runORgate(b1, b2, &b3);
   printf("OR gate Out: %d\n",b3);
   nor1.runNORgate(b1, b2, &b3);
   printf("NOR gate Out: %d\n",b3);
   xor1.runXORgate(b1, b2, &b3);
   printf("XOR gate Out: %d\n",b3);
   xnor1.runXNORgate(b1, b2, &b3);
   printf("XNOR gate Out: %d\n",b3);
   b1=1; b2=0;
   printf("In1=1 & In2=0\n");
   not1.runNOTgate(b1, &b3);
   printf("NOT gate Out: %d\n",b3);
   and1.runANDgate(b1, b2, &b3);
   printf("AND gate Out: %d\n",b3);
   nand1.runNANDgate(b1, b2, &b3);
   printf("NAND gate Out: %d\n",b3);
   or1.runORgate(b1, b2, &b3);
   printf("OR gate Out: %d\n",b3);
   nor1.runNORgate(b1, b2, &b3);
   printf("NOR gate Out: %d\n",b3);
   xor1.runXORgate(b1, b2, &b3);
   printf("XOR gate Out: %d\n",b3);
   xnor1.runXNORgate(b1, b2, &b3);
   printf("XNOR gate Out: %d\n",b3);
   b1=1; b2=1;
   printf("In1=1 & In2=1\n");
   not1.runNOTgate(b1, &b3);
   printf("NOT gate Out: %d\n",b3);
   and1.runANDgate(b1, b2, &b3);
   printf("AND gate Out: %d\n",b3);
   nand1.runNANDgate(b1, b2, &b3);
   printf("NAND gate Out: %d\n",b3);
   or1.runORgate(b1, b2, &b3);
   printf("OR gate Out: %d\n",b3);
   nor1.runNORgate(b1, b2, &b3);
   printf("NOR gate Out: %d\n",b3);
   xor1.runXORgate(b1, b2, &b3);
   printf("XOR gate Out: %d\n",b3);
   xnor1.runXNORgate(b1, b2, &b3);
   printf("XNOR gate Out: %d\n",b3);

   printf("\nENDING OPS TESTS\n\n");

   return 0;
}
