
#include "../inc/Array.h"

Array::Array(int rows, int cols)
    : validRows(validateDim(rows))
    , validCols(validateDim(cols))
{
    myRows = rows;
    myCols = cols;
    myElements = rows*cols;
    initArray();
}

Array::~Array( void )
{
    freeArray();
    printf("Self Destruct!!!!\n");
}

double &Array::operator ()(unsigned int row, unsigned int col)
{
    if ( row >= myRows )
    {
        printf("ERROR: Tried to access ROW out of bounds.\n");
        exit(0);
    }
    if ( col >= myCols )
    {
        printf("ERROR: Tried to access COL out of bounds.\n");
        exit(0);
    }
    return array[ myCols*row +col ];
}

double &Array::operator [](unsigned int index)
{
    if ( index >= myElements )
    {
        printf("ERROR: Tried to access INDEX out of bounds.\n");
        exit(0);
    }

    return array[index];
}

void Array::initArray(void)
{
    array = new double[myElements];
}

void Array::freeArray(void)
{
    delete[] array;
    array=NULL;
}

void Array::setZeros(void)
{
    for (unsigned int i = 0; i < myElements; i++)
    {
        array[i] = 0.0;
    }
}

void Array::setOnes(void)
{
    for (unsigned int i = 0; i < myElements; i++)
    {
        array[i] = 1.0;
    }
}

void Array::setIncrement(double start, double increment)
{
    array[0]=start;

    for (unsigned int i = 1; i < myElements; i++)
    {
        array[i] = array[i-1] + increment;
    }
}

int Array::getRows(void)
{
    return myRows;
}

int Array::getCols(void)
{
    return myCols;
}

double &Vector::operator ()(unsigned int row)
{
    if ( row >= myRows )
    {
        printf("ERROR: Tried to access ROW out of bounds.\n");
        exit(0);
    }
    return array[ row ];
}
