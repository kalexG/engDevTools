// Filename: Matrix.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

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
    private:
    protected:

    // Member Data
    public:
    private:
    protected:
};

#endif
