//--------------------------
// Filename: Vector.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#include "../inc/Vector.h"

// Overload "()" Operator (Accessing: (row))
double &Vector::operator() (int row)
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

// Get Magnitude
double Vector::getMagnitude(void)
{
    return sqrt(myArray[0]*myArray[0] + myArray[1]*myArray[1] + myArray[2]*myArray[2]);
}

// Get Unit Vector
Vector Vector::getUnitVector(void)
{
    Vector tmp;
    double mag = getMagnitude();
    tmp[0] = myArray[0]/mag;
    tmp[1] = myArray[1]/mag;
    tmp[2] = myArray[2]/mag;
    return tmp;
}

// Take Cross Product of Two Vectors
Vector crossProduct(Vector& vec1, Vector& vec2)
{
    Vector tmp;
    tmp[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
    tmp[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
    tmp[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
    return tmp;
}

// Take Dot Product of Two Vectors
double dotProduct(Vector& vec1, Vector& vec2)
{
    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];  
}
