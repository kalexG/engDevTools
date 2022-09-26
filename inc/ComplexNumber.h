#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <vector>

template <typename T>
class ComplexNumber
{
    // Member Functions
    public:
        // Constructor ()
        ComplexNumber();
        // Constructor (real, imag)
        ComplexNumber(T real, T imag);
        // Destructor
        virtual ~ComplexNumber(void);
        // Copy Constructor
        ComplexNumber(const ComplexNumber<T>& arr);
        // Move Constructor
        ComplexNumber(ComplexNumber<T>&& arr) noexcept;
        // Copy Assignment Operator:
        ComplexNumber& operator= (ComplexNumber<T>& arr);
        // Move Assignment Operator:
        ComplexNumber& operator= (ComplexNumber<T>&& arr) noexcept;
        // Getter Function: real
        T real(void);
        // Getter Function: imag
        T imag(void);
        // Getter Function: vals
        std::vector<T> vals(void);
        // Setter Function: set
        void set(const T real, const T imag);
        // Arithmetic Operator: +
        ComplexNumber<T> operator+ (const ComplexNumber<T>& arr) const;
        // Arithmetic Operator: -
        ComplexNumber<T> operator- (const ComplexNumber<T>& arr) const;
        // Artithmetic Operator: -
        ComplexNumber<T> operator- (void) const;
        // Access Operator: []
        T &operator[] (int index);
        // Access Operator: ()
        T &operator() (int index);
        // Function: swap
        friend void swap(ComplexNumber<T>& arr1, ComplexNumber<T>& arr2)
        {
            std::swap(arr1.myData, arr2.myData);
        }
    private:
    protected:
    // Member Data
    public:
        enum CN_Accessor
        {
            REAL = 0,
            IMAG = 1,
            MAX_LEN = 2
        }
    private:
    protected:
        // Data: myData
        std::vector<T> myData;
};

// Constructor ()
template <typename T>
ComplexNumber<T>::ComplexNumber()
    : myData(MAX_LEN)
{
    myData[REAL] = 0;
    myData[IMAG] = 0;
}

// Constructor (real, imag)
template <typename T>
ComplexNumber<T>::ComplexNumber(T real, T imag)
    : myData(MAX_LEN)
{
    myData[REAL] = real;
    myData[IMAG] = imag;
}

// Destructor
template <typename T>
ComplexNumber<T>::~ComplexNumber(void)
{}

// Copy Constructor
template <typename T>
ComplexNumber<T>::ComplexNumber(const ComplexNumber<T>& arr)
    : ComplexNumber(arr.myData[REAL], arr.myData[IMAG])
{}

// Move Contructor
template <typename T>
ComplexNumber<T>::ComplexNumber(ComplexNumber<T>&& arr) noexcept
    : myData(std::move(arr.myData))
{}

// Copy Assignment Operator
template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator= (ComplexNumber<T>& arr)
{
    return *this = ComplexNumber(arr.myData[REAL], arr.myData[IMAG]);
}

// Move Assignment Operator
template <typename T>
ComplexNumber<T>& ComplexNumber<T>::operator= (ComplexNumber<T>&& arr) noexcept
{
    swap(*this, arr);
    return *this;
}

// Get real component
template <typename T>
int ComplexNumber<T>::real(void)
{
    return myData[REAL];
}

// Get imaginary component 
template <typename T>
int ComplexNumber<T>::imag(void)
{
    return myData[IMAG];
}

// Get data
template <typename T>
std::vector<T> ComplexNumber<T>::data(void)
{
    return myData;
}

// Clear data
template <typename T>
void ComplexNumber<T>::clear(void)
{
    myData[REAL] = 0;
    myData[IMAG] = 0;
}

// Overload "+" Operator (Array Addition)
template <typename T, class Derived>
Derived ComplexNumber<T, Derived>::operator+ (const Derived& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Derived tmp(myRows, myCols);
        for (int i = 0; i < myData; i++)
        {
            tmp.myData.at(i) = myData.at(i) + arr.myData.at(i);
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [+] size mismatch.\n");   
    }
}

// Overload "-" Operator (Array Subtraction)
template <typename T, class Derived>
Derived ComplexNumber<T, Derived>::operator- (const Derived& arr) const
{
    if ( (arr.myRows == myRows) && (arr.myCols == myCols) )
    {
        Derived tmp(myRows, myCols);
        for (int i = 0; i < myData; i++)
        {
            tmp.myData.at(i) = myData.at(i) - arr.myData.at(i);
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [-] size mismatch.\n");   
    }
}

// Overload "-" Operator (-1*Array)
template <typename T, class Derived>
Derived ComplexNumber<T, Derived>::operator- (void) const
{
    Derived tmp(myRows, myCols);
    for (int i = 0; i < myData; i++)
    {
        tmp.myData.at(i) = -myData.at(i);
    }
    return tmp;
}

// Overload "[]" Operator (Accessing: [element])
template <typename T, class Derived>
T &ComplexNumber<T, Derived>::operator[] (int index)
{
    if ( index >= myData || index < 0)
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myData.at(index);
    }
}

// Overload "()" Operator (Accessing: (row, col))
template <typename T, class Derived>
T &ComplexNumber<T, Derived>::operator() (int row, int col)
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
        return myData.at(myCols * row + col);
    }
}

// Overload "()" Operator (Accessing: (index))
template <typename T, class Derived>
T &ComplexNumber<T, Derived>::operator() (int index)
{
    if ( index >= myData )
    {
        throw std::out_of_range("ERROR: Tried to access INDEX out of bounds.\n");
    }
    else
    {
        return myData[ index ];
    }
}

#endif