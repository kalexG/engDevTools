//--------------------------
// Filename: matrixOps.cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/vmaOps.h"

// Matrix Initialization
// Inputs: None
// Outputs: m
// Operation: 

void vmaOps::mInit(double*** mInit)
{
   *mInit = new double *[3];

   for (int i=0;i<3;i++)
   {
      (*mInit)[i]= new double[3];
   }

   mSetZeros(*mInit);
}

// Matrix Free
// Inputs: mFree
// Outputs: mFree
// Operation: Free Memory

void vmaOps::mFree(double*** mFree)
{
   for (int i=0;i<3;i++)
   {
      delete[] (*mFree)[i];
   }
   
   delete[] *mFree;
   *mFree=NULL;
}

// Set Matrix to Zeros
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=Zeros

void vmaOps::mSetZeros(mat mOut)
{

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         mOut[i][j]=0;
      }
   }
}

// Set Matrix to Ones
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=Ones

void vmaOps::mSetOnes(mat mOut)
{

   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         mOut[i][j]=1;
      }
   }
}

// Set Matrix to Identity
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=Identity

void vmaOps::mSetIdentity(mat mOut)
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

// Set Matrix to 123
// Inputs: mOut
// Outputs: mOut
// Operation: mOut=123

void vmaOps::mSet123(mat mOut)
{
   int k=1;
   for (int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         mOut[i][j]=k;
         k++;
      }
   }
}

// Matrix Addition
// Inputs: m1, m2
// Outputs: mOut
// Operation: mOut=m1+m2

void vmaOps::mAdd(mat mOut, mat m1, mat m2)
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

void vmaOps::mSub(mat mOut, mat m1, mat m2)
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

void vmaOps::mMult(mat mOut, mat m1, mat m2)
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

void vmaOps::mTrace(double* sOut, mat m1)
{
   *sOut=m1[0][0]+m1[1][1]+m1[2][2];
}

// Scalar * Matrix
// Inputs: s1, m1
// Outputs: mOut
// Operation: s1*m1=mOut

void vmaOps::ScaXMat(mat mOut, double s1, mat m1)
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
// Operation: m2=m1^t

void vmaOps::mTran(mat mOut, mat m1)
{
   // TODO: Find better way to protect input matrix if mOut is replacing m1 [mTran(m1,m1)]
   double uLD[3]={m1[1][0],m1[2][0],m1[2][1]};
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         mOut[j][i]=m1[i][j];
      }
   }
   mOut[0][1]=uLD[0];
   mOut[0][2]=uLD[1];
   mOut[1][2]=uLD[2];
}

// Matrix isEqual
// Inputs: m1, m2
// Outputs: str1
// Operation: ?m1=m2?

void vmaOps::mIsEqual(bool* isEqual, mat m1, mat m2)
{
   *isEqual=false;
   bool wiTol=false;
   double tol=1.0e-10;
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
            if (abs(m1[i][j]-m2[i][j])>tol)
            {
               *isEqual=false;
               printf("These matricies are NOT equal\n");
               return;
            }
            else
            {
               wiTol=true;
               *isEqual=true;
            }
         }
      }
   }
   if (wiTol==true)
   {
      printf("Found a difference within tolerance: err<%f\n",tol);
   }
   printf("These matricies are ARE equal\n");
}

// Matrix Determinant (3x3) 
// Inputs: m1
// Outputs: sOut
// Operation: Determinant of 3x3 matrix

void vmaOps::mDet33(double* sOut, mat m1)
{
   *sOut=m1[0][0]*(m1[1][1]*m1[2][2]-m1[2][1]*m1[1][2]);
   *sOut=*sOut+m1[0][1]*(m1[1][2]*m1[2][0]-m1[2][2]*m1[1][0]);
   *sOut=*sOut+m1[0][2]*(m1[1][0]*m1[2][1]-m1[2][0]*m1[1][1]);
}

// Matrix Minor
// Inputs: m1
// Outputs: mOut
// Operation: Get Matrix of Minors

void vmaOps::mMinor(mat mOut, mat m1)
{
   double mDet22[4];
   double detMin;
   
   for(int i=0;i<3;i++)
   {
      for (int j=0;j<3;j++)
      {
         for (int k=0;k<4;)
         {
            for (int p=0;p<3;p++)
            {
               for (int q=0;q<3;q++)
               {
                  if (p!=i && q!=j)
                  {
                     mDet22[k]=m1[p][q];
                     k++;
                     if (k==4)
                     {
                        break;
                     }
                  }
               }
            }
         }
         detMin = mDet22[0]*mDet22[3]-mDet22[1]*mDet22[2];  
         mOut[i][j]=detMin;
      }
   }
}

// Matrix Cofactor
// Inputs: m1
// Outputs: mOut
// Operation: Get Matrix of Cofactors

void vmaOps::mCofactor(mat mOut, mat m1)
{
   mMinor(mOut, m1);
   mOut[0][1]=-mOut[0][1];
   mOut[1][0]=-mOut[1][0];
   mOut[1][2]=-mOut[1][2];
   mOut[2][1]=-mOut[2][1];
}

// Matrix Adjugate
// Inputs: m1
// Outputs: mOut
// Operation: Get Matrix Adjoint

void vmaOps::mAdjugate(mat mOut, mat m1)
{
   mCofactor(mOut, m1);
   mTran(mOut, mOut);
}


// Matrix Inverse
// Inputs: m1
// Outputs: m2
// Operation: Inverse of 3x3 matrix

void vmaOps::mInv(mat mOut, mat m1)
{
   double det=0;
   mDet33(&det,m1);
   double det_inv=1/det;
   mSetZeros(mOut);
   if (det==0)
   {
      printf("Input matrix is NOT invertible. Its determinant is equal to zero.\n");
      return;
   }

   double col1[3]={m1[0][0],m1[0][1],m1[0][2]};
   double col2[3]={m1[1][0],m1[1][1],m1[1][2]};
   double col3[3]={m1[2][0],m1[2][1],m1[2][2]};
   double cp[3];

   crossProduct(cp, col2, col3);
   ScaXVec(cp, det_inv, cp);
   memcpy(&mOut[0][0],&cp,sizeof(cp));

   crossProduct(cp, col3, col1);
   ScaXVec(cp, det_inv, cp);
   memcpy(&mOut[1][0],&cp,sizeof(cp));

   crossProduct(cp, col1, col2);
   ScaXVec(cp, det_inv, cp);
   memcpy(&mOut[2][0],&cp,sizeof(cp));

   mTran(mOut,mOut);

}


