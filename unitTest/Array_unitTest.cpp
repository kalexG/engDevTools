#include "EDTUnitTest.h"

// Test Array() - Make sure object got constructed correctly with valid dimensions
TEST_F(ArrayUnitTest, checkConstructor_validConstructionNonSquare)
{
    Array<double> myTestArray(4, 7);
    EXPECT_EQ(myTestArray.rows(), 4);
    EXPECT_EQ(myTestArray.cols(), 7);
    EXPECT_EQ(myTestArray.size(), 28);
}

// Test Array() - Make sure object got constructed correctly with valid dimensions
TEST_F(ArrayUnitTest, checkConstructor_validConstructionSquare)
{
    Array<double> myTestArray(4, 4);
    EXPECT_EQ(myTestArray.rows(), 4);
    EXPECT_EQ(myTestArray.cols(), 4);
    EXPECT_EQ(myTestArray.size(), 16);
}

// Test Array() - Catch constructor throw for invalid dimensions
TEST_F(ArrayUnitTest, checkConstructor_invalidDimensions)
{
    EXPECT_THROW(Array<double> myTestArray(3, -1), std::invalid_argument);
}

// Test Array::zeros() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetZeros)
{
    Array<double> myTestArray(3, 3);
    myTestArray.zeros();
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], 0.0);
    }
}

// Test Array::ones() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetOnes)
{
    Array<double> myTestArray(3, 3);
    myTestArray.ones();
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], 1.0);
    }
}

// Test Array::set() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetTo)
{
    Array<double> myTestArray(3, 3);
    myTestArray.set(5.0);
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], 5.0);
    }
}

// Test Array::set() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetIncrement)
{
    Array<double> myTestArray(3, 3);
    myTestArray.set(2.0, 2.0);
    double tmp = 2.0;
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], tmp);
        tmp += 2.0;
    }
}

// Test Array::identity() - Make sure setter works (Catch non-square array)
TEST_F(ArrayUnitTest, checkSetIdentity_nonSquareArray)
{
    Array<double> myTestArray(3, 4);
    myTestArray.ones();
    EXPECT_THROW(myTestArray.identity(), std::length_error);
}

// Test Array::identity() - Make sure setter works
TEST_F(ArrayUnitTest, checkSetIdentity_squareArray)
{
    Array<double> myTestArray(4, 4);
    myTestArray.ones();
    myTestArray.identity();
    for (int i = 0; i < myTestArray.rows(); i++)
    {
        for (int j = 0; j < myTestArray.cols(); j++)
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

// Test Array::g_inverse() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetInverse_6_3_5_b)
{
    Array<double> myTestArray(myArray2->g_inverse());
    ASSERT_EQ(myTestArray.rows(), myArray2_inv->cols());
    ASSERT_EQ(myTestArray.cols(), myArray2_inv->rows());
    ASSERT_EQ(myTestArray.size(), myArray2_inv->size());
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray, *myArray2_inv));
}

// Test Array::g_inverse() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetInverse_6_3_5_d)
{
    Array<double> myTestArray(myArray4->g_inverse());
    ASSERT_EQ(myTestArray.rows(), myArray4_inv->cols());
    ASSERT_EQ(myTestArray.cols(), myArray4_inv->rows());
    ASSERT_EQ(myTestArray.size(), myArray4_inv->size());
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray, *myArray4_inv));
}

