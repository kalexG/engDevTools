// Filename: Differentiator.h
// Created: 12/27/2018
// Last Modified: 12/27/2018
// Author: Kevin Gomez

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
    protected:

    // Data
    public:
    private:
    protected:
};

