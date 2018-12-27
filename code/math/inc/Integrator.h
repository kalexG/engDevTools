// Filename: Integrator.h
// Created: 12/27/2018
// Last Modified: 12/27/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <utility>

class Integrator
{
    // Functions
    public:
        // Constructor
        Integrator();
        // Copy Constructor (Blocked)
        Integrator(const Integrator& integ) = delete;
        // Move Constructor (Blocked)
        Integrator(Integrator&& integ) noexcept = delete;
        // Copy Assignment (Blocked)
        Integrator& operator=(const Integrator& integ) = delete;
        // Move Assignment (Blocked)
        Integrator& operator=(Integrator&& integ) noexcept = delete;
        // Destructor
        virtual ~Integrator(void);
    private:
    protected:

    // Data
    public:
    private:
    protected:
};

