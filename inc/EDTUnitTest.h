#ifndef EDT_UNITTEST_H
#define EDT_UNITTEST_H

#include <gtest.h>
#include <gmock.h>
#include "Array.h"
#include "Matrix.h"
#include "Vector.h"
#include "NumericalMethods.h"
#include "NumericalMethodsUtilities.h"
#include "ArrayUtilities.h"

using ::testing::DoubleNear;
using ::testing::ElementsAre;

class MockVector : public Vector<double>
{
    public:
        MockVector() : Vector() {}
        MOCK_METHOD0(Destruct, void());
        virtual ~MockVector() { Destruct(); }
};

class VectorUnitTest : public ::testing::Test
{
    public:
    private:
    protected:
};

class MockMatrix : public Matrix<double> 
{
    public:
        MockMatrix() : Matrix() {}
        MOCK_METHOD0(Destruct, void());
        virtual ~MockMatrix() { Destruct(); }
};

class MatrixUnitTest : public ::testing::Test
{
    public:
        MatrixUnitTest() {}
    private:
    protected:
};

class MockArray : public Array<double> 
{
    public:
        MockArray(int rows, int cols) : Array(rows, cols) {}
        MOCK_METHOD0(Destruct, void());
        virtual ~MockArray() { Destruct(); }
};

