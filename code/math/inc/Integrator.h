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
#include "../inc/Vector.h"
#include "../inc/LongVector.h"

class Integrator
{
    // Functions
    public:
        // Constructor
        Integrator() {};
        // Destructor
        virtual ~Integrator() {};
        // Virtual Function: integrate (scalar)
        virtual double integrate(const LongVector &dx) = 0;
        // Virtual Function: integrate (LongVector)
        virtual LongVector integrateComposite(const LongVector &dx, const LongVector &t, const double = 0.0) = 0;
        // Virtual Function: integrate
        virtual Vector integrate(const Vector &vec) = 0;
    private:
    protected:
};

#endif // INTEGRATOR_H
