#include "EDTUnitTest.h"

// Test: Vector() - Make sure object got constructed correctly
TEST_F(VectorUnitTest, checkConstructor)
{
    // Only Vector<double> unique data in constructor
    Vector<double> myTestVector;
    EXPECT_EQ(myTestVector.rows(), 3);
    EXPECT_EQ(myTestVector.cols(), 1);
    EXPECT_EQ(myTestVector.size(), 3);
}

// Test: Vector::operator() - Check in-bounds access
TEST_F(VectorUnitTest, checkOperatorAccessParenthesis_inBounds)
{
    Vector<double> myTestVector;
    myTestVector.set(1.0, 1.0);
    EXPECT_EQ(myTestVector(0), 1);
    EXPECT_EQ(myTestVector(1), 2);
    EXPECT_EQ(myTestVector(2), 3);
}

// Test: Vector::operator() - Check out-of-bounds access
TEST_F(VectorUnitTest, checkOperatorAccessParenthesis_outOfBounds)
{
    Vector<double> myTestVector;
    EXPECT_THROW(myTestVector(3), std::out_of_range);
}

// Test: Vector::getMagnitude() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkGetMagnitude)
{
    Vector<double> myTestVector;
    myTestVector.set(1.0, 1.0);
    ASSERT_THAT(myTestVector.magnitude(), DoubleNear(sqrt(14), 1e-05));
}

// Test: Vector::crossProduct() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkCrossProduct)
{
    Vector<double> vec1;
    Vector<double> vec2;
    Vector<double> myTestVector;
    vec1.set(1.0, 1.0);
    vec2.ones();
    myTestVector = Utilities::crossProduct(vec1, vec2);
    EXPECT_EQ(myTestVector(0), -1.0);
    EXPECT_EQ(myTestVector(1), 2.0);
    EXPECT_EQ(myTestVector(2), -1.0);
}

// Test: Vector::dotProduct() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkDotProduct)
{
    Vector<double> vec1;
    Vector<double> vec2;
    vec1.set(1.0, 1.0);
    vec2.ones();
    ASSERT_EQ(Utilities::dotProduct(vec1, vec2), 6.0);
}

// Test: Vector::getUnitVector() - Make sure calculation is correct
TEST_F(VectorUnitTest, checkGetUnitVector)
{
    Vector<double> vec1;
    Vector<double> myTestVector;
    vec1.set(1.0, 1.0);
    myTestVector = vec1.unit();
    ASSERT_THAT(myTestVector(0), DoubleNear(1.0/sqrt(14), 1e-05));
    ASSERT_THAT(myTestVector(1), DoubleNear(2.0/sqrt(14), 1e-05));
    ASSERT_THAT(myTestVector(2), DoubleNear(3.0/sqrt(14), 1e-05));
}
