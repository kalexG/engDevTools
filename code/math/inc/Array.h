// Filename: Array.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <math.h>
#include <utility>
#include <algorithm>
#include <stdio.h>

extern "C" 
{
    #include <lapacke/lapacke.h>
    void LAPACKE_dge_trans( int, lapack_int, lapack_int,
                            const double*, lapack_int,
                            double*, lapack_int );

    void dgemm_(char*, char*, const int*,
                   const int*, const int*, double*, double*,
                   const int*, double*, const int*, double*,
                   double*, const int*);
}

class Array
{
    // Class for unit testing
    friend class ArrayUnitTest;

    // Member Functions
    public:
        // Constructor
        Array(unsigned int rows, unsigned int cols);
        // Copy Constructor
        Array(const Array& arr);
        // Move Constructor
        Array(Array&& arr) noexcept;
        // Assignment Operator: Copy
        Array& operator=(const Array& arr);
        // Assignment Operator: Move
        Array& operator=(Array&& arr) noexcept;
        // Destructor
        virtual ~Array(void);
        // Setter Function: setZeros
        void setZeros(void);
        // Setter Function: setOnes
        void setOnes(void);
        // Setter Function: setTo
        void setTo(const double);
        // Setter Function: setIncrement
        void setIncrement(const double = 0.0, const double = 1.0);
        // Setter Function: setIdentity
        void setIdentity(void);
        // Setter Function: setTranspose
        void setTranspose(void);
        // Getter Function: getMyRows
        unsigned int getMyRows(void);
        // Getter Function: getMyCols
        unsigned int getMyCols(void);
        // Getter Function: getMyElements
        unsigned int getMyElements(void);
        // Getter Function: getMyArray
        double* getMyArray(void);
        // Getter Function: getIsSquare
        bool getIsSquare(void);
        // Getter Function: getTrace
        double getTrace(void);
        // Access Operator: ()
        double &operator() (unsigned int row, unsigned int col);
        // Access Operator: []
        double &operator[] (unsigned int index);
        // Arithmetic Operator: +
        Array operator+ (const Array& arr) const;
        // Arithmetic Operator: -
        Array operator- (const Array& arr) const;
        // Artithmetic Operator: -
        Array operator- (void) const;
        // Arithmetic Operator: *
        Array operator* (const double scalar)const;
        // Arithmetic Operator: *
        friend Array operator* (const double scalar, const Array &arr);
        // Function: swap
        friend void swap(Array& arr1, Array& arr2);
    private:
        // Function: initArray
        void initArray(void);
        // Function: freeArray
        void freeArray(void);
        // Function: checkSquare
        bool checkSquare(unsigned int rows, unsigned int cols);
    protected:

    // Member Data
    public:
    private:
    protected:
        // Data: myRows
        unsigned int myRows;
        // Data: myCols
        unsigned int myCols;
        // Data: myElements
        unsigned int myElements;
        // Data: myArray
        double* myArray;
        // Data: myArraySize
        std::size_t myArraySize;
        // Data: isSquare
        bool isSquare;
};

class Matrix : public Array
{
    // Class for unit testing
    friend class MatrixUnitTest;
    
    // Member Functions
    public:
        // Constructor
        Matrix() : Array(3, 3) {}
    private:
    protected:

    // Member Data
    public:
    private:
    protected:
};

class Vector : public Array
{
    // Class for unit testing
    friend class VectorUnitTest;
    
    // Member Functions
    public:
        // Constructor
        Vector() : Array(3, 1) {}
        // Access Operator: ()
        double &operator() (unsigned int row);
        // Getter Function getMagnitude
        double getMagnitude(void);
        // Function unitVector
        friend Vector unitVector(Vector& vec);
        // Function: crossProduct
        friend Vector crossProduct(Vector& vec1, Vector& vec2);
        // Function: dotProduct
        friend double dotProduct(Vector& vec1, Vector& vec2);
    private:
    protected:
    
    // Member Data
    public:
    private:
    protected:
};

#endif
