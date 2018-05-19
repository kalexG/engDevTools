//--------------------------
// Filename: matrixOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/mvOps.h"

// Matrix Initialization
// Inputs: None
// Outputs: m
// Operation: 

double** mvOps::mInit(void)
{
   m = new double *[3];

   for (int i=0;i<3;i++)
   {
      m[i]= new double[3];
   }

   mSetZeros(m);
   return m;
}

// Set Matrix to Zeros
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=Zeros

void mvOps::mSetZeros(double** mOut)
{

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         mOut[i][j]=0;
      }
   }
}

// Set Matrix to Identity
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=Identity

void mvOps::mSetIdentity(double** mOut)
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

void mvOps::mAdd(double** mOut, double** m1, double** m2)
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

void mvOps::mSub(double** mOut, double** m1, double** m2)
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

void mvOps::mMult(double** mOut, double** m1, double** m2)
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

void mvOps::mTrace(double* sOut, double** m1)
{
   *sOut=m1[0][0]+m1[1][1]+m1[2][2];
}

// Scalar * Matrix
// Inputs: s1, m1
// Outputs: mOut
// Operation: s1*m1=mOut

void mvOps::mScaXMat(double** mOut, double s1, double** m1)
{
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         mOut[i][j]=s1*m1[i][j];
      }
   }
}

// Matrix Transpose
// Inputs: s1, m1
// Outputs: mOut
// Operation: s1*m1=mOut

void mvOps::mTran(double** mOut, double** m1)
{
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         mOut[j][i]=m1[i][j];
      }
   }
}

// Matrix isEqual
// Inputs: m1, m1
// Outputs: str1
// Operation: s1*m1=mOut

void mvOps::misEqual(bool* isEqual, double** m1, double** m2)
{
   *isEqual=false;
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         if (m1[i][j]==m2[i][j])
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