// Test Array::g_transpose() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetTranspose)
{
    Array<double> myTestArray1(4, 3);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2(myTestArray1.g_transpose());
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size());
    for (int i = 0; i < myTestArray2.rows(); i++)
    {
        for (int j = 0; j < myTestArray2.cols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::s_transpose() - Make sure setter works (M=N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Eq_N)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2(myTestArray1);
    myTestArray1.s_transpose();
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    for (int i = 0; i < myTestArray2.rows(); i++)
    {
        for (int j = 0; j < myTestArray2.cols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::s_transpose() - Make sure setter works (M>N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Gt_N)
{
    Array<double> myTestArray1(4, 2);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2(myTestArray1);
    myTestArray1.s_transpose();
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size());
    for (int i = 0; i < myTestArray2.rows(); i++)
    {
        for (int j = 0; j < myTestArray2.cols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::s_transpose() - Make sure setter works (M<N)
TEST_F(ArrayUnitTest, checkSetTranspose_M_Lt_N)
{
    Array<double> myTestArray1(2, 4);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2(myTestArray1);
    myTestArray1.s_transpose();
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    for (int i = 0; i < myTestArray2.rows(); i++)
    {
        for (int j = 0; j < myTestArray2.cols(); j++)
        {
            EXPECT_EQ(myTestArray2(i,j), myTestArray1(j,i));
        }
    }
}

// Test Array::operator= - Make sure copy assignment works
TEST_F(ArrayUnitTest, checkCopyAssignment)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(2.0, 4.0);
    Array<double> myTestArray2(3, 3);
    myTestArray2 = myTestArray1;
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    for (int i = 0; i < myTestArray1.size(); i++ )
    {
        EXPECT_EQ(myTestArray1[i], myTestArray2[i]);
    } 
}

// Test Array(&Array) - Make sure copy construtor works
TEST_F(ArrayUnitTest, checkCopyConstructor)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(2.0, 4.0);
    Array<double> myTestArray2(myTestArray1);
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    for (int i = 0; i < myTestArray1.size(); i++ )
    {
        EXPECT_EQ(myTestArray1[i], myTestArray2[i]);
    } 
}

// Test Array::operator() - Check in-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessParenthesis_inBounds)
{
    Array<double> myTestArray(4, 7);
    myTestArray.set(1.0, 1.0);
    double k = 1.0;
    for (int i = 0; i < myTestArray.rows(); i++ )
    {
        for (int j = 0; j < myTestArray.cols(); j++)
        {
            EXPECT_EQ(myTestArray(i, j), k);
            k += 1.0;
        }
    } 
}

// Test Array::operator() - Check out-of-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessParenthesis_outOfBounds)
{
    Array<double> myTestArray(4, 7);
    EXPECT_THROW(myTestArray(3,7), std::out_of_range);
    EXPECT_THROW(myTestArray(4,6), std::out_of_range);
    EXPECT_THROW(myTestArray(3,-1), std::out_of_range);
    EXPECT_THROW(myTestArray(-1,6), std::out_of_range);
}

// Test Array::operator[] - Check in-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessBracket_inBounds)
{
    Array<double> myTestArray(4, 7);
    myTestArray.set(1.0, 1.0);
    double k = 1.0;
    for (int i = 0; i < myTestArray.size(); i++ )
    {
        EXPECT_EQ(myTestArray[i], k);
        k += 1.0;
    } 
}

// Test Array::operator[] - Check out-of-bounds access
TEST_F(ArrayUnitTest, checkOperatorAccessBracket_outOfBounds)
{
    Array<double> myTestArray(4, 7);
    EXPECT_THROW(myTestArray[28], std::out_of_range);
    EXPECT_THROW(myTestArray[-1], std::out_of_range);
}

// Test Array::operator* (Array * scalar) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorMultiply_ArrayScalar)
{
    Array<double> myTestArray(4, 2);
    myTestArray.set(2.0);
    myTestArray = myTestArray * 2;
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], 4.0);
    }
}

// Test Array::operator* (scalar * Array) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorMultiply_ScalarArray)
{
    Array<double> myTestArray(4, 2);
    myTestArray.set(2.0);
    myTestArray = 2 * myTestArray;
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], 4.0);
    }
}

// Test Array::rows() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyRows)
{
    Array<double> myTestArray(3, 6);
    EXPECT_EQ(myTestArray.rows(), 3);
}

// Test Array::getMyColumnss() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyColumns)
{
    Array<double> myTestArray(3, 6);
    EXPECT_EQ(myTestArray.cols(), 6);
}

