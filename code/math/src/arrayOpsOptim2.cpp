//--------------------------
// Filename: arrayOpsOptim.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/arrayOpsOptim.h"

// Array Initialization [Version2]
// Inputs: None
// Outputs: m
// Operation: Allocate Memory

/*void arrayOpsOptim::aInit_2(myArrayp1* aInit, int row, int col)
{
   int ele = row*col;

   get<0>(aInit) = new double [ele];

   for (int i=0;i<ele;i++)
   {
      get<0>(aInit)[i]=0;
   }

   get<1>(aInit)=row;
   get<2>(aInit)=col;
   //return make_tuple(a,row,col);
}

// Array Free [Version1]
// Inputs: aFree
// Outputs: aFree
// Operation: Free Memory

void arrayOpsOptim::aFree_2(myArrayp1* aFree)
{
   delete[] get<0>(aFree);
   get<0>(aFree)=NULL;
} */

// Set Array to Zeros [Version1]
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Zeros

void arrayOpsOptim::aSetZeros_2(myArrayp2 aOut)
{
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=0;
      }
   }
}

// Set Array to Ones [Version1]
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=Ones

void arrayOpsOptim::aSetOnes_2(myArrayp2 aOut)
{
   for (int i=0;i<get<1>(aOut);i++)
   {
      for(int j=0;j<get<2>(aOut);j++)
      {
         get<0>(aOut)[i][j]=1;
      }
   }
}

// Set Array to 123 [Version1]
// Inputs: aOut
// Outputs: aOut
// Operation: aOut=123

void arrayOpsOptim::aSet123_2(myArrayp2 aOut)
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

// Array Multiplication [Version2] [NOT DONE]
// Changes: 
// 1. Use single pointers instead of double pointers
// Inputs: a1, a2
// Outputs: aOut
// Operation: aOut=a1*a2

void arrayOpsOptim::aMatMat_2(myArrayp2 aOut, myArrayp2 a1, myArrayp2 a2)
{
   // Make sure new array starts out empty

   if ( get<2>(a1) != get<1>(a2) )
   {
   printf("Error: Number of columns of array 1 must equal number of rows of array 2\n");
   return;
   }

   aSetZeros_2(aOut);

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
