//--------------------------
// Filename: Array.h
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

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
    
    lapack_int LAPACKE_dgetrf( int, lapack_int, lapack_int,
                               double*, lapack_int, lapack_int* );
    
    lapack_int LAPACKE_dgetri( int, lapack_int, double*,
                               lapack_int, const lapack_int* );

    void cblas_dgemm(CBLAS_LAYOUT, CBLAS_TRANSPOSE, CBLAS_TRANSPOSE, 
                    int, int, int, double, const double*, int, 
                    const double*, int, double, double*, int);
}

class Array;
bool compare(Array& arr1, Array& arr2, double tol = 1.0e-06);

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
        // Move Constructor [UT: Y]
        Array(Array&& arr) noexcept;
        // Assignment Operator: [UT: Y]
        Array& operator= (Array arr) noexcept;
        // Destructor [UT: N]
        virtual ~Array(void);
        // Setter Function: setZeros [UT: Y]
        void setZeros(void);
        // Setter Function: setOnes [UT: Y]
        void setOnes(void);
        // Setter Function: setTo [UT: Y]
        void setTo(const double);
        // Setter Function: setIncrement [UT: Y]
        void setIncrement(const double = 0.0, const double = 1.0);
        // Setter Function: setIdentity [UT: Y]
        void setIdentity(void);
        // Setter Function: setTranspose [UT: Y]
        void setTranspose(void);
        // Setter Function: getTranspose [UT: Y]
        Array getTranspose(void);
        // Setter Function: setInverse [UT: N]
        void setInverse(void);
        // Setter Function: getInverse [UT: N]
        Array getInverse(void);
        // Setter Function: getDeterminant [UT: N]
        double getDeterminant(void);
        // Getter Function: getMyRows [UT: Y]
        int getMyRows(void);
        // Getter Function: getMyCols [UT: Y]
        int getMyCols(void);
        // Getter Function: getMyElements [UT: Y]
        int getMyElements(void);
        // Getter Function: getMyArray [UT: Y]
        double* getMyArray(void);
        // Getter Function: getMyArraySize [UT: Y]
        std::size_t getMyArraySize(void);
        // Getter Function: getArrayProperties [UT: Y]
        std::vector<bool> getArrayProperties(void);
        // Getter Function: getTrace [UT: Y]
        double getTrace(void);
        // Getter Function: getStdVector1D [UT: Y]
        std::vector<double> getStdVector1D(void);
        // Getter Function: getStdVector2D [UT: Y]
        std::vector<std::vector<double>> getStdVector2D(void);
        // Access Operator: () [UT: Y]
        double &operator() (int row, int col);
        // Access Operator: [] [UT: Y]
        double &operator[] (int index);
        // Arithmetic Operator: + [UT: Y]
        Array operator+ (const Array& arr) const;
        // Arithmetic Operator: - [UT: Y]
        Array operator- (const Array& arr) const;
        // Artithmetic Operator: - [UT: Y]
        Array operator- (void) const;
        // Arithmetic Operator: * [UT: Y]
        Array operator* (const double scalar) const;
        // Arithmetic Operator: * [UT: Y]
        Array operator* (const Array& arr) const;
        // Arithmetic Operator: * [UT: Y]
        friend Array operator* (const double scalar, const Array &arr);
        // Function: swap [UT: Y]
        friend void swap(Array& arr1, Array& arr2);
        // Function: compare [UT: Y]
        friend bool compare(Array& arr1, Array& arr2, double tol);
        // Function: Print Array Contents [UT: Y]
        std::string printArray(void);
        // Function: Print Array Info [UT: Y]
        std::string printArrayInfo(void);
    private:
        // Function: checkValidDims [UT: N]
        bool checkValidDims(int rows, int cols);
        // Function: checkSquare [UT: N]
        bool checkSquare();
        // Function: checkSingular [UT: N]
        bool checkSingular();
        // Function: checkIdentity [UT: N]
        bool checkIdentity();
    protected:

    // Member Data
    public:
    private:
        // Data: validDims
        bool validDims;
    protected:
        // Data: enum for property identification
        enum Properties
        {
            IDENTITY,
            SQUARE,
            SINGULAR,
            MAX_PROPERTIES
        };
        // Array myProperties
        std::vector<bool> myProperties;
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
};

#endif
