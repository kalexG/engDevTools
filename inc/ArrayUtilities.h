#ifndef ARRAYUTILITIES_H
#define ARRAYUTILITIES_H

#include "Array.h"
#include "Matrix.h"
#include "Vector.h"

namespace Utilities
{
    // Function: Print Array Contents
    template <typename T>
    std::string printArray(Array<T> arr)
    {
        std::ostringstream tmpStream;
        tmpStream << "| ";
        int j = arr.cols() - 1;
        for (int i = 0; i < arr.size(); i++)
        {
            tmpStream << arr[i];
            if ( j == 0 )
            {
                tmpStream << " |\n| ";
                j = arr.cols() - 1;
            }
            else
            {
                tmpStream << " | ";
                j--;
            }
        }
        std::string tmpString = tmpStream.str();
        tmpString.erase(tmpString.length() - 3);
        return tmpString;
    };

    // Function: Print Array Info
    template <typename T>
    std::string printArrayInfo(Array<T> arr)
    {
        std::ostringstream tmpStream;
        tmpStream << "Dimensions - " << arr.rows() << "x" << arr.cols() << "\n";
        tmpStream << "Elements - " << arr.size();
        std::string tmpString = tmpStream.str();
        return tmpString;
    };
    
    
    // Function: compare
    template <typename T>
    bool compare(Array<T> arr1, Array<T> arr2)
    {
        if ( (arr1.rows() != arr2.rows()) || (arr1.cols() != arr2.cols()) )
        {
            return false;
        }
        for (int i = 0; i < arr1.size(); i++)
        {
            if (arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    };
        
    // Function: compare (doubles w/ tolerance)
    inline bool compare(Array<double> arr1, Array<double> arr2, double tol = 1e-03)
    {
        if ( (arr1.rows() != arr2.rows()) || (arr1.cols() != arr2.cols()) )
        {
            return false;
        }
        for (int i = 0; i < arr1.size(); i++)
        {
            if (std::abs(arr1[i] - arr2[i]) > tol)
            {
                return false;
            }
        }
        return true;
    };
        
    // Data: enum for property identification
    enum ArrayProperties
    {
        IDENTITY,
        SQUARE,
        SINGULAR,
        MAX_PROPERTIES
    };
        
    // Function: Check if Array is Square
    bool checkSquare(Array<double> arr);

    // Function: Check if Array is Identity
    bool checkIdentity(Array<double> arr);

    // Function: Check if Array is Singular
    bool checkSingular(Array<double> arr);

    // Function: Get Array Properties
    std::vector<bool> getArrayProperties(Array<double> arr);

    // Function: Cross Product of Two Vectors
    Vector<double> crossProduct(Vector<double> vec1, Vector<double> vec2);

    // Function Dot Product of Two Vectors
    double dotProduct(Vector<double> vec1, Vector<double> vec2);
}

#endif