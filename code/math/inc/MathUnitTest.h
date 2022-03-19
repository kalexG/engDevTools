//--------------------------
// Filename: MathUnitTest.h
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#ifndef MATHUNITTEST_H
#define MATHUNITTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Array.h"
#include "../inc/Matrix.h"
#include "../inc/Vector.h"
#include "../inc/LongVector.h"
#include "../inc/Integrator.h"
#include "../inc/IntegratorMidpoint.h"
#include "../inc/IntegratorSimps.h"
#include "../inc/IntegratorTrapz.h"
#include "../inc/NumericalMethods.h"

using ::testing::DoubleNear;
using ::testing::ElementsAre;

using namespace NumericalMethods;

class MockVector : public Vector
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

class MockMatrix : public Matrix 
{
    public:
        MockMatrix() : Matrix() {}
        MOCK_METHOD0(Destruct, void());
        virtual ~MockMatrix() { Destruct(); }
};

class MatrixUnitTest : public ::testing::Test
{
    public:
        Matrix myMatrix1;
        Matrix myMatrix1Minor;
        Matrix myMatrix1Cofactor;
        Matrix myMatrix1Adjugate;
        double myMatrix1Determinant;
        MatrixUnitTest()
        {
            // Matrix for Testing: myMatrix1
            myMatrix1(0,0) = 3; myMatrix1(0,1) = 0; myMatrix1(0,2) = 2;
            myMatrix1(1,0) = 2; myMatrix1(1,1) = 0; myMatrix1(1,2) = -2;
            myMatrix1(2,0) = 0; myMatrix1(2,1) = 1; myMatrix1(2,2) = 1;
            // Minor of myMatrix1: myMatrix1Minor
            myMatrix1Minor(0,0) = 2; myMatrix1Minor(0,1) = 2; myMatrix1Minor(0,2) = 2;
            myMatrix1Minor(1,0) = -2; myMatrix1Minor(1,1) = 3; myMatrix1Minor(1,2) = 3;
            myMatrix1Minor(2,0) = 0; myMatrix1Minor(2,1) = -10; myMatrix1Minor(2,2) = 0;
            // Cofactor of myMatrix1: myMatrix1Cofactor
            myMatrix1Cofactor(0,0) = 2; myMatrix1Cofactor(0,1) = -2; myMatrix1Cofactor(0,2) = 2;
            myMatrix1Cofactor(1,0) = 2; myMatrix1Cofactor(1,1) = 3; myMatrix1Cofactor(1,2) = -3;
            myMatrix1Cofactor(2,0) = 0; myMatrix1Cofactor(2,1) = 10; myMatrix1Cofactor(2,2) = 0;
            // Adjugate of myMatrix1: myMatrix1Adjugate
            myMatrix1Adjugate(0,0) = 2; myMatrix1Adjugate(0,1) = 2; myMatrix1Adjugate(0,2) = 0;
            myMatrix1Adjugate(1,0) = -2; myMatrix1Adjugate(1,1) = 3; myMatrix1Adjugate(1,2) = 10;
            myMatrix1Adjugate(2,0) = 2; myMatrix1Adjugate(2,1) = -3; myMatrix1Adjugate(2,2) = 0;
            // Determinant of myMatrix1: myMatrix1Determinant
            myMatrix1Determinant = 10;
        }
    private:
    protected:
};

class MockArray : public Array 
{
    public:
        MockArray(int rows, int cols) : Array(rows, cols) {}
        MOCK_METHOD0(Destruct, void());
        virtual ~MockArray() { Destruct(); }
};

class ArrayUnitTest : public ::testing::Test
{
    public:
        Array* myArray1;
        Array* myArray2;
        Array* myArray2_inv;
        Array* myArray3;
        Array* myArray4;
        Array* myArray4_inv;
        ArrayUnitTest()
        {
            myArray1 = new Array(3,3);
            myArray2 = new Array(3,3);
            myArray2_inv = new Array(3,3);
            myArray3 = new Array(4,4);
            myArray4 = new Array(4,4);
            myArray4_inv = new Array(4,4);
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
        }
    private:
    protected:
};

class IntegratorMidpointUnitTest : public ::testing::Test
{
    public:
    private:
    protected:
};

class IntegratorSimpsUnitTest : public ::testing::Test
{
    public:
    private:
    protected:
};

class IntegratorTrapzUnitTest : public ::testing::Test
{
    public:
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
