// Filename: Array.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <utility>

class Array
{
    // Functions
    public:
        // Constructor
        Array(unsigned int rows, unsigned int cols);
        // Copy Constructor
        Array(const Array& arr);
        // Move Constructor
        Array(Array&& arr) noexcept;
        // Copy Assignment
        Array& operator=(const Array& arr);
        // Move Assignment
        Array& operator=(Array&& arr) noexcept;
        // Destructor
        virtual ~Array(void);

        void setZeros(void);
        void setOnes(void);
        void setIncrement(double = 0.0, double = 1.0);
        unsigned int getRows(void);
        unsigned int getCols(void);
        unsigned int getElems(void);
        double &operator() (unsigned int row, unsigned int col);
        double &operator[] (unsigned int index);
        Array operator+ (const Array &arr) const;
        Array operator- (const Array &arr) const;
        Array operator- (void) const;
        Array operator* (const double scalar)const;
        friend Array operator* (const double scalar, const Array &arr);
        friend void swap(Array& arr1, Array& arr2);
    private:
        void initArray(void);
        void freeArray(void);
    protected:

    // Data
    public:
    private:
    protected:
        unsigned int myRows;
        unsigned int myCols;
        unsigned int myElements;
        double* array;
};

class Matrix : public Array
{
    public:
        Matrix() : Array(3, 3) {}
    private:
    protected:

    public:
    private:
    protected:
};

class Vector : public Array
{
    public:
        Vector() : Array(3, 1) {}
        double &operator() (unsigned int row);
    private:
    protected:

    public:
    private:
    protected:
};