// Test Array::size() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyElements)
{
    Array<double> myTestArray(3, 6);
    EXPECT_EQ(myTestArray.size(), 18);
}

// Test Array::getMyArray() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMyArray)
{
    Array<double> myTestArray(3, 3);
    myTestArray.set(1.0, 1.0);
    std::vector<double> tmp;
    tmp = myTestArray.data();
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(tmp[i], myTestArray[i]);
    }
}

// Test Array::getArrayProperties() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetArrayProperties_none)
{
    Array<double> myTestArray(4, 3);
    std::vector<bool> exp_prop{false, false, true};
    EXPECT_EQ(Support::ArraySupport::getArrayProperties(myTestArray), exp_prop);
}

// Test Array::getArrayProperties() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetArrayProperties_sq)
{
    Array<double> myTestArray(3, 3);
    std::vector<bool> exp_prop{false, true, true};
    EXPECT_EQ(Support::ArraySupport::getArrayProperties(myTestArray), exp_prop);
}

// Test Array::getArrayProperties() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetArrayProperties_sq_id)
{
    Array<double> myTestArray(3, 3);
    myTestArray.identity();
    std::vector<bool> exp_prop{true, true, false};
    EXPECT_EQ(Support::ArraySupport::getArrayProperties(myTestArray), exp_prop);
}

// Test Array::getArrayProperties() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetArrayProperties_sq_sin_6_3_5_a)
{
    std::vector<bool> exp_prop{false, true, true};
    EXPECT_EQ(Support::ArraySupport::getArrayProperties(*myArray1), exp_prop);
}

// Test Array::getArrayProperties() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetArrayProperties_sq_sin_6_3_5_c)
{
    std::vector<bool> exp_prop{false, true, true};
    EXPECT_EQ(Support::ArraySupport::getArrayProperties(*myArray3), exp_prop);
}

// Test Array::operator+ (Array + Array) - Catch invalid demnsions
TEST_F(ArrayUnitTest, checkOperatorAdd_invalidDimensions)
{
    Array<double> myTestArray1(3, 3);
    Array<double> myTestArray2(3, 4);
    Array<double> myTestArray3(3, 3);
    EXPECT_THROW(myTestArray3 = myTestArray1 + myTestArray2, std::length_error);
}

// Test Array::operator+ (Array + Array) - Make calculation is correct
TEST_F(ArrayUnitTest, checkOperatorAdd_validDimensions)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(2.0);
    Array<double> myTestArray3(3, 3);
    myTestArray3.zeros();
    myTestArray3 = myTestArray1 + myTestArray2;
    for (int i = 0; i < myTestArray1.size(); i++)
    {
        EXPECT_EQ(myTestArray3[i], 3.0);
    }
}

// Test Array::operator- (Array - Array) - Catch invalid demnsions
TEST_F(ArrayUnitTest, checkOperatorSubtract_invalidDimensions)
{
    Array<double> myTestArray1(3, 3);
    Array<double> myTestArray2(3, 4);
    Array<double> myTestArray3(3, 3);
    EXPECT_THROW(myTestArray3 = myTestArray1 - myTestArray2, std::length_error);
}

// Test Array::operator- (Array - Array) - Make calculation is correct
TEST_F(ArrayUnitTest, checkOperatorSubtract_validDimensions)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(3.0);
    Array<double> myTestArray3(3, 3);
    myTestArray3.zeros();
    myTestArray3 = myTestArray2 - myTestArray1;
    for (int i = 0; i < myTestArray1.size(); i++)
    {
        EXPECT_EQ(myTestArray3[i], 2.0);
    }
}

// Test Array::operator- (-1 * Array) - Make sure calculation is correct
TEST_F(ArrayUnitTest, checkOperatorSubtract_negativeArray)
{
    Array<double> myTestArray(3, 3);
    myTestArray.set(2.0);
    myTestArray = -myTestArray;
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(myTestArray[i], -2.0);
    }
}

