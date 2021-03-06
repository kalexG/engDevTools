//-----------------------------
// Filename: Array_unitTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//-----------------------------

#include "../inc/MathUnitTest.h"

// Test Array() - Make sure object got constructed correctly with valid dimensions
TEST_F(ArrayUnitTest, checkConstructor_validDimensions)
{
    Array myTestArray(4, 7);
    EXPECT_EQ(myTestArray.getMyRows(), 4);
    EXPECT_EQ(myTestArray.getMyCols(), 7);
    EXPECT_EQ(myTestArray.getMyElements(), 28);
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
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements());
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
    
}

// Test Array::setTranspose() - Make sure setter works (M=N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Eq_N)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::setTranspose() - Make sure setter works (M>N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Gt_N)
{
    Array myTestArray1(4, 2);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements());
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::setTranspose() - Make sure setter works (M<N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Lt_N)
{
    Array myTestArray1(2, 4);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(myTestArray1);
    myTestArray1.setTranspose();
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    for (int i = 0; i < myTestArray2.getMyRows(); i++)
    {
        for (int j = 0; j < myTestArray2.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
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

// Test Array::operator() - Check in-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessParenthesis_inBounds)
{
    Array myTestArray(4, 7);
    myTestArray.setIncrement(1.0, 1.0);
    double k = 1.0;
    for (int i = 0; i < myTestArray.getMyRows(); i++ )
    {
        for (int j = 0; j < myTestArray.getMyCols(); j++)
        {
            EXPECT_EQ(myTestArray(i, j), k);
            k += 1.0;
        }
    } 
}

// Test Array::operator() - Check out-of-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessParenthesis_outOfBounds)
{
    Array myTestArray(4, 7);
    EXPECT_THROW(myTestArray(3,7), std::out_of_range);
    EXPECT_THROW(myTestArray(4,6), std::out_of_range);
    EXPECT_THROW(myTestArray(3,-1), std::out_of_range);
    EXPECT_THROW(myTestArray(-1,6), std::out_of_range);
}

// Test Array::operator[] - Check in-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessBracket_inBounds)
{
    Array myTestArray(4, 7);
    myTestArray.setIncrement(1.0, 1.0);
    double k = 1.0;
    for (int i = 0; i < myTestArray.getMyElements(); i++ )
    {
        EXPECT_EQ(myTestArray[i], k);
        k += 1.0;
    } 
}

// Test Array::operator[] - Check out-of-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessBracket_outOfBounds)
{
    Array myTestArray(4, 7);
    EXPECT_THROW(myTestArray[28], std::out_of_range);
    EXPECT_THROW(myTestArray[-1], std::out_of_range);
}

// Test Array::operator* (Array * scalar) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorMultiply_ArrayScalar)
{
    Array myTestArray(4, 2);
    myTestArray.setTo(2.0);
    myTestArray = myTestArray * 2;
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], 4.0);
    }
}

// Test Array::operator* (scalar * Array) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorMultiply_ScalarArray)
{
    Array myTestArray(4, 2);
    myTestArray.setTo(2.0);
    myTestArray = 2 * myTestArray;
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], 4.0);
    }
}

// Test Array::getMyArray() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyArray)
{
    Array myTestArray(3, 3);
    myTestArray.setIncrement(1.0, 1.0);
    double* tmp;
    tmp = myTestArray.getMyArray();
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(tmp[i], myTestArray[i]);
    }
    delete[] tmp;
    tmp = NULL;
}

// Test Array::getMyArraySize() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyArraySize)
{
    Array myTestArray(3, 3);
    EXPECT_EQ(myTestArray.getMyArraySize(), 72);
}

// Test Array::operator+ (Array + Array) - Catch invalid demnsions
TEST_F(ArrayUnitTest, checkOperatorAdd_invalidDimensions)
{
    Array myTestArray1(3, 3);
    Array myTestArray2(3, 4);
    Array myTestArray3(3, 3);
    EXPECT_THROW(myTestArray3 = myTestArray1 + myTestArray2, std::length_error);
}

// Test Array::operator+ (Array + Array) - Make calculation is correct
TEST_F(ArrayUnitTest, checkOperatorAdd_validDimensions)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(3, 3);
    myTestArray2.setTo(2.0);
    Array myTestArray3(3, 3);
    myTestArray3.setZeros();
    myTestArray3 = myTestArray1 + myTestArray2;
    for (int i = 0; i < myTestArray1.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray3[i], 3.0);
    }
}

