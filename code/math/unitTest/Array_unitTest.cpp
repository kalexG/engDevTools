// Array_ut.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Array.h"

using ::testing::DoubleNear;
using ::testing::ElementsAre;

class VectorUnitTest : public ::testing::Test
{
    public:
        Vector myTestVector;
    private:
    protected:
};

class MatrixUnitTest : public ::testing::Test
{
    public:
        Matrix myTestMatrix;
    private:
    protected:
};

// Test: Matrix() - Make sure object got constructed correctly
TEST_F(MatrixUnitTest, checkConstructor)
{
    // Only Vector unique data in constructor
    EXPECT_EQ(myTestMatrix.getMyRows(), 3);
    EXPECT_EQ(myTestMatrix.getMyCols(), 3);
    EXPECT_EQ(myTestMatrix.getMyElements(), 9);
}

// Test: Vector() - Make sure object got constructed correctly
TEST_F(VectorUnitTest, checkConstructor)
{
    // Only Vector unique data in constructor
    EXPECT_EQ(myTestVector.getMyRows(), 3);
    EXPECT_EQ(myTestVector.getMyCols(), 1);
    EXPECT_EQ(myTestVector.getMyElements(), 3);
}

// Test: Vector::operator() - Check in-bounds access
TEST_F(VectorUnitTest, checkOperatorAccessParenthesis_inBounds)
{
    myTestVector.setIncrement(1.0, 1.0);
    EXPECT_EQ(myTestVector(0), 1);
    EXPECT_EQ(myTestVector(1), 2);
    EXPECT_EQ(myTestVector(2), 3);
}

// Test: Vector::operator() - Check out-of-bounds access
TEST_F(VectorUnitTest, checkOperatorAccessParenthesis_outOfBounds)
{
    EXPECT_THROW(myTestVector(3), std::out_of_range);
}

// Test: Vector::getMagnitude() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkGetMagnitude)
{
    myTestVector.setIncrement(1.0, 1.0);
    ASSERT_THAT(myTestVector.getMagnitude(), DoubleNear(sqrt(14), 1e-05));
}

// Test: Vector::crossProduct() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkCrossProduct)
{
    Vector vec1;
    Vector vec2;
    vec1.setIncrement(1.0, 1.0);
    vec2.setOnes();
    myTestVector = crossProduct(vec1, vec2);
    EXPECT_EQ(myTestVector(0), -1.0);
    EXPECT_EQ(myTestVector(1), 2.0);
    EXPECT_EQ(myTestVector(2), -1.0);
}

// Test: Vector::dotProduct() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkDotProduct)
{
    Vector vec1;
    Vector vec2;
    vec1.setIncrement(1.0, 1.0);
    vec2.setOnes();
    ASSERT_EQ(dotProduct(vec1, vec2), 6.0);
}

// Test: Vector::getUnitVector() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkGetUnitVector)
{
    Vector vec1;
    vec1.setIncrement(1.0, 1.0);
    myTestVector = vec1.getUnitVector();
    ASSERT_THAT(myTestVector(0), DoubleNear(1.0/sqrt(14), 1e-05));
    ASSERT_THAT(myTestVector(1), DoubleNear(2.0/sqrt(14), 1e-05));
    ASSERT_THAT(myTestVector(2), DoubleNear(3.0/sqrt(14), 1e-05));
}

int main(int argc, char **argv) {

   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
