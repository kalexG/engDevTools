//--------------------------
// Filename: matrixOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/mvOps.h"

// Array Initialization
// Inputs: None
// Outputs: m
// Operation: Allocate Memory

myArray mvOps::aInit(int row, int col)
{
   a = new double *[row];

   for (int i=0;i<row;i++)
   {
      a[i]= new double[col];
   }

   for (int i=0;i<row;i++)
   {
      for (int j=0;j<col;j++)
      {
         a[i][j]=0;
      }
   }

   return make_tuple(a,row,col);
}

// Array Free
// Inputs: aFree
// Outputs: aFree
// Operation: Free Memory

void mvOps::aFree(myArray aFree)
{
   for (int i=0;i<get<1>(aFree);i++)
   {
      delete[] get<0>(aFree)[i];
   }
   
   delete[] get<0>(aFree);
}

// Set Array to Zeros
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Zeros

void mvOps::aSetZeros(myArray aOut)
{
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=0;
      }
   }
}

// Set Array to Ones
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Ones

void mvOps::aSetOnes(myArray aOut)
{
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=1;
      }
   }
}

// Set Matrix to Identity
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Identity

void mvOps::aSetIdentity(myArray aOut)
{
   if ( (get<1>(aOut) != get<2>(aOut)) )
   {
   printf("Error: Array needs to be square to have identity matrix (nxn)\n");
   return;
   }

   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         if (i==j)
         {
            get<0>(aOut)[i][j]=1;
         }
         else
         {
            get<0>(aOut)[i][j]=0;
         }
      }
   }
}

// Array Addition
// Inputs: a1, a2
// Outputs: aOut
// Operation: aOut=a1+a2

void mvOps::aAdd(myArray aOut, myArray a1, myArray a2)
{
   if ((get<1>(a1) != get<1>(a2)) || (get<2>(a1) != get<2>(a2)))
   {
   printf("Error: Array dimensions must be the equivalent for Addition\n");
   return;
   }

   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         get<0>(aOut)[i][j]=get<0>(a1)[i][j]+get<0>(a2)[i][j];
      }
   }
}

// Array Subtraction
// Inputs: a1, a2
// Outputs: aOut
// Operation: aOut=a1-a2

void mvOps::aSub(myArray aOut, myArray a1, myArray a2)
{
   if ((get<1>(a1) != get<1>(a2)) || (get<2>(a1) != get<2>(a2)))
   {
   printf("Error: Array dimensions must be the equivalent for Subtraction\n");
   return;
   }

   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         get<0>(aOut)[i][j]=get<0>(a1)[i][j]-get<0>(a2)[i][j];
      }
   }
}

// Array Multiplication [NOT DONE]
// Inputs: a1, a2
// Outputs: aOut
// Operation: aOut=a1*a2

void mvOps::aMult(double** aOut, double** a1, double** a2)
{
   // Make sure new array starts out empty
   //aSetZeros(aOut);

   for (int k=0;k<3;k++)
   {
      for(int i=0;i<3;i++)
      {
         for (int j=0;j<3;j++)
         {
            aOut[k][i]=aOut[k][i]+a1[k][j]*a2[j][i];
         }
      }
   }
}

// Scalar * Array
// Inputs: s1, a1
// Outputs: aOut
// Operation: s1*a1=aOut

void mvOps::aScaXArr(myArray aOut, double s1, myArray a1)
{
   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         get<0>(aOut)[i][j]=s1*get<0>(a1)[i][j];
      }
   }
}

// Array Transpose
// Inputs: s1, m1
// Outputs: mOut
// Operation: s1*m1=mOut

void mvOps::aTran(myArray aOut, myArray a1)
{
   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         get<0>(aOut)[j][i]=get<0>(a1)[i][j];
      }
   }
}

// Array isEqual [NOT DONE]
// Inputs: a1, a2
// Outputs: str1
// Operation: ?a1=a2?

void mvOps::aIsEqual(bool* isEqual, double** a1, double** a2)
{
   *isEqual=false;
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         if (a1[i][j]==a2[i][j])
         {
            *isEqual=true;
         }
         else
         {
            *isEqual=false;
            return;
         }
      }
   }
}
