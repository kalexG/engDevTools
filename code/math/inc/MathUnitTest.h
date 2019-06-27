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
