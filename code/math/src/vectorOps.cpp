//--------------------------
// Filename: vectorOps.cpp
// Created: 04/07/2018
// Last Modified: 04/07/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/vectorOps.h"

// Vector Addition
// Inputs: v1, v2
// Outputs: vOut
// Operation: vOut=v1+v2

void vectorOps::vAdd(double* vOut, double* v1, double* v2)
{
   for(int i=0;i<3;i++)
   {
      vOut[i]=v1[i]+v2[i];
   }
}

// Vector Subtraction
// Inputs: v1, v2
// Outputs: vOut
// Operation: vOut=v1-v2

void vectorOps::vSub(double* vOut, double* v1, double* v2)
{
   for(int i=0;i<3;i++)
   {
      vOut[i]=v1[i]-v2[i];
   }
}

// Vector Magnitude
// Inputs: v1
// Outputs: sOut
// Operation: sOut=mag(v1)

void vectorOps::vMag(double* sOut, double* v1)
{
   *sOut=sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);
}

// Unit Vector
// Inputs: v1
// Outputs: vOut
// Operation: vOut=v1/mag(v1)

void vectorOps::vUnit(double* vOut, double* v1)
{
   for(int i=0;i<3;i++)
   {
      vOut[i]=v1[i]/sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);
   }
}

// Cross Product
// Inputs: v1, v2
// Outputs: vOut
// Operation: vOut=v1xv2

void vectorOps::crossProduct(double* vOut, double* v1, double* v2)
{
   vOut[0] = v1[1]*v2[2]-v1[2]*v2[1];
   vOut[1] = v1[2]*v2[0]-v1[0]*v2[2];
   vOut[2] = v1[0]*v2[1]-v1[1]*v2[0];
}

// Dot Product
// Inputs: v1, v2
// Outputs: sOut
// Operation: sOut=v1.v2

void vectorOps::dotProduct(double* sOut, double* v1, double* v2)
{
   *sOut = v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}
