// Matrix_unitTest.cpp
#include "../inc/mathUnitTest.h"

// Test: Matrix() - Make sure object got constructed correctly
TEST_F(MatrixUnitTest, checkConstructor)
{
    // Only Matrix unique data in constructor
    Matrix myTestMatrix;
    EXPECT_EQ(myTestMatrix.getMyRows(), 3);
    EXPECT_EQ(myTestMatrix.getMyCols(), 3);
    EXPECT_EQ(myTestMatrix.getMyElements(), 9);
}
