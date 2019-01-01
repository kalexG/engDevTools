#include "../inc/Array.h"

// Constructor
Array::Array(int rows, int cols)
    : validDims(checkValidDims(rows, cols))
    , myRows(rows)
    , myCols(cols)
    , myElements(rows*cols)
    , isSquare(checkSquare(rows, cols))
{
    myArray = new double [myElements]();
    myArraySize = sizeof(myArray);
    printf("ctor!\n");
}

// Copy Constructor
Array::Array(const Array& arr)
    : Array(arr.myRows, arr.myCols)
{
    std::copy(arr.myArray, arr.myArray + arr.myElements, myArray );
    printf("copy ctor!\n");
}

// Move Contructor
Array::Array (Array&& arr) noexcept
: myArray(std::exchange(arr.myArray, nullptr))
{
    printf("move ctor!\n");
}

// Swaps Array class data members
void swap(Array& arr1, Array& arr2)
{
    std::swap(arr1.myRows, arr2.myRows);
    std::swap(arr1.myCols, arr2.myCols);
    std::swap(arr1.myElements, arr2.myElements);
    std::swap(arr1.myArray, arr2.myArray);
    std::swap(arr1.myArraySize, arr2.myArraySize);
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
    delete[] myArray;
    myArray = NULL;
    printf("dtor!\n");
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
    Array tmp(m, n);
    if ( k == arr.myRows )
    {
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
    Array tmp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
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
    Array tmp(myRows, myCols);
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
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
double &Array::operator[] (int index)
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
