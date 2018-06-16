// Filename: digitalLogic.cpp
// Created: 06/10/2018
// Last Modified: 06/10/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/logicGates.h"
using namespace std;

void NOTgate::runNOTgate(int bin1, int* binOut)
{
   *binOut = -bin1+1;
}

void ANDgate::runANDgate(int bin1, int bin2, int* binOut)
{
   *binOut = bin1*bin2;
}

void NANDgate::runNANDgate(int bin1, int bin2, int* binOut)
{
   int tmp1 = bin1*bin2;
   if (tmp1<1)
   {
      *binOut = 1;
   }
   else
   {
      *binOut = 0;
   }
}

void ORgate::runORgate(int bin1, int bin2, int* binOut)
{
   if (bin1>0 || bin2>0)
   {
      *binOut = 1;
   }
   else
   {
      *binOut=0;
   }
}

void NORgate::runNORgate(int bin1, int bin2, int* binOut)
{
   if (bin1>0 || bin2>0)
   {
      *binOut = 0;
   }
   else
   {
      *binOut=1;
   }
}

void XORgate::runXORgate(int bin1, int bin2, int* binOut)
{
   if (bin1 == bin2)
   {
      *binOut=0;
   }
   else
   {
      *binOut=1;
   }
}

void XNORgate::runXNORgate(int bin1, int bin2, int* binOut)
{
   if (bin1 == bin2)
   {
      *binOut=1;
   }
   else
   {
      *binOut=0;
   }
}
