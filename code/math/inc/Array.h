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
#include <vector>

extern "C" 
{
    #include <lapacke/lapacke.h>
    #include <cblas/cblas.h>
    void LAPACKE_dge_trans( int, lapack_int, lapack_int,
                            const double*, lapack_int,
                            double*, lapack_int );

    void cblas_dgemm(CBLAS_LAYOUT, CBLAS_TRANSPOSE, CBLAS_TRANSPOSE, 
                    int, int, int, double, const double*, int, 
                    const double*, int, double, double*, int);
}

class Array
{
    // Class for unit testing
    friend class ArrayUnitTest;

    // Member Functions
    public:
        // Constructor [UT: Y]
        Array(int rows, int cols);
        // Copy Constructor [UT: Y]
        Array(const Array& arr);
        // Move Constructor [UT: TODO]
        Array(Array&& arr) noexcept;
        // Assignment Operator: Copy [UT: Y]
        Array& operator=(const Array& arr);
        // Assignment Operator: Move [UT: TODO]
        Array& operator=(Array&& arr) noexcept;
        // Destructor [UT: Y]
        virtual ~Array(void);
        // Setter Function: setZeros [UT: Y]
        void setZeros(void);
        // Setter Function: setOnes [UT: Y]
        void setOnes(void);
        // Setter Function: setTo [UT: Y]
        void setTo(const double);
        // Setter Function: setIncrement [UT: Y]
        void setIncrement(const double = 0.0, const double = 1.0);
        // Setter Function: setIdentity [UT: TODO]
        void setIdentity(void);
        // Setter Function: setTranspose [UT: Y]
        void setTranspose(void);
        // Setter Function: getTranspose [UT: Y]
        Array getTranspose(void);
        // Getter Function: getMyRows [UT: Y]
        int getMyRows(void);
        // Getter Function: getMyCols [UT: Y]
        int getMyCols(void);
        // Getter Function: getMyElements [UT: Y]
        int getMyElements(void);
        // Getter Function: getMyArray [UT: TODO]
        double* getMyArray(void);
        // Getter Function: getMyArraySize [UT: TODO]
        std::size_t getMyArraySize(void);
        // Getter Function: getIsSquare [UT: Y]
        bool getIsSquare(void);
        // Getter Function: getTrace [UT: TODO]
        double getTrace(void);
        // Getter Function: getStdVector1D [UT: TODO]
        std::vector<double> getStdVector1D(void);
        // Getter Function: getStdVector2D [UT: TODO]
        std::vector<std::vector<double>> getStdVector2D(void);
        // Access Operator: () [UT: TODO]
        double &operator() (int row, int col);
        // Access Operator: [] [UT: TODO]
        double &operator[] (int index);
        // Arithmetic Operator: + [UT: TODO]
        Array operator+ (const Array& arr) const;
        // Arithmetic Operator: - [UT: TODO]
        Array operator- (const Array& arr) const;
        // Artithmetic Operator: - [UT: TODO]
        Array operator- (void) const;
        // Arithmetic Operator: * [UT: TODO]
        Array operator* (const double scalar) const;
        // Arithmetic Operator: * [UT: TODO]
        Array operator* (const Array& arr) const;
        // Arithmetic Operator: * [UT: TODO]
        friend Array operator* (const double scalar, const Array &arr);
        // Function: swap [UT: TODO]
        friend void swap(Array& arr1, Array& arr2);
        // Function: compare [UT: TODO]
        friend bool compare(Array& arr1, Array& arr2, const double tol = 1e-06);
    private:
        // Function: checkValidDims [UT: Y]
        bool checkValidDims(int rows, int cols);
        // Function: checkSquare [UT: Y]
        bool checkSquare(int rows, int cols);
    protected:

    // Member Data
    public:
    private:
        // Data: validDims
        bool validDims;
    protected:
        // Data: myRows
        int myRows;
        // Data: myCols
        int myCols;
        // Data: myElements
        int myElements;
        // Data: myArray
        double* myArray;
        // Data: myArraySize
        std::size_t myArraySize;
        // Data: isSquare
        bool isSquare;
};

#endif
