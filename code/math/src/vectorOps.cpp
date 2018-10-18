//--------------------------
// Filename: vectorOps.cpp
// Created: 04/07/2018
// Last Modified: 04/07/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/vmaOps.h"

// Set Vector to Zeros
// Inputs: vOut
// Outputs: vOut
// Operation: vOut=Zeros

void vmaOps::vSetZeros(double* vOut)
{
   vOut[0]=0;
   vOut[1]=0;
   vOut[2]=0;
}

// Set Vector to Ones
// Inputs: vOut
// Outputs: vOut
// Operation: vOut=Ones

void vmaOps::vSetOnes(double* vOut)
{
   vOut[0]=1;
   vOut[1]=1;
   vOut[2]=1;
}

// Set Vector to 123
// Inputs: vOut
// Outputs: vOut
// Operation: vOut=123

void vmaOps::vSet123(double* vOut)
{
   vOut[0]=1;
   vOut[1]=2;
   vOut[2]=3;
}

// Vector Addition
// Inputs: v1, v2
// Outputs: vOut
// Operation: vOut=v1+v2

void vmaOps::vAdd(double* vOut, double* v1, double* v2)
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

void vmaOps::vSub(double* vOut, double* v1, double* v2)
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

void vmaOps::vMag(double* sOut, double* v1)
{
   *sOut=sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);
}

// Unit Vector
// Inputs: v1
// Outputs: vOut
// Operation: vOut=v1/mag(v1)

void vmaOps::vUnit(double* vOut, double* v1)
{
   double mag;
   vMag(&mag, v1);
   for(int i=0;i<3;i++)
   {
      vOut[i]=v1[i]/mag;
   }
}

// Cross Product
// Inputs: v1, v2
// Outputs: vOut
// Operation: vOut=v1xv2

void vmaOps::crossProduct(double* vOut, double* v1, double* v2)
{
   vOut[0] = v1[1]*v2[2]-v1[2]*v2[1];
   vOut[1] = v1[2]*v2[0]-v1[0]*v2[2];
   vOut[2] = v1[0]*v2[1]-v1[1]*v2[0];
}

// Dot Product
// Inputs: v1, v2
// Outputs: sOut
// Operation: sOut=v1.v2

void vmaOps::dotProduct(double* sOut, double* v1, double* v2)
{
   *sOut = v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
}

// Vector isEqual
// Inputs: m1, m2
// Outputs: str1
// Operation: ?m1=m2?

void vmaOps::vIsEqual(bool* isEqual, double* v1, double* v2)
{
   if (v1[0]==v2[0] && v1[1]==v2[1] && v1[2]==v2[2])
   {
      *isEqual=true;
   }
   else
   {
      *isEqual=false;
   }
}

void vmaOps::ScaXVec(double* vOut, double s1, double* v1)
{
   vOut[0]=s1*v1[0];
   vOut[1]=s1*v1[1];
   vOut[2]=s1*v1[2];
}
