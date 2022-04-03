#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"

template <typename T>
class Matrix : public Array<T>
{
    // Member Functions
    public:
        using Base = Array<T>;
        using Base::operator=;
        // Constructor
        Matrix() : Base(3, 3) {}
    private:
    protected:
    // Member Data
    public:
    private:
    protected:
};

#endif