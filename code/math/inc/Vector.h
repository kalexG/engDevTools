// Filename: Vector.h
// Created: 12/22/2018
// Last Modified: 12/22/2018
// Author: Kevin Gomez

#ifndef VECTOR_H
#define VECTOR_H

#include "../inc/Array.h"

class Vector : public Array
{
    // Class for unit testing
    friend class VectorUnitTest;
    
    // Member Functions
    public:
        // Constructor
        Vector() : Array(3, 1) {}
        // Access Operator: ()
        double &operator() (int row);
        // Getter Function getMagnitude
        double getMagnitude(void);
        // Getter Function getUnitVector
        Vector getUnitVector(void);
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
