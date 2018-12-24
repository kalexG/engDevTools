
#include "../inc/Array.h"

// Standard Constructor
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

// Destructor
Array::~Array( void )
{
    freeArray();
}

// Array = Operator
Array &Array::operator =(Array& arr)
{
    if ( (arr.myRows == this->myRows) && (arr.myCols == this->myCols) )
    {
        swap(array, arr.array);
        return *this;
    }
    else
    {
        printf("ERROR: You can't set two arrays equal when the dimesnions are not the same.\n");
        return *this; // Fix when you decide how you want to exit cleanly
    }
}

// Array () Operator
double &Array::operator ()(unsigned int row, unsigned int col)
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

// Array [] Operator
double &Array::operator [](unsigned int index)
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
    array = new double[myElements];
    setZeros();
}

// Free Array
void Array::freeArray(void)
{
    delete[] array;
    array=NULL;
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
    array[0]=start;

    for (unsigned int i = 1; i < myElements; i++)
    {
        array[i] = array[i-1] + increment;
    }
}

// Get Rows
int Array::getRows(void)
{
    return myRows;
}

// Get Columns
int Array::getCols(void)
{
    return myCols;
}

// Get Elements
int Array::getElems(void)
{
    return myElements;
}

// Vector = Operator
double &Vector::operator ()(unsigned int row)
{
    if ( row >= myRows )
    {
        printf("ERROR: Tried to access ROW out of bounds.\n");
        row = myRows - 1; // Fix when you decide how you want to exit cleanly
    }
    return array[ row ];
}
