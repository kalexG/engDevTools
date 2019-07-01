//--------------------------
// Filename: Matrix.h
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#ifndef MATRIX_H
#define MATRIX_H

#include "../inc/Array.h"

class Matrix : public Array
{
    // Class for unit testing
    friend class MatrixUnitTest;
    
    // Member Functions
    public:
        // Constructor
        Matrix() : Array(3, 3) {}
        // Getter Function: getMinor [UT: N]
        Matrix getMinor(void);
        // Getter Function: getCofactor [UT: N]
        Matrix getCofactor(void);
        // Getter Function: getAdjugate [UT: N]
        Matrix getAdjugate(void);
    private:
    protected:

    // Member Data
    public:
    private:
    protected:
};

#endif
