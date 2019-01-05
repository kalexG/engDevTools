//--------------------------
// Filename: Integrator.h
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//--------------------------

#ifndef INTEGRATOR_H
#define INTEGRATOR_H

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
        bool IntegratorSet;
    protected:

    // Data
    public:
    private:
    protected:
};

#endif // INTEGRATOR_H
