
#include "../inc/Array.h"

// Constructor
Array::Array(unsigned int rows, unsigned int cols)
    : myRows(rows)
    , myCols(cols)
    , myElements(rows*cols)
{
    initArray();
}

// Copy Constructor
Array::Array(const Array& arr)
    : Array(arr.myRows, arr.myCols)
{}

// Move Contructor
Array::Array (Array&& arr) noexcept
    : array(std::exchange(arr.array, nullptr))
{}

// Swaps Array class data members
void swap(Array& arr1, Array& arr2)
{
    std::swap(arr1.myRows, arr2.myRows);
    std::swap(arr1.myCols, arr2.myCols);
    std::swap(arr1.myElements, arr2.myElements);
    std::swap(arr1.array, arr2.array);
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
    printf("Destructor call!\n");
}

// Overload "*" Operator (lhs: Array*Scalar)
Array Array::operator* (const double scalar) const
{
    Array tmp(myRows, myCols);
    for (unsigned int i = 0; i < myElements; i++)
    {
        tmp.array[i] = array[i] * scalar;
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
            tmp.array[i] = array[i] + arr.array[i];
        }
    }
    else
    {
        throw std::length_error("ERROR: Array operation [+] size mismatch.\n");   
    }
    return tmp;
}

// Overload "-" Operator (Array Subtraction)
Array Array::operator- (const Array& arr) const
{
    Array tmp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        for (unsigned int i = 0; i < myElements; i++)
        {
            tmp.array[i] = array[i] - arr.array[i];
        }
    }
    else
    {
        throw std::length_error("ERROR: Array operation [-] size mismatch.\n");   
    }
    return tmp;
}
// Overload "-" Operator (-1*Array)
Array Array::operator- (void) const
{
    Array tmp(myRows, myCols);
    for (unsigned int i = 0; i < myElements; i++)
    {
        tmp.array[i] = -array[i];
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
    if ( col >= myCols )
    {
        throw std::out_of_range("ERROR: Tried to access COL out of bounds.\n");
    }
    return array[myCols * row + col];
}

// Overload "[]" Operator (Accessing: [element])
double &Array::operator[] (unsigned int index)
{
    if ( index >= myElements )
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }

    return array[index];
}

// Initialize Array
void Array::initArray(void)
{
    array = new double [myElements]();
}

// Free Array
void Array::freeArray(void)
{
    delete[] array;
    array = NULL;
}

// Set Array [Zeros]
void Array::setZeros(void)
{
    for (unsigned int i = 0; i < myElements; i++)
    {
        array[i] = 0.0;
    }
}

// Set Array [Ones]
void Array::setOnes(void)
{
    for (unsigned int i = 0; i < myElements; i++)
    {
        array[i] = 1.0;
    }
}

// Set Array [Increment]
void Array::setIncrement(double start, double increment)
{
    array[0] = start;

    for (unsigned int i = 1; i < myElements; i++)
    {
        array[i] = array[i-1] + increment;
    }
}

// Get Rows
unsigned int Array::getRows(void)
{
    return myRows;
}

// Get Columns
unsigned int Array::getCols(void)
{
    return myCols;
}

// Get Elements
unsigned int Array::getElems(void)
{
    return myElements;
}

// Overload "()" Operator (Accessing: (row))
double &Vector::operator() (unsigned int row)
{
    if ( row >= myRows )
    {
        throw std::out_of_range("ERROR: Tried to access ROW out of bounds.\n");
    }
    return array[ row ];
}

Vector Vector::getUnitVector(void)
{
    Vector tmp;
    double mag = getMagnitude();
    tmp[0] = tmp[0]/mag;
    tmp[1] = tmp[1]/mag;
    tmp[2] = tmp[2]/mag;
    return tmp;
}

double Vector::getMagnitude(void)
{
    return sqrt(array[0]*array[0] + array[1]*array[1] + array[2]*array[2]);
}

Vector crossProduct(Vector& vec1, Vector& vec2)
{
    Vector tmp;
    tmp[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
    tmp[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
    tmp[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
    return tmp;
}

double dotProduct(Vector& vec1, Vector& vec2)
{
    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];  
}
