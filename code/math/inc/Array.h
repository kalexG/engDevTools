// Filename: Array.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <utility>

class Array
{
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
        // Setter Function: setIncrement
        void setIncrement(double = 0.0, double = 1.0);
        // Getter Function: getRows
        unsigned int getRows(void);
        // Getter Function getCols
        unsigned int getCols(void);
        // Getter Function getElems
        unsigned int getElems(void);
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
        // Data: array
        double* array;
};

class Matrix : public Array
{
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
    // Member Functions
    public:
        // Constructor
        Vector() : Array(3, 1) {}
        // Access Operator: ()
        double &operator() (unsigned int row);
        // Getter Function getUnitVector
        Vector getUnitVector(void);
        // Getter Function getMagnitude
        double getMagnitude(void);
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
