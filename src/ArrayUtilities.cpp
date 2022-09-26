#include "ArrayUtilities.h"
using namespace Utilities;

// Function: Check if Array is Square
bool Utilities::checkSquare(Array<double> arr)
{
    if (arr.rows() == arr.cols()) { return true; }
    else { return false; }
}

// Function: Check if Array is Identity
bool Utilities::checkIdentity(Array<double> arr)
{
    if (!checkSquare(arr)) { return false; }
    
    for (int i = 0; i < arr.size(); i += (arr.cols() + 1))
    {
        if ( arr[i] != 1.0 ) { return false; }
    }
    
    return true;
}

// Function: Check if Array is Singular
bool Utilities::checkSingular(Array<double> arr)
{
    if ( !checkSquare(arr) || arr.size() == 0 ) { return true; }
    
    if ( checkIdentity(arr) ) { return false; }
    
    int mn = arr.rows();
    std::vector<int> ipiv(mn);
    // Utilize LAPACKE LU Factorization
    int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, arr.data().data(), mn, ipiv.data() );
    
    if ( info != 0 ) { return true; }
    else { return false; }
}

// Function: Get Array Properties
std::vector<bool> Utilities::getArrayProperties(Array<double> arr)
{
    std::vector<bool> myProperties(MAX_PROPERTIES);
    // Reevaluate properties
    myProperties[SQUARE] = checkSquare(arr);
    myProperties[IDENTITY] = checkIdentity(arr);
    myProperties[SINGULAR] = checkSingular(arr);
    return myProperties;
}

// Function: Cross Product of Two Vectors
Vector<double> Utilities::crossProduct(Vector<double> vec1, Vector<double> vec2)
{
    Vector<double> tmp;
    tmp[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
    tmp[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
    tmp[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
    return tmp;
}

// Function Dot Product of Two Vectors
double Utilities::dotProduct(Vector<double> vec1, Vector<double> vec2)
{
    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];  
}