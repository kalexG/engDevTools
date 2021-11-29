//------------------------------
// Filename: Matrix_unitTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//------------------------------

#include "../inc/MathUnitTest.h"

// Test: Matrix() - Make sure object got constructed correctly
TEST_F(MatrixUnitTest, checkConstructor)
{
    // Only Matrix unique data in constructor
    Matrix myTestMatrix;
    EXPECT_EQ(myTestMatrix.getMyRows(), 3);
    EXPECT_EQ(myTestMatrix.getMyCols(), 3);
    EXPECT_EQ(myTestMatrix.getMyElements(), 9);
}

// Test: Matrix::getMinor() - Make sure getter works
TEST_F(MatrixUnitTest, checkGetMinor)
{
    Matrix myTestMatrix(myMatrix1.getMinor());
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_EQ(myTestMatrix(i,j), myMatrix1Minor(i,j));
        }
    }
}

// Test: Matrix::getCofactor() - Make sure getter works
TEST_F(MatrixUnitTest, checkGetCofactor)
{
    Matrix myTestMatrix(myMatrix1.getCofactor());
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_EQ(myTestMatrix(i,j), myMatrix1Cofactor(i,j));
        }
    }
}

// Test: Matrix::getAdjugate() - Make sure getter works
TEST_F(MatrixUnitTest, checkGetAdjugate)
{
    Matrix myTestMatrix(myMatrix1.getAdjugate());
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            EXPECT_EQ(myTestMatrix(i,j), myMatrix1Adjugate(i,j));
        }
    }
}

// Test: Matrix::getDeterminant33() - Make sure getter works
TEST_F(MatrixUnitTest, checkGetDeterminant)
{
    double det = myMatrix1.getDeterminant();
    EXPECT_EQ(det, myMatrix1Determinant);
}
