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

myArray vmaOps::aInit(int row, int col)
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

void vmaOps::aFree(myArray aFree)
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

void vmaOps::aSetZeros(myArray aOut)
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

void vmaOps::aSetOnes(myArray aOut)
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

void vmaOps::aSetIdentity(myArray aOut)
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

void vmaOps::aAdd(myArray aOut, myArray a1, myArray a2)
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

void vmaOps::aSub(myArray aOut, myArray a1, myArray a2)
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

void vmaOps::aMult(myArray aOut, myArray a1, myArray a2)
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

void vmaOps::aScaXArr(myArray aOut, double s1, myArray a1)
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

void vmaOps::aTran(myArray aOut, myArray a1)
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

void vmaOps::aIsEqual(bool* isEqual, myArray a1, myArray a2)
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