class ArrayUnitTest : public ::testing::Test
{
    public:
        Array<double>* myArray1;
        Array<double>* myArray2;
        Array<double>* myArray2_inv;
        Array<double>* myArray3;
        Array<double>* myArray4;
        Array<double>* myArray4_inv;
        Array<double>* myArray5;
        Array<double>* myArray5Minor;
        Array<double>* myArray5Cofactor;
        Array<double>* myArray5Adjugate;
        double myArray5Determinant;
        ArrayUnitTest()
        {
            myArray1 = new Array<double>(3,3);
            myArray2 = new Array<double>(3,3);
            myArray2_inv = new Array<double>(3,3);
            myArray3 = new Array<double>(4,4);
            myArray4 = new Array<double>(4,4);
            myArray4_inv = new Array<double>(4,4);
            myArray5 = new Array<double>(3,3);
            myArray5Minor = new Array<double>(3,3);
            myArray5Cofactor = new Array<double>(3,3);
            myArray5Adjugate = new Array<double>(3,3);
            // Array for Testing: myArray1 (singular)
            myArray1->operator()(0,0) = 4;  myArray1->operator()(0,1) = 2;  myArray1->operator()(0,2) = 6;
            myArray1->operator()(1,0) = 3;  myArray1->operator()(1,1) = 0;  myArray1->operator()(1,2) = 7;
            myArray1->operator()(2,0) = -2; myArray1->operator()(2,1) = -1; myArray1->operator()(2,2) = -3;
            // Array for Testing: myArray2
            myArray2->operator()(0,0) = 1; myArray2->operator()(0,1) = 2; myArray2->operator()(0,2) = 0;
            myArray2->operator()(1,0) = 2; myArray2->operator()(1,1) = 1; myArray2->operator()(1,2) = -1;
            myArray2->operator()(2,0) = 3; myArray2->operator()(2,1) = 1; myArray2->operator()(2,2) = 1;
            // Array for Testing: myArray2_inv
            myArray2_inv->operator()(0,0) = -1.0/4.0; myArray2_inv->operator()(0,1) = 1.0/4.0;   myArray2_inv->operator()(0,2) = 1.0/4.0;
            myArray2_inv->operator()(1,0) = 5.0/8.0; myArray2_inv->operator()(1,1) = -1.0/8.0; myArray2_inv->operator()(1,2) = -1.0/8.0;
            myArray2_inv->operator()(2,0) = 1.0/8.0; myArray2_inv->operator()(2,1) = -5.0/8.0; myArray2_inv->operator()(2,2) = 3.0/8.0;
            // Array for Testing: myArray3 (singular)
            myArray3->operator()(0,0) = 1;  myArray3->operator()(0,1) = 1; myArray3->operator()(0,2) = -1; myArray3->operator()(0,3) = 1;
            myArray3->operator()(1,0) = 1;  myArray3->operator()(1,1) = 2; myArray3->operator()(1,2) = -4; myArray3->operator()(1,3) = -2;
            myArray3->operator()(2,0) = 2;  myArray3->operator()(2,1) = 1; myArray3->operator()(2,2) = 1;  myArray3->operator()(2,3) = 5;
            myArray3->operator()(3,0) = -1; myArray3->operator()(3,1) = 0; myArray3->operator()(3,2) = -2; myArray3->operator()(3,3) = -4;
            // Array for Testing: myArray4
            myArray4->operator()(0,0) = 4; myArray4->operator()(0,1) = 0;  myArray4->operator()(0,2) = 0; myArray4->operator()(0,3) = 0;
            myArray4->operator()(1,0) = 6; myArray4->operator()(1,1) = 7;  myArray4->operator()(1,2) = 0; myArray4->operator()(1,3) = 0;
            myArray4->operator()(2,0) = 9; myArray4->operator()(2,1) = 11; myArray4->operator()(2,2) = 1; myArray4->operator()(2,3) = 0;
            myArray4->operator()(3,0) = 5; myArray4->operator()(3,1) = 4;  myArray4->operator()(3,2) = 1; myArray4->operator()(3,3) = 1;
            // Array for Testing: myArray4_inv
            myArray4_inv->operator()(0,0) = 1.0/4.0; myArray4_inv->operator()(0,1) = 0;  myArray4_inv->operator()(0,2) = 0; myArray4_inv->operator()(0,3) = 0;
            myArray4_inv->operator()(1,0) = -3.0/14.0; myArray4_inv->operator()(1,1) = 1.0/7.0;  myArray4_inv->operator()(1,2) = 0; myArray4_inv->operator()(1,3) = 0;
            myArray4_inv->operator()(2,0) = 3.0/28.0; myArray4_inv->operator()(2,1) = -11.0/7.0; myArray4_inv->operator()(2,2) = 1; myArray4_inv->operator()(2,3) = 0;
            myArray4_inv->operator()(3,0) = -1.0/2.0; myArray4_inv->operator()(3,1) = 1;  myArray4_inv->operator()(3,2) = -1; myArray4_inv->operator()(3,3) = 1;
            // Matrix for Testing: myArray5
            myArray5->operator()(0,0) = 3.0; myArray5->operator()(0,1) = 0.0; myArray5->operator()(0,2) = 2.0;
            myArray5->operator()(1,0) = 2.0; myArray5->operator()(1,1) = 0.0; myArray5->operator()(1,2) = -2.0;
            myArray5->operator()(2,0) = 0.0; myArray5->operator()(2,1) = 1.0; myArray5->operator()(2,2) = 1.0;
            // Minor of myArray5: myArray5Minor
            myArray5Minor->operator()(0,0) = 2.0; myArray5Minor->operator()(0,1) = 2.0; myArray5Minor->operator()(0,2) = 2.0;
            myArray5Minor->operator()(1,0) = -2.0; myArray5Minor->operator()(1,1) = 3.0; myArray5Minor->operator()(1,2) = 3.0;
            myArray5Minor->operator()(2,0) = 0.0; myArray5Minor->operator()(2,1) = -10.0; myArray5Minor->operator()(2,2) = 0.0;
            // Cofactor of myArray5: myArray5Cofactor
            myArray5Cofactor->operator()(0,0) = 2.0; myArray5Cofactor->operator()(0,1) = -2.0; myArray5Cofactor->operator()(0,2) = 2.0;
            myArray5Cofactor->operator()(1,0) = 2.0; myArray5Cofactor->operator()(1,1) = 3.0; myArray5Cofactor->operator()(1,2) = -3.0;
            myArray5Cofactor->operator()(2,0) = 0.0; myArray5Cofactor->operator()(2,1) = 10.0; myArray5Cofactor->operator()(2,2) = 0.0;
            // Adjugate of myArray5: myArray5Adjugate
            myArray5Adjugate->operator()(0,0) = 2.0; myArray5Adjugate->operator()(0,1) = 2.0; myArray5Adjugate->operator()(0,2) = 0.0;
            myArray5Adjugate->operator()(1,0) = -2.0; myArray5Adjugate->operator()(1,1) = 3.0; myArray5Adjugate->operator()(1,2) = 10.0;
            myArray5Adjugate->operator()(2,0) = 2.0; myArray5Adjugate->operator()(2,1) = -3.0; myArray5Adjugate->operator()(2,2) = 0.0;
            // Determinant of myArray5: myArray5Determinant
            myArray5Determinant = 10.0;
        }
    private:
    protected:
};

class NumericalMethodsUnitTest : public ::testing::Test
{
    public:
    private:
    protected:
};

#endif
