//--------------------------
// Filename: Array.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#include "../inc/Array.h"

// Constructor
Array::Array(int rows, int cols)
    : validDims(checkValidDims(rows, cols))
    , myRows(rows)
    , myCols(cols)
    , myElements(rows*cols)
    , myArray(new double[myElements])
    , myArraySize(myElements * sizeof(myArray))
    , isSquare(checkSquare(rows, cols))
{}

// Copy Constructor
Array::Array(const Array& arr)
    : Array(arr.myRows, arr.myCols)
{
    std::copy(arr.myArray, arr.myArray + arr.myElements, myArray );
}

// Move Contructor
Array::Array (Array&& arr) noexcept
    : Array(arr.myRows, arr.myCols)
{
    swap(*this, arr);
}

// Swaps Array class data members
void swap(Array& arr1, Array& arr2)
{
    std::swap(arr1.myRows, arr2.myRows);
    std::swap(arr1.myCols, arr2.myCols);
    std::swap(arr1.myElements, arr2.myElements);
    std::swap(arr1.myArray, arr2.myArray);
    std::swap(arr1.myArraySize, arr2.myArraySize);
    std::swap(arr1.isSquare, arr2.isSquare);
}

// Compare Array class data members
bool compare(Array& arr1, Array& arr2, double tol)
{
    if ( (arr1.myRows != arr2.myRows) || (arr1.myCols != arr2.myCols) )
    {
        return false;
    }
    for (int i = 0; i < arr1.myElements; i++)
    {
        if (std::abs(arr1[i] - arr2[i]) > tol)
        {
            return false;
        }
    }
    return true;
}

// Copy & Move assignment
Array& Array::operator= (Array arr) noexcept
{
    swap(*this, arr);
    return *this;
}

// Destructor
Array::~Array(void)
{
    delete[] myArray;
    myArray = NULL;
}

// Overload "*" Operator (lhs: Array*Scalar)
Array Array::operator* (const double scalar) const
{
    Array tmp(myRows, myCols);
    for (int i = 0; i < myElements; i++)
    {
        tmp.myArray[i] = myArray[i] * scalar;
    }
    return tmp;
}

// Overload "*" Operator (rhs: Scalar*Array)
Array operator* (const double scalar, const Array& arr)
{
    return arr * scalar;
}

// Overload "*" Operator (Array*Array)
Array Array::operator* (const Array& arr) const
{
    int m = myRows;
    int n = arr.myCols;
    int k = myCols;
    if ( k == arr.myRows )
    {
        Array tmp(m, n);
        // Utilize cblas matrix-matrix multiply
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                    m, n, k, 1.0, myArray, k, arr.myArray, n, 0.0, tmp.myArray, n); 
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [*] size mismatch.\n");
    }
}

// Overload "+" Operator (Array Addition)
Array Array::operator+ (const Array& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Array tmp(myRows, myCols);
        for (int i = 0; i < myElements; i++)
        {
            tmp.myArray[i] = myArray[i] + arr.myArray[i];
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [+] size mismatch.\n");   
    }
}

// Overload "-" Operator (Array Subtraction)
Array Array::operator- (const Array& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Array tmp(myRows, myCols);
        for (int i = 0; i < myElements; i++)
        {
            tmp.myArray[i] = myArray[i] - arr.myArray[i];
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [-] size mismatch.\n");   
    }
}
// Overload "-" Operator (-1*Array)
Array Array::operator- (void) const
{
    Array tmp(myRows, myCols);
    for (int i = 0; i < myElements; i++)
    {
        tmp.myArray[i] = -myArray[i];
    }
    return tmp;
}

// Overload "()" Operator (Accessing: (row, col))
double &Array::operator() (int row, int col)
{
    if ( row >= myRows || row < 0 )
    {
        throw std::out_of_range("ERROR: Tried to access ROW out of bounds.\n");
    }
    else if ( col >= myCols || col < 0 )
    {
        throw std::out_of_range("ERROR: Tried to access COL out of bounds.\n");
    }
    else
    {
        return myArray[myCols * row + col];
    }
}

// Overload "[]" Operator (Accessing: [element])
double &Array::operator[] (int index)
{
    if ( index >= myElements || index < 0)
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myArray[index];
    }
}

// Set Array [Zeros]
void Array::setZeros(void)
{
    std::fill(&myArray[0], &myArray[myElements], 0.0);
}

// Set Array [Ones]
void Array::setOnes(void)
{
    std::fill(&myArray[0], &myArray[myElements], 1.0);
}

// Set Array [Double]
void Array::setTo(const double val)
{
    std::fill(&myArray[0], &myArray[myElements], val);
}

// Set Array [Increment]
void Array::setIncrement(const double start, const double increment)
{
    myArray[0] = start;

    for (int i = 1; i < myElements; i++)
    {
        myArray[i] = myArray[i-1] + increment;
    }
}

