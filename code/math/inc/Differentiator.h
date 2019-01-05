//---------------------------
// Filename: Differentiator.h
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//---------------------------

#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include <iostream>
#include <math.h>
#include <utility>

class Differentiator
{
    // Functions
    public:
        // Constructor
        Differentiator();
        // Copy Constructor (Blocked)
        Differentiator(const Differentiator& diffe) = delete;
        // Move Constructor (Blocked)
        Differentiator(Differentiator&& diffe) noexcept = delete;
        // Copy Assignment (Blocked)
        Differentiator& operator=(const Differentiator& diffe) = delete;
        // Move Assignment (Blocked)
        Differentiator& operator=(Differentiator&& diffe) noexcept = delete;
        // Destructor
        virtual ~Differentiator(void);
    private:
        bool DifferentiatorSet;
    protected:

    // Data
    public:
    private:
    protected:
};

#endif // DIFFERENTIATOR_H
