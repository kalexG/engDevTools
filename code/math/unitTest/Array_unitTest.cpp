#include "../inc/mathUnitTest.h"

// Test Array() - Make sure object got constructed correctly with valid dimensions
TEST_F(ArrayUnitTest, checkConstructor_validDimensions)
{
    Array myTestArray(3, 3);
    EXPECT_EQ(myTestArray.getMyRows(), 3);
    EXPECT_EQ(myTestArray.getMyCols(), 3);
    EXPECT_EQ(myTestArray.getMyElements(), 9);
}

// Test Array() - Catch constructor throw for invalid dimensions
TEST_F(ArrayUnitTest, checkConstructor_invalidDimensions)
{
    EXPECT_THROW(Array myTestArray(3, -1), std::invalid_argument);
}

// Test Array() - Make sure object identifies square array during construction
TEST_F(ArrayUnitTest, checkConstructor_squareArray)
{
    Array myTestArray(4, 4);
    EXPECT_TRUE(myTestArray.getIsSquare());    
}

// Test Array() - Make sure object identifies non-square array during construction
TEST_F(ArrayUnitTest, checkConstructor_nonSquareArray)
{
    Array myTestArray(4, 3);
    EXPECT_FALSE(myTestArray.getIsSquare());    
}

// Test Array::setZeros() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetZeros)
{
    Array myTestArray(3, 3);
    myTestArray.setZeros();
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], 0.0);
    }
}

// Test Array::setOnes() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetOnes)
{
    Array myTestArray(3, 3);
    myTestArray.setOnes();
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], 1.0);
    }
}

// Test Array::setTo() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetTo)
{
    Array myTestArray(3, 3);
    myTestArray.setTo(5.0);
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], 5.0);
    }
}

// Test Array::setIncrement() - Make sure setter works (Default)
TEST_F(ArrayUnitTest, checkSetIncrement_default)
{
    Array myTestArray(3, 3);
    myTestArray.setIncrement();
    double tmp = 0.0;
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], tmp);
        tmp += 1.0;
    }
}

// Test Array::setIncrement() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetIncrement)
{
    Array myTestArray(3, 3);
    myTestArray.setIncrement(2.0, 2.0);
    double tmp = 2.0;
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], tmp);
        tmp += 2.0;
    }
}

// Test Array::setIdentity() - Make sure setter works (Catch non-square array)
TEST_F(ArrayUnitTest, checkSetIdentity_nonSquareArray)
{
    Array myTestArray(3, 4);
    myTestArray.setOnes();
    EXPECT_THROW(myTestArray.setIdentity(), std::length_error);
}

// Test Array::setIdentity() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetIdentity_squareArray)
{
    Array myTestArray(4, 4);
    myTestArray.setOnes();
    myTestArray.setIdentity();
    for (int i = 0; i < myTestArray.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray.getMyCols(); j++)
        {
            if (i == j)
            {
                EXPECT_EQ(myTestArray(i,j), 1.0);
            }
            else
            {
                EXPECT_EQ(myTestArray(i,j), 0.0);
            }
        }
    }
}

// Test Array::getTranspose() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetTranspose)
{
    Array myTestArray1(4, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1.getTranspose());
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
    EXPECT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    EXPECT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    EXPECT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements());
    
}

// Test Array::setTranspose() - Make sure setter works (M=N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Eq_N)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
    EXPECT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    EXPECT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    EXPECT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
}

// Test Array::setTranspose() - Make sure setter works (M>N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Gt_N)
{
    Array myTestArray1(4, 2);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
    EXPECT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    EXPECT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    EXPECT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements());
}

// Test Array::setTranspose() - Make sure setter works (M<N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Lt_N)
{
    Array myTestArray1(2, 4);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
    EXPECT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    EXPECT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    EXPECT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
}

// Test Array::operator= - Make sure copy assignment works
TEST_F(ArrayUnitTest, checkCopyAssignment)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(2.0, 4.0);
    Array myTestArray2(3, 3);
    myTestArray2 = myTestArray1;
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    for (int i = 0; i < myTestArray1.getMyElements(); i++ )
    {
        EXPECT_EQ(myTestArray1[i], myTestArray2[i]);
    } 
}

// Test Array(&Array) - Make sure copy construtor works
TEST_F(ArrayUnitTest, checkCopyConstructor)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(2.0, 4.0);
    Array myTestArray2(myTestArray1);
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    for (int i = 0; i < myTestArray1.getMyElements(); i++ )
    {
        EXPECT_EQ(myTestArray1[i], myTestArray2[i]);
    } 
}
