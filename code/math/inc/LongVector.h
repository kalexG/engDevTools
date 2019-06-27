//--------------------------
// Filename: LongVector.h
// Created: 01/13/2018
// Last Modified: 01/13/2018
// Author: Kevin Gomez
//--------------------------

#ifndef LONGVECTOR_H
#define LONGVECTOR_H

#include "../inc/Array.h"

class LongVector : public Array
{
    // Class for unit testing
    friend class LongVectorUnitTest;
    
    // Member Functions
    public:
        // Constructor
        LongVector(int rows) : Array(rows, 1) {}
        // Access Operator: ()
        double &operator() (int row);
    private:
    protected:
    
    // Member Data
    public:
    private:
    protected:
};

#endif
