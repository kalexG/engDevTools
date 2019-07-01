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