// Test Array::data - Make sure getter works
TEST_F(ArrayUnitTest, checkData)
{
    Array<double> myTestArray(3, 4);
    myTestArray.set(2.0, 1.0);
    std::vector<double> tmp = myTestArray.data();
    for (int i = 0; i < myTestArray.size(); i++)
    {
        EXPECT_EQ(tmp.at(i), myTestArray[i]);
    }
}

// Test Array::trace() - Make sure calculation is correct (invalid dimensions)
TEST_F(ArrayUnitTest, checkGetTrace_invalidDimensions)
{
    Array<double> myTestArray(3, 4);
    EXPECT_THROW(myTestArray.trace(), std::length_error);
}

// Test Array::trace() - Make sure calculation is correct (valid dimensions)
TEST_F(ArrayUnitTest, checkGetTrace_validDimensions)
{
    Array<double> myTestArray(3, 3);
    myTestArray.set(1.0, 1.0);
    EXPECT_EQ(myTestArray.trace(), 15.0);
}

// Test Array::operator= - Make sure move assignment works
TEST_F(ArrayUnitTest, checkMoveAssignment)
{
    Array<double> myTestArray1(3, 3);
    Array<double> myTestArray2(3, 3);
    myTestArray1.set(1.0, 1.0);
    myTestArray2 = std::move(myTestArray1);
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    double j = 1.0;
    for (int i = 0; i < myTestArray2.size(); i++ )
    {
        EXPECT_EQ(myTestArray2[i], j);
        j += 1.0;
    } 
}

// Test Array(&&Array) - Make sure Move construtor works
TEST_F(ArrayUnitTest, checkMoveConstructor)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2 = std::move(myTestArray1);
    ASSERT_EQ(myTestArray2.rows(), myTestArray1.cols());
    ASSERT_EQ(myTestArray2.cols(), myTestArray1.rows());
    ASSERT_EQ(myTestArray2.size(), myTestArray1.size()); 
    double j = 1.0;
    for (int i = 0; i < myTestArray2.size(); i++ )
    {
        EXPECT_EQ(myTestArray2[i], j);
        j += 1.0;
    } 
}

// Test Array::swap() - Make sure swap function works
TEST_F(ArrayUnitTest, checkSwap)
{
    Array<double> myTestArray1(3, 3);
    Array<double> myTestArray2(5, 3);
    swap(myTestArray1, myTestArray2);
    ASSERT_EQ(myTestArray2.rows(), 3);
    ASSERT_EQ(myTestArray1.rows(), 5);
    ASSERT_EQ(myTestArray2.cols(), 3);
    ASSERT_EQ(myTestArray1.cols(), 3);
    ASSERT_EQ(myTestArray2.size(), 9);
    ASSERT_EQ(myTestArray1.size(), 15);
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_differentSize)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(4, 3);
    myTestArray2.ones();
    ASSERT_FALSE(Support::ArraySupport::compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_differentElements)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(2.0, 1.0);
    ASSERT_FALSE(Support::ArraySupport::compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_outOfDefaultTolerance)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    myTestArray1(0, 0) = 1.002;
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    ASSERT_FALSE(Support::ArraySupport::compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (false)
TEST_F(ArrayUnitTest, checkCompare_outOfSpecifiedTolerance)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    myTestArray1(0, 0) = 1.0000002;
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    ASSERT_FALSE(Support::ArraySupport::compare(myTestArray1, myTestArray2, 1e-07));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_inDefaultTolerance)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    myTestArray1(0, 0) = 1.0000002;
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray1, myTestArray2));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_inSpecifiedTolerance)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(1.0, 1.0);
    myTestArray1(0, 0) = 1.00000002;
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray1, myTestArray2, 1e-07));
}

// Test Array::compare() - Make sure compare function works (true)
TEST_F(ArrayUnitTest, checkCompare_same)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.set(2.0, 2.0);
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(2.0, 2.0);
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray1, myTestArray2));
}

