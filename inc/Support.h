#ifndef SUPPORT_H
#define SUPPORT_H

#include "Array.h"
#include "Vector.h"

namespace Support
{
    namespace ArraySupport
    {
        // Function: Print Array Contents
        template <typename T>
        inline std::string printArray(Array<T> arr)
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
        inline std::string printArrayInfo(Array<T> arr)
        {
            std::ostringstream tmpStream;
            tmpStream << "Dimensions - " << arr.rows() << "x" << arr.cols() << "\n";
            tmpStream << "Elements - " << arr.size();
            std::string tmpString = tmpStream.str();
            return tmpString;
        };
        
        // Function: compare
        template <typename T>
        inline bool compare(Array<T> arr1, Array<T> arr2)
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
        inline bool checkSquare(Array<double> arr)
        {
            if (arr.rows() == arr.cols()) { return true; }
            else { return false; }
        };

        // Function: Check if Array is Singular
        inline bool checkIdentity(Array<double> arr)
        {
            if (!checkSquare(arr)) { return false; }
            
            for (int i = 0; i < arr.size(); i += (arr.cols() + 1))
            {
                if ( arr[i] != 1.0 ) { return false; }
            }
            
            return true;
        };

        // Function: Check if Array is Identity
        inline bool checkSingular(Array<double> arr)
        {
            if ( !checkSquare(arr) || arr.size() == 0 ) { return true; }
            
            if ( checkIdentity(arr) ) { return false; }
            
            int mn = arr.rows();
            std::vector<int> ipiv(mn);
            // Utilize LAPACKE LU Factorization
            int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, arr.data().data(), mn, ipiv.data() );
            
            if ( info != 0 ) { return true; }
            else { return false; }
        };

        // Function: Get Array Properties
        inline std::vector<bool> getArrayProperties(Array<double> arr)
        {
            std::vector<bool> myProperties(MAX_PROPERTIES);
            // Reevaluate properties
            myProperties[SQUARE] = checkSquare(arr);
            myProperties[IDENTITY] = checkIdentity(arr);
            myProperties[SINGULAR] = checkSingular(arr);
            return myProperties;
        };

        // Function: Cross Product of Two Vectors
        inline Vector<double> crossProduct(Vector<double> vec1, Vector<double> vec2)
        {
            Vector<double> tmp;
            tmp[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
            tmp[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
            tmp[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
            return tmp;
        };

        // Function Dot Product of Two Vectors
        inline double dotProduct(Vector<double> vec1, Vector<double> vec2)
        {
            return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];  
        };

    }
}

#endif