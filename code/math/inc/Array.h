// Filename: Array.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
using namespace std;

class Array
{
    // Functions
    public:
        Array(unsigned int rows, unsigned int cols);
        Array(const Array& arr);
        virtual ~Array( void );
        void setZeros(void);
        void setOnes(void);
        void setIncrement(double = 0.0, double = 1.0);
        int getRows(void);
        int getCols(void);
        int getElems(void);
        double &operator() (unsigned int row, unsigned int col);
        double &operator[] (unsigned int index);
        Array& operator=(Array& arr);
    private:
        void initArray( void );
        void freeArray( void );
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
