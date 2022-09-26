#ifndef VECTOR_H
#define VECTOR_H

#include "Array.h"

template <typename T>
class Vector : public Array<T>
{
    // Member Functions
    public:
        using Base = Array<T>;
        using Base::operator=;
        // Constructor
        Vector() : Base(3, 1) {}
    private:
    protected:
    // Member Data
    public:
    private:
    protected:
};

template <>
class Vector<double> : public Array<double>
{
    // Member Functions
    public:
        using Base = Array<double>;
        using Base::operator=;
        // Constructor
        Vector() : Base(3, 1) {}
        // Getter Function magnitude
        double magnitude(void);
        // Getter Function unit
        Vector<double> unit(void);
    private:
    protected:
    // Member Data
    public:
    private:
    protected:
};

// Get Magnitude
inline double Vector<double>::magnitude(void)
{
    return sqrt(myData.at(0)*myData.at(0) + myData.at(1)*myData.at(1) + myData.at(2)*myData.at(2));
}

// Get Unit Vector
inline Vector<double> Vector<double>::unit(void)
{
    Vector<double> tmp;
    double mag = magnitude();
    tmp[0] = myData.at(0)/mag;
    tmp[1] = myData.at(1)/mag;
    tmp[2] = myData.at(2)/mag;
    return tmp;
}

#endif