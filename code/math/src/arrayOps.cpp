//--------------------------
// Filename: matrixOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/vmaOps.h"

// Array Initialization
// Inputs: None
// Outputs: m
// Operation: Allocate Memory

void vmaOps::aInit(arr* aInit, int row, int col)
{

   get<1>(*aInit) = row;
   get<2>(*aInit) = col;

   get<0>(*aInit) = new double *[row];

   for (int i=0;i<row;i++)
   {
      (get<0>(*aInit))[i]= new double[col];
   }

   for (int i=0;i<row;i++)
   {
      for (int j=0;j<col;j++)
      {
         (get<0>(*aInit))[i][j]=0;
      }
   }

   aSetZeros(*aInit);

}

// Array Free
// Inputs: aFree
// Outputs: aFree
// Operation: Free Memory

void vmaOps::aFree(arr* aFree)
{
   for (int i=0;i<get<1>(*aFree);i++)
   {
      delete[] get<0>(*aFree)[i];
   }
   
   delete[] get<0>(*aFree);
   get<0>(*aFree)=NULL;
   get<1>(*aFree)=0;
   get<2>(*aFree)=0;
}

// Set Array to Zeros
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Zeros

void vmaOps::aSetZeros(arr aOut)
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

void vmaOps::aSetOnes(arr aOut)
{
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=1;
      }
   }
}

// Set Array to 123
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=123

void vmaOps::aSet123(arr aOut)
{
   int k=1;
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=k;
         k++;
      }
   }
}

// Set Matrix to Identity
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Identity

void vmaOps::aSetIdentity(arr aOut)
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

void vmaOps::aAdd(arr aOut, arr a1, arr a2)
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

void vmaOps::aSub(arr aOut, arr a1, arr a2)
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

void vmaOps::aMult(arr aOut, arr a1, arr a2)
{
   // Make sure new array starts out empty

   if ( get<2>(a1) != get<1>(a2) )
   {
   printf("Error: Number of columns of array 1 must equal number of rows of array 2\n");
   return;
   }

   aSetZeros(aOut);

   for (int k=0;k<get<1>(a1);k++)
   {
      for(int i=0;i<get<2>(a2);i++)
      {
         for (int j=0;j<get<2>(a1);j++)
         {
            get<0>(aOut)[k][i]=get<0>(aOut)[k][i]+get<0>(a1)[k][j]*get<0>(a2)[j][i];
         }
      }
   }
}

// Scalar * Array
// Inputs: s1, a1
// Outputs: aOut
// Operation: s1*a1=aOut

void vmaOps::ScaXArr(arr aOut, double s1, arr a1)
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

void vmaOps::aTran(arr aOut, arr a1)
{
   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         get<0>(aOut)[j][i]=get<0>(a1)[i][j];
      }
   }
}

// Array isEqual
// Inputs: a1, a2
// Outputs: str1
// Operation: ?a1=a2?

void vmaOps::aIsEqual(bool* isEqual, arr a1, arr a2)
{
   *isEqual=false;

   if ((get<1>(a1) != get<1>(a2)) || (get<2>(a1) != get<2>(a2)))
   {
   printf("Error: Array dimensions are not the same\n");
   return;
   }

   for(int i=0;i<get<1>(a1);i++)
   {
      for (int j=0;j<get<2>(a1);j++)
      {
         if (get<0>(a1)[i][j]==get<0>(a2)[i][j])
         {
            *isEqual=true;
         }
         else
         {
            *isEqual=false;
            printf("These arrays are NOT equal\n");
            return;
         }
      }
   }
   printf("These arrays are ARE equal\n");
}

// Matrix Determinant (2x2) 
// Inputs: m1
// Outputs: sOut
// Operation: Dterminant of 2x2 matrix

void vmaOps::mDet22(double* sOut, double** m1)
{
   *sOut=m1[0][0]*m1[1][1]-m1[0][1]*m1[1][0];
}

