//--------------------------
// Filename: Matrix.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#include "../inc/Matrix.h"

// Get Matrix of Minors
Matrix Matrix::getMinor(void)
{
    double mDet22[4];
    double detMin;
    Matrix tmp;

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
                            mDet22[k]=myArray[myCols*p+q];
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
            tmp(i,j)=detMin;
        }
    }
    return tmp;
}

// Get Matrix of Cofactors
Matrix Matrix::getCofactor(void)
{
    Matrix tmp;
    tmp = getMinor();
    tmp(0,1)=-tmp(0,1);
    tmp(1,0)=-tmp(1,0);
    tmp(1,2)=-tmp(1,2);
    tmp(2,1)=-tmp(2,1);
    return tmp;
}

// Get Matrix Adjoint
Matrix Matrix::getAdjugate(void)
{
    Matrix tmp;
    tmp = getCofactor();
    tmp.setTranspose();
    return tmp;
}

