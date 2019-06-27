//---------------------------
// Filename: IntegratorTrapz
// Created: 01/10/2018
// Last Modified: 01/10/2018
// Author: Kevin Gomez
//---------------------------

#ifndef INTEGRATOR_TRAPZ_H
#define INTEGRATOR_TRAPZ_H

#include <iostream>
#include <math.h>
#include <utility>
#include "../inc/Integrator.h"

class IntegratorTrapz : public Integrator
{
    // Functions
    public:
        // Constructor
        IntegratorTrapz();
        // Copy Constructor (Not Allowed)
        IntegratorTrapz(const IntegratorTrapz& integ) = delete;
        // Move Constructor (Not Allowed)
        IntegratorTrapz(IntegratorTrapz&& integ) noexcept = delete;
        // Assignment Operator: (Not Allowed)
        IntegratorTrapz& operator= (IntegratorTrapz integ) noexcept = delete;
        // Destructor
        virtual ~IntegratorTrapz();
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

#endif // INTEGRATOR_TRAPZ_H

