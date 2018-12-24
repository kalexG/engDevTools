// Filename: Array.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include <tuple>
#include <typeinfo>
using namespace std;

class Array
{
    // Functions
    public:
        Array(int rows, int cols);
        
        /*Array(const Array& arr)
        : Array(arr.myRows, arr.myCols)
        {}

        Array& operator=(Array arr)
        {
            swap(array, arr.array);
            return *this;
        }
        
        Array(Array&& arr) noexcept
        : array(exchange(arr.array, nullptr))
        {}
        Array& operator=(Array&& arr) noexcept
        {
            swap(array, arr.array);
            return *this;
        }*/
        virtual ~Array( void );
        void setZeros(void);
        void setOnes(void);
        void setIncrement(double = 0.0, double = 1.0);
        int getRows(void);
        int getCols(void);
        double &operator() (unsigned int row, unsigned int col);
        double &operator[] (unsigned int index);
        Array operator+(const Array& a);
        // TODO: Add Operator
        // TODO: Subtract Operator
        // TODO: Multiply Operator
    private:
        void initArray( void );
        void freeArray( void );
        static bool validateDim(const int dim)
        {
            try
            {
                return (dim > 0) ? true : throw false;
            }
            catch (bool errorFlag)
            {
                printf("ERROR: Invalid array dimensions! Check array object parameters.\n");
                exit(0);
            }
        }
    protected:

    // Data
    public:
    private:
        bool validRows;
        bool validCols;
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
