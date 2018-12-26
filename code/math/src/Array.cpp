
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

// Copy/Move Assignment
Array& Array::operator =(Array arr) noexcept
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        swap(*this, arr);
        return *this;
    }
    else
    {
        printf("ERROR: You can't set two arrays equal when the dimesnions are not the same.\n");
        return *this;// Fix when you decide how you want to exit cleanly
    }
}

// Destructor
Array::~Array( void )
{
    freeArray();
}

// Overload "*" Operator (lhs: Array*Scalar)
Array Array::operator* (const double scalar)const
{
    Array temp(myRows, myCols);
    for (unsigned int i = 0; i < myElements; i++)
    {
        temp.array[i] = array[i]*scalar;
    }
    return temp;
}

// Overload "*" Operator (rhs: Scalar*Array)
Array operator* (const double scalar, const Array &arr)
{
    return arr * scalar;
}

// Overload "+" Operator (Array Addition)
Array Array::operator+ (const Array &arr) const
{
    Array temp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        for (unsigned int i = 0; i < myElements; i++)
        {
            temp.array[i] = array[i] + arr.array[i];
        }
    }
    return temp;
}

// Overload "-" Operator (Array Subtraction)
Array Array::operator- (const Array &arr) const
{
    Array temp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        for (unsigned int i = 0; i < myElements; i++)
        {
            temp.array[i] = array[i] - arr.array[i];
        }
    }
    return temp;
}
// Overload "-" Operator (-1*Array)
Array Array::operator- (void) const
{
    Array temp(myRows, myCols);
    for (unsigned int i = 0; i < myElements; i++)
    {
        temp.array[i] = -array[i];
    }
    return temp;
}

// Overload "()" Operator (Accessing: (row, col))
double &Array::operator() (unsigned int row, unsigned int col)
{
    if ( row >= myRows )
    {
        printf("ERROR: Tried to access ROW out of bounds.\n");
        row = myRows -1; // Fix when you decide how you want to exit cleanly
    }
    if ( col >= myCols )
    {
        printf("ERROR: Tried to access COL out of bounds.\n");
        col = myCols - 1; // Fix when you decide how you want to exit cleanly
    }
    return array[ myCols*row +col ];
}

// Overload "[]" Operator (Accessing: [element])
double &Array::operator[] (unsigned int index)
{
    if ( index >= myElements )
    {
        printf("ERROR: Tried to access INDEX out of bounds.\n");
        index = myElements - 1; // Fix when you decide how you want to exit cleanly
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
double &Vector::operator ()(unsigned int row)
{
    if ( row >= myRows )
    {
        printf("ERROR: Tried to access ROW out of bounds.\n");
        row = myRows - 1; // Fix when you decide how you want to exit cleanly
    }
    return array[ row ];
}
