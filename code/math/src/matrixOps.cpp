//--------------------------
// Filename: matrixOps.cpp
// Created: 04/21/2018
// Last Modified: 04/21/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/matrixOps.h"

// Matrix Initialization
// Inputs

double** matrixOps::mInit(void)
{
   m = new double *[3];

   for (int i=0;i<3;i++)
   {
      m[i]= new double[3];
   }

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         m[i][j]=0;
      }
   }
   return m;
}

void matrixOps::mSetZeros(double** mOut)
{

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         mOut[i][j]=0;
      }
   }
}

void matrixOps::mSetIdentity(double** mOut)
{

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         if (i==j)
         {
            mOut[i][j]=1;
         }
         else
         {
            mOut[i][j]=0;
         }
      }
   }
}

// Matrix Addition
// Inputs: m1, m2
// Outputs: mOut
// Operation: mOut=m1+m2

void matrixOps::mAdd(double** mOut, double** m1, double** m2)
{
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         mOut[i][j]=m1[i][j]+m2[i][j];
      }
   }
}

// Matrix Subtraction
// Inputs: m1, m2
// Outputs: mOut
// Operation: mOut=m1-m2

void matrixOps::mSub(double** mOut, double** m1, double** m2)
{
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         mOut[i][j]=m1[i][j]-m2[i][j];
      }
   }
}

// Matrix Multiplication
// Inputs: m1, m2
// Outputs: mOut
// Operation: mOut=m1*m2

void matrixOps::mMult(double** mOut, double** m1, double** m2)
{
   // Make sure new matrix starts out empty
   mSetZeros(mOut);

   for (int k=0;k<3;k++)
   {
      for(int i=0;i<3;i++)
      {
         for (int j=0;j<3;j++)
         {
            mOut[k][i]=mOut[k][i]+m1[k][j]*m2[j][i];
         }
      }
   }
}

// Matrix Trace 
// Inputs: m1
// Outputs: s1
// Operation: Sum Diagonal of m1

void matrixOps::mTrace(double s1, double** m1)
{
   s1=m1[0][0]+m1[1][1]+m1[2][2];
}