// Set Identity
void Array::setIdentity(void)
{
    if (isSquare)
    {
        setZeros();
        for (int i = 0; i < myElements; i += (myCols + 1))
        {
            myArray[i] = 1.0;
        }
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have an identity\n");
    }
}

// Set Transpose
void Array::setTranspose(void)
{
    Array tmp(myCols, myRows);
    // Utilize LAPACKE out-of-place transpose
    LAPACKE_dge_trans( LAPACK_ROW_MAJOR, myRows, myCols, myArray, myCols, tmp.myArray, myRows );
    swap(*this, tmp);
}

// Get Transpose
Array Array::getTranspose(void)
{
    Array tmp(myCols, myRows);
    // Utilize LAPACKE out-of-place transpose
    LAPACKE_dge_trans( LAPACK_ROW_MAJOR, myRows, myCols, myArray, myCols, tmp.myArray, myRows );
    return tmp;
}

// Get Determinant
double Array::getDeterminant(void)
{
    if (isSquare)
    {
        Array tmp(*this);
        int mn = tmp.myRows;
        int* ipiv = new int [mn];
        // Utilize LAPACKE LU Factorization
        int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, tmp.myArray, mn, ipiv );
        // INFO < 0: if INFO = -i, the i-th argument had an illegal value
        // INFO > 0: if INFO = i, U(i,i) is exactly zero. The factorization 
        //           has been completed, but the factor U is exactly
        //           singular, and division by zero will occur if it is used
        //           to solve a system of equations.
        if ( info < 0 )
        {
            throw std::invalid_argument("ERROR: INFO < 0 in getDeterminant: if INFO = -i, the i-th argument had an illegal value: " +
                                         std::to_string(info) + "\n");
        }
        else
        {
            // Calculate Determinant
            double det = 1;
            for( int i = 0; i < mn; i++ )
            {
                if ( i != ipiv[ i ] - 1 )
                {
                    det *= -tmp(i,i);
                }
                else
                {
                    det *= tmp(i,i);
                }
            }
            return det;
        }
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have a determinant\n");
    } 
}

// Get myRows
int Array::getMyRows(void)
{
    return myRows;
}

// Get myCols
int Array::getMyCols(void)
{
    return myCols;
}

// Get myElements
int Array::getMyElements(void)
{
    return myElements;
}

// Get myArray
double* Array::getMyArray(void)
{
    double* tmp;
    tmp = new double [myElements];
    std::copy(myArray, myArray + myElements, tmp);
    return tmp;
}

// Get myArraySize
std::size_t Array::getMyArraySize(void)
{
    return myArraySize;
}

// Get isSquare
bool Array::getIsSquare(void)
{
    return isSquare;
}

// Get Trace
double Array::getTrace(void)
{
    if (isSquare)
    {
        double tmp = 0.0;
        for (int i = 0; i < myElements; i += (myCols + 1))
        {
            tmp += myArray[i];
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have a trace\n");
    }
}

// Get myArray as std::vector in row first format
std::vector<double> Array::getStdVector1D(void)
{
    std::vector<double> tmp (myElements);
    tmp.assign(myArray, myArray + myElements);
    return tmp;
}

// Get myArray as 2-Dimensional std::vector
std::vector<std::vector<double>> Array::getStdVector2D(void)
{
    std::vector<std::vector<double>> tmp(myRows);
    int j = 0;
    for (int i = 0; i < myRows; i++)
    {
        tmp[i].resize(myCols);
        std::copy(&myArray[j], &myArray[j+myCols], tmp[i].begin());
        j += myCols;
    }
    return tmp;
}

// Check if Array is Square
bool Array::checkSquare(int rows, int cols)
{
    if (rows == cols)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

// Check if Dimensions are Valid
bool Array::checkValidDims(int rows, int cols)
{
    if ((rows <= 0) || (cols <= 0))
    {
        throw std::invalid_argument("ERROR: Array Dimesions must be > 0.\n");
    }
    else 
    {
        return false;
    }
}

// Print array contents
std::string Array::printArray(void)
{
    std::ostringstream tmpStream;
    tmpStream << "| ";
    int j = myCols - 1;
    for (int i = 0; i < myElements; i++)
    {
        tmpStream << myArray[i];
        if ( j == 0 )
        {
            tmpStream << " |\n| ";
            j = myCols - 1;
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
}

// Print array information
std::string Array::printArrayInfo()
{
    std::ostringstream tmpStream;
    tmpStream << "Dimensions - " << myRows << "x" << myCols << "\n";
    tmpStream << "Elements - " << myElements << "\n";
    tmpStream << "Size - " << myArraySize << " Bytes\n";
    tmpStream << "Square Array - " << std::boolalpha << isSquare;
    std::string tmpString = tmpStream.str();
    return tmpString;
}