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
