#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <vector>
#include <lapacke_utils.h>
#include <cblas.h>

template <typename T, class Derived>
class ArrayBase
{
    // Member Functions
    public:
        // Constructor (rows, cols)
        ArrayBase(int rows, int cols);
        // Destructor
        virtual ~ArrayBase(void);
        // Copy Constructor
        ArrayBase(const ArrayBase<T, Derived>& arr);
        // Move Constructor
        ArrayBase(ArrayBase<T, Derived>&& arr) noexcept;
        // Getter Function: dims
        std::vector<int> dims(void);
        // Getter Function: size
        int size(void);
        // Getter Function: rows
        int rows(void);
        // Getter Function: cols
        int cols(void);
        // Getter Function: data
        std::vector<T> data(void);
        // Setter Function: set
        void set(const double val, const double = 0.0);
        // Assignment Operator:
        ArrayBase& operator= (ArrayBase<T, Derived> arr) noexcept;
        // Arithmetic Operator: +
        Derived operator+ (const Derived& arr) const;
        // Arithmetic Operator: -
        Derived operator- (const Derived& arr) const;
        // Artithmetic Operator: -
        Derived operator- (void) const;
        // Access Operator: []
        T &operator[] (int index);
        // Access Operator: ()
        T &operator() (int row, int col);
        // Access Operator: ()
        T &operator() (int index);
        // Function: swap
        friend void swap(ArrayBase<T, Derived>& arr1, ArrayBase<T, Derived>& arr2)
        {
            std::swap(arr1.myRows, arr2.myRows);
            std::swap(arr1.myCols, arr2.myCols);
            std::swap(arr1.myElements, arr2.myElements);
            std::swap(arr1.myArray, arr2.myArray);
        }
    private:
        // Function: checkValidDims
        bool checkValidDims(int rows, int cols);
    protected:
    // Member Data
    public:
    private:
    protected:
        // Data: validDims
        bool validDims;
        // Data: myRows
        int myRows;
        // Data: myCols
        int myCols;
        // Data: myElements
        int myElements;
        // Data: myArray
        std::vector<T> myArray;
};

// Constructor
template <typename T, class Derived>
ArrayBase<T, Derived>::ArrayBase(int rows, int cols)
    : validDims(checkValidDims(rows, cols))
    , myRows(rows)
    , myCols(cols)
    , myElements(rows*cols)
    , myArray(myElements)
{}

// Destructor
template <typename T, class Derived>
ArrayBase<T, Derived>::~ArrayBase(void)
{}

// Check if Dimensions are Valid
template <typename T, class Derived>
bool ArrayBase<T, Derived>::checkValidDims(int rows, int cols)
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

// Copy Constructor
template <typename T, class Derived>
ArrayBase<T, Derived>::ArrayBase(const ArrayBase<T, Derived>& arr)
    : ArrayBase(arr.myRows, arr.myCols)
{
    myArray = arr.myArray;
}

// Move Contructor
template <typename T, class Derived>
ArrayBase<T, Derived>::ArrayBase(ArrayBase<T, Derived>&& arr) noexcept
    : ArrayBase(arr.myRows, arr.myCols)
{
    swap(*this, arr);
}

// Copy & Move assignment
template <typename T, class Derived>
ArrayBase<T, Derived>& ArrayBase<T, Derived>::operator= (ArrayBase<T, Derived> arr) noexcept
{
    swap(*this, arr);
    return *this;
}

template <typename T, class Derived>
// Get dimensions
std::vector<int> ArrayBase<T, Derived>::dims(void)
{
    std::vector<int> dims(2);
    dims.at(0) = myRows;
    dims.at(1) = myCols;
    return dims;
}

template <typename T, class Derived>
// Get dimensions
int ArrayBase<T, Derived>::size(void)
{
    return myElements;
}

template <typename T, class Derived>
// Get rows
int ArrayBase<T, Derived>::rows(void)
{
    return myRows;
}

template <typename T, class Derived>
// Get cols
int ArrayBase<T, Derived>::cols(void)
{
    return myCols;
}

template <typename T, class Derived>
// Get dimensions
std::vector<T> ArrayBase<T, Derived>::data(void)
{
    return myArray;
}

template <typename T, class Derived>
// Set 
void ArrayBase<T, Derived>::set(const double val, const double inc)
{
    std::fill(myArray.begin(), myArray.end(), val);
    if (inc != 0.0)
    {
        for (int i = 1; i < myElements; i++)
        {
            myArray.at(i) = myArray.at(i-1) + inc;
        }
    }
}

template <typename T, class Derived>
// Overload "+" Operator (Array Addition)
Derived ArrayBase<T, Derived>::operator+ (const Derived& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Derived tmp(myRows, myCols);
        for (int i = 0; i < myElements; i++)
        {
            tmp.myArray.at(i) = myArray.at(i) + arr.myArray.at(i);
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [+] size mismatch.\n");   
    }
}

template <typename T, class Derived>
// Overload "-" Operator (Array Subtraction)
Derived ArrayBase<T, Derived>::operator- (const Derived& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Derived tmp(myRows, myCols);
        for (int i = 0; i < myElements; i++)
        {
            tmp.myArray.at(i) = myArray.at(i) - arr.myArray.at(i);
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [-] size mismatch.\n");   
    }
}

template <typename T, class Derived>
// Overload "-" Operator (-1*Array)
Derived ArrayBase<T, Derived>::operator- (void) const
{
    Derived tmp(myRows, myCols);
    for (int i = 0; i < myElements; i++)
    {
        tmp.myArray.at(i) = -myArray.at(i);
    }
    return tmp;
}

template <typename T, class Derived>
// Overload "[]" Operator (Accessing: [element])
T &ArrayBase<T, Derived>::operator[] (int index)
{
    if ( index >= myElements || index < 0)
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myArray.at(index);
    }
}

template <typename T, class Derived>
// Overload "()" Operator (Accessing: (row, col))
T &ArrayBase<T, Derived>::operator() (int row, int col)
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
        return myArray.at(myCols * row + col);
    }
}

// Overload "()" Operator (Accessing: (index))
template <typename T, class Derived>
T &ArrayBase<T, Derived>::operator() (int index)
{
    if ( index >= myElements )
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myArray[ index ];
    }
}

#endif