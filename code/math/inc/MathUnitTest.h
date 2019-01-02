// MathUnitTest.cpp

#ifndef MATHUNITTEST_H
#define MATHUNITTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../inc/Array.h"
#include "../inc/Matrix.h"
#include "../inc/Vector.h"

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

#endif
