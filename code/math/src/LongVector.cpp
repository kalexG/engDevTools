//--------------------------
// Filename: LongVector.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#include "../inc/LongVector.h"

// Overload "()" Operator (Accessing: (row))
double &LongVector::operator() (int row)
{
    if ( row >= myRows )
    {
        throw std::out_of_range("ERROR: Tried to access ROW out of bounds.\n");
    }
    else
    {
        return myArray[ row ];
    }
}
