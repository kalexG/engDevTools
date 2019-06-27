//-----------------------------
// Filename: IntegratorMidpoint
// Created: 01/10/2018
// Last Modified: 01/10/2018
// Author: Kevin Gomez
//-----------------------------

#ifndef INTEGRATOR_MIDPOINT_H
#define INTEGRATOR_MIDPOINT_H

#include <iostream>
#include <math.h>
#include <utility>
#include "../inc/Integrator.h"

class IntegratorMidpoint : public Integrator
{
    // Functions
    public:
        // Constructor
        IntegratorMidpoint();
        // Copy Constructor (Not Allowed)
        IntegratorMidpoint(const IntegratorMidpoint& integ) = delete;
        // Move Constructor (Not Allowed)
        IntegratorMidpoint(IntegratorMidpoint&& integ) noexcept = delete;
        // Assignment Operator: (Not Allowed)
        IntegratorMidpoint& operator= (IntegratorMidpoint integ) noexcept = delete;
        // Destructor
        virtual ~IntegratorMidpoint(void);
        // Function: integrate [UT: N]
        double integrate(const LongVector &dx);
        // Function: integrate [UT: N]
        LongVector integrateComposite(const LongVector &dx, const LongVector &t, const double = 0.0);
        // Function: integrate [UT: N]
        Vector integrate(const Vector &vec);
    private:
    protected:

    // Data
    public:
    private:
    protected:
};

#endif // INTEGRATOR_MIDPOINT_H


