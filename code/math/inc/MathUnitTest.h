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

using ::testing::DoubleNear;
using ::testing::ElementsAre;

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

#endif