// Test Array::operator- (Array - Array) - Catch invalid demnsions
TEST_F(ArrayUnitTest, checkOperatorSubtract_invalidDimensions)
{
    Array myTestArray1(3, 3);
    Array myTestArray2(3, 4);
    Array myTestArray3(3, 3);
    EXPECT_THROW(myTestArray3 = myTestArray1 - myTestArray2, std::length_error);
}

// Test Array::operator- (Array - Array) - Make calculation is correct
TEST_F(ArrayUnitTest, checkOperatorSubtract_validDimensions)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(3, 3);
    myTestArray2.setTo(3.0);
    Array myTestArray3(3, 3);
    myTestArray3.setZeros();
    myTestArray3 = myTestArray2 - myTestArray1;
    for (int i = 0; i < myTestArray1.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray3[i], 2.0);
    }
}

// Test Array::operator- (-1 * Array) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorSubtract_negativeArray)
{
    Array myTestArray(3, 3);
    myTestArray.setTo(2.0);
    myTestArray = -myTestArray;
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(myTestArray[i], -2.0);
    }
}

// Test Array::getStdVector1D() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetStdVector1D)
{
    Array myTestArray(3, 4);
    myTestArray.setIncrement(2.0, 1.0);
    std::vector<double> tmp = myTestArray.getStdVector1D();
    for (int i = 0; i < myTestArray.getMyElements(); i++)
    {
        EXPECT_EQ(tmp.at(i), myTestArray[i]);
    }
}

// Test Array::getStdVector2D() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetStdVector2D)
{
    Array myTestArray(3, 4);
    myTestArray.setIncrement(2.0, 1.0);
    std::vector<std::vector<double>> tmp = myTestArray.getStdVector2D();
    for (int i = 0; i < myTestArray.getMyRows(); i++)
    {
        for(int j = 0; j < myTestArray.getMyCols(); j++)
        {
            EXPECT_EQ(tmp.at(i).at(j), myTestArray(i,j));
        }
    }
}

// Test Array::getTrace() - Make sure calculation is correct (invalid dimensions)
TEST_F(ArrayUnitTest, checkGetTrace_invalidDimensions)
{
    Array myTestArray(3, 4);
    EXPECT_THROW(myTestArray.getTrace(), std::length_error);
}

// Test Array::getTrace() - Make sure calculation is correct (valid dimensions)
TEST_F(ArrayUnitTest, checkGetTrace_validDimensions)
{
    Array myTestArray(3, 3);
    myTestArray.setIncrement(1.0, 1.0);
    EXPECT_EQ(myTestArray.getTrace(), 15.0);
}

// Test Array::operator= - Make sure move assignment works
TEST_F(ArrayUnitTest, checkMoveAssignment)
{
    Array myTestArray1(3, 3);
    Array myTestArray2(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    myTestArray2 = std::move(myTestArray1);
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    double j = 1.0;
    for (int i = 0; i < myTestArray2.getMyElements(); i++ )
    {
        EXPECT_EQ(myTestArray2[i], j);
        j += 1.0;
    } 
}

// Test Array(&&Array) - Make sure Move construtor works
TEST_F(ArrayUnitTest, checkMoveConstructor)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2 = std::move(myTestArray1);
    ASSERT_EQ(myTestArray2.getMyRows(), myTestArray1.getMyCols());
    ASSERT_EQ(myTestArray2.getMyCols(), myTestArray1.getMyRows());
    ASSERT_EQ(myTestArray2.getMyElements(), myTestArray1.getMyElements()); 
    double j = 1.0;
    for (int i = 0; i < myTestArray2.getMyElements(); i++ )
    {
        EXPECT_EQ(myTestArray2[i], j);
        j += 1.0;
    } 
}

