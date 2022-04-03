#include "EDTUnitTest.h"

// Test: Matrix() - Make sure object got constructed correctly
TEST_F(MatrixUnitTest, checkConstructor)
{
    // Only Matrix unique data in constructor
    Matrix<double> myTestMatrix;
    EXPECT_EQ(myTestMatrix.rows(), 3);
    EXPECT_EQ(myTestMatrix.cols(), 3);
    EXPECT_EQ(myTestMatrix.size(), 9);
}