// Test Array::operator* - Catch invalid dimensions
TEST_F(ArrayUnitTest, checkOperatorMultiply_invalidDimensions)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(4, 3);
    myTestArray2.ones();
    Array<double> myTestArray3(3, 3);
    myTestArray3.zeros();
    EXPECT_THROW(myTestArray3 = myTestArray1 * myTestArray2, std::length_error);
}

// Test Array::operator* - Mxn * n*K
TEST_F(ArrayUnitTest, checkOperatorMultiply_Mn_nK)
{
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    Array<double> myTestArray3(3, 3);
    myTestArray3.zeros();
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
    Array<double> myTestArray1(2, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(3, 3);
    myTestArray2.set(1.0, 1.0);
    Array<double> myTestArray3(2, 3);
    myTestArray3.zeros();
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
    Array<double> myTestArray1(3, 3);
    myTestArray1.ones();
    Array<double> myTestArray2(3, 2);
    myTestArray2.set(1.0, 1.0);
    Array<double> myTestArray3(3, 2);
    myTestArray3.zeros();
    myTestArray3 = myTestArray1 * myTestArray2;
    EXPECT_EQ(myTestArray3(0, 0), 9);
    EXPECT_EQ(myTestArray3(0, 1), 12);
    EXPECT_EQ(myTestArray3(1, 0), 9);
    EXPECT_EQ(myTestArray3(1, 1), 12);
    EXPECT_EQ(myTestArray3(2, 0), 9);
    EXPECT_EQ(myTestArray3(2, 1), 12);
}

TEST_F(ArrayUnitTest, checkPrintArray_squareArray)
{
    Array<double> arr(4, 4);
    arr.set(1, 1);
    std::string arr_p = Support::ArraySupport::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 10 | 11 | 12 |\n| 13 | 14 | 15 | 16 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST_F(ArrayUnitTest, checkPrintArray_moreRows)
{
    Array<double> arr(4, 3);
    arr.set(1, 1);
    std::string arr_p = Support::ArraySupport::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 |\n| 4 | 5 | 6 |\n| 7 | 8 | 9 |\n| 10 | 11 | 12 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST_F(ArrayUnitTest, checkPrintArray_moreCols)
{
    Array<double> arr(3, 4);
    arr.set(1, 1);
    std::string arr_p = Support::ArraySupport::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 10 | 11 | 12 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST_F(ArrayUnitTest, checkPrintArrayInfo_squareArray)
{
    Array<double> arr(3, 3);
    std::string arr_i = Support::ArraySupport::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 3x3\nElements - 9"; 
    EXPECT_EQ(arr_i, expectedString); 
}

TEST_F(ArrayUnitTest, checkPrintArrayInfo_moreRows)
{
    Array<double> arr(4, 3);
    std::string arr_i = Support::ArraySupport::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 4x3\nElements - 12"; 
    EXPECT_EQ(arr_i, expectedString); 
}

TEST_F(ArrayUnitTest, checkPrintArrayInfo_moreCols)
{
    Array<double> arr(3, 5);
    std::string arr_i = Support::ArraySupport::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 3x5\nElements - 15"; 
    EXPECT_EQ(arr_i, expectedString); 
}

// Test: Array::getMinor() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetMinor)
{
    Array<double> myTestArray(myArray5->g_minor());
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray, *myArray5Minor));
}

// Test: Array::getCofactor() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetCofactor)
{
    Array<double> myTestArray(myArray5->g_cofactor());
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray, *myArray5Cofactor));
}

// Test: Array::getAdjugate() - Make sure getter works
TEST_F(ArrayUnitTest, checkGetAdjugate)
{
    Array<double> myTestArray(myArray5->g_adjugate());
    ASSERT_TRUE(Support::ArraySupport::compare(myTestArray, *myArray5Adjugate));
}