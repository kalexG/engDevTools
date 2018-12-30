#include "../inc/Array.h"

// Constructor
Array::Array(unsigned int rows, unsigned int cols)
    : myRows(rows)
    , myCols(cols)
    , myElements(rows*cols)
    , isSquare(checkSquare(rows, cols))
{
    initArray();
}

// Copy Constructor
Array::Array(const Array& arr)
    : Array(arr.myRows, arr.myCols)
{}

// Move Contructor
Array::Array (Array&& arr) noexcept
: myArray(std::exchange(arr.myArray, nullptr))
{}

// Swaps Array class data members
void swap(Array& arr1, Array& arr2)
{
    std::swap(arr1.myRows, arr2.myRows);
    std::swap(arr1.myCols, arr2.myCols);
    std::swap(arr1.myElements, arr2.myElements);
    std::swap(arr1.myArray, arr2.myArray);
    std::swap(arr1.myArraySize, arr2.myArraySize);
}

// Copy Assignment
Array& Array::operator= (const Array& arr)
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {    
        return *this = Array(arr);
    }
    else
    {
        throw std::length_error("ERROR: Array operation size mismatch.\n");   
    }
}

// Move Assignment
Array& Array::operator= (Array&& arr) noexcept
{
    swap(*this, arr);
    return *this;
}

// Destructor
Array::~Array(void)
{
    freeArray();
}

// Overload "*" Operator (lhs: Array*Scalar)
Array Array::operator* (const double scalar) const
{
    Array tmp(myRows, myCols);
    for (unsigned int i = 0; i < myElements; i++)
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

// Overload "+" Operator (Array Addition)
Array Array::operator+ (const Array& arr) const
{
    Array tmp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        for (unsigned int i = 0; i < myElements; i++)
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
    Array tmp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        for (unsigned int i = 0; i < myElements; i++)
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
    for (unsigned int i = 0; i < myElements; i++)
    {
        tmp.myArray[i] = -myArray[i];
    }
    return tmp;
}

// Overload "()" Operator (Accessing: (row, col))
double &Array::operator() (unsigned int row, unsigned int col)
{
    if ( row >= myRows )
    {
        throw std::out_of_range("ERROR: Tried to access ROW out of bounds.\n");
    }
    else if ( col >= myCols )
    {
        throw std::out_of_range("ERROR: Tried to access COL out of bounds.\n");
    }
    else
    {
        return myArray[myCols * row + col];
    }
}

// Overload "[]" Operator (Accessing: [element])
double &Array::operator[] (unsigned int index)
{
    if ( index >= myElements )
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myArray[index];
    }
}

// Initialize Array
void Array::initArray(void)
{
    myArray = new double [myElements]();
    myArraySize = sizeof(myArray);
}

// Free Array
void Array::freeArray(void)
{
    delete[] myArray;
    myArray = NULL;
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

    for (unsigned int i = 1; i < myElements; i++)
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
        for (unsigned int i = 0; i < myElements; i += (myCols + 1))
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

// Get myRows
unsigned int Array::getMyRows(void)
{
    return myRows;
}

// Get myCols
unsigned int Array::getMyCols(void)
{
    return myCols;
}

// Get myElements
unsigned int Array::getMyElements(void)
{
    return myElements;
}

// Get myArray
double* Array::getMyArray(void)
{
    return myArray;
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
        for (unsigned int i = 0; i < myElements; i += (myCols + 1))
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
    unsigned int j = 0;
    for (unsigned int i = 0; i < myRows; i++)
    {
        tmp[i].resize(myCols);
        std::copy(&myArray[j], &myArray[j+myCols], tmp[i].begin());
        j += myCols;
    }
    return tmp;
}

// Check if Array is Square
bool Array::checkSquare(unsigned int rows, unsigned int cols)
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

// Overload "()" Operator (Accessing: (row))
double &Vector::operator() (unsigned int row)
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

// Calculate Unit Vector
Vector unitVector(Vector& vec)
{
    Vector tmp;
    double mag = vec.getMagnitude();
    tmp[0] = vec[0]/mag;
    tmp[1] = vec[1]/mag;
    tmp[2] = vec[2]/mag;
    return tmp;
}

// Get Magnitude
double Vector::getMagnitude(void)
{
    return sqrt(myArray[0]*myArray[0] + myArray[1]*myArray[1] + myArray[2]*myArray[2]);
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