// Test Array::swap() - Make sure swap function works
TEST_F(ArrayUnitTest, checkSwap)
{
    Array myTestArray1(3, 3);
    Array myTestArray2(5, 3);
    swap(myTestArray1, myTestArray2);
    ASSERT_EQ(myTestArray2.getMyRows(), 3);
    ASSERT_EQ(myTestArray1.getMyRows(), 5);
    ASSERT_EQ(myTestArray2.getMyCols(), 3);
    ASSERT_EQ(myTestArray1.getMyCols(), 3);
    ASSERT_EQ(myTestArray2.getMyElements(), 9);
    ASSERT_EQ(myTestArray1.getMyElements(), 15);
    ASSERT_EQ(myTestArray2.getMyArraySize(), 72);
    ASSERT_EQ(myTestArray1.getMyArraySize(), 120);
    ASSERT_TRUE(myTestArray2.getIsSquare());
    ASSERT_FALSE(myTestArray1.getIsSquare());
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_differentSize)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(4, 3);
    myTestArray2.setOnes();
    ASSERT_FALSE(compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_differentElements)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(2.0, 1.0);
    ASSERT_FALSE(compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_outOfDefaultTolerance)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    myTestArray1(0, 0) = 1.000002;
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    ASSERT_FALSE(compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_outOfSpecifiedTolerance)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    myTestArray1(0, 0) = 1.0000002;
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    ASSERT_FALSE(compare(myTestArray1, myTestArray2, 1e-07));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_inDefaultTolerance)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    myTestArray1(0, 0) = 1.0000002;
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    ASSERT_TRUE(compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_inSpecifiedTolerance)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(1.0, 1.0);
    myTestArray1(0, 0) = 1.00000002;
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    ASSERT_TRUE(compare(myTestArray1, myTestArray2, 1e-07));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_same)
{
    Array myTestArray1(3, 3);
    myTestArray1.setIncrement(2.0, 2.0);
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(2.0, 2.0);
    ASSERT_TRUE(compare(myTestArray1, myTestArray2));
}

// Test Array::operator* - Catch invalid dimensions
TEST_F(ArrayUnitTest, checkOperatorMultiply_invalidDimensions)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(4, 3);
    myTestArray2.setOnes();
    Array myTestArray3(3, 3);
    myTestArray3.setZeros();
    EXPECT_THROW(myTestArray3 = myTestArray1 * myTestArray2, std::length_error);
}

// Test Array::operator* - Mxn * n*K
TEST_F(ArrayUnitTest, checkOperatorMultiply_Mn_nK)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    Array myTestArray3(3, 3);
    myTestArray3.setZeros();
    myTestArray3 = myTestArray1 * myTestArray2;
    EXPECT_EQ(myTestArray3(0, 0), 12);
    EXPECT_EQ(myTestArray3(0, 1), 15);
    EXPECT_EQ(myTestArray3(0, 2), 18);
    EXPECT_EQ(myTestArray3(1, 0), 12);
    EXPECT_EQ(myTestArray3(1, 1), 15);
    EXPECT_EQ(myTestArray3(1, 2), 18);
    EXPECT_EQ(myTestArray3(2, 0), 12);
    EXPECT_EQ(myTestArray3(2, 1), 15);
    EXPECT_EQ(myTestArray3(2, 2), 18);
}

// Test Array::operator* - mxn * n*K
TEST_F(ArrayUnitTest, checkOperatorMultiply_mn_nK)
{
    Array myTestArray1(2, 3);
    myTestArray1.setOnes();
    Array myTestArray2(3, 3);
    myTestArray2.setIncrement(1.0, 1.0);
    Array myTestArray3(2, 3);
    myTestArray3.setZeros();
    myTestArray3 = myTestArray1 * myTestArray2;
    EXPECT_EQ(myTestArray3(0, 0), 12);
    EXPECT_EQ(myTestArray3(0, 1), 15);
    EXPECT_EQ(myTestArray3(0, 2), 18);
    EXPECT_EQ(myTestArray3(1, 0), 12);
    EXPECT_EQ(myTestArray3(1, 1), 15);
    EXPECT_EQ(myTestArray3(1, 2), 18);
}

// Test Array::operator* - Mxn * n*k
TEST_F(ArrayUnitTest, checkOperatorMultiply_Mn_nk)
{
    Array myTestArray1(3, 3);
    myTestArray1.setOnes();
    Array myTestArray2(3, 2);
    myTestArray2.setIncrement(1.0, 1.0);
    Array myTestArray3(3, 2);
    myTestArray3.setZeros();
    myTestArray3 = myTestArray1 * myTestArray2;
    EXPECT_EQ(myTestArray3(0, 0), 9);
    EXPECT_EQ(myTestArray3(0, 1), 12);
    EXPECT_EQ(myTestArray3(1, 0), 9);
    EXPECT_EQ(myTestArray3(1, 1), 12);
    EXPECT_EQ(myTestArray3(2, 0), 9);
    EXPECT_EQ(myTestArray3(2, 1), 12);
}
