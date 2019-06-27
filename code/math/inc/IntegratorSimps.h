//---------------------------
// Filename: IntegratorSimps
// Created: 01/10/2018
// Last Modified: 01/10/2018
// Author: Kevin Gomez
//---------------------------

#ifndef INTEGRATOR_SIMPS_H
#define INTEGRATOR_SIMPS_H

#include <iostream>
#include <math.h>
#include <utility>
#include "../inc/Integrator.h"

class IntegratorSimps : public Integrator
{
    // Functions
    public:
        // Constructor
        IntegratorSimps();
        // Copy Constructor (Not Allowed)
        IntegratorSimps(const IntegratorSimps& integ) = delete;
        // Move Constructor (Not Allowed)
        IntegratorSimps(IntegratorSimps&& integ) noexcept = delete;
        // Assignment Operator: (Not Allowed)
        IntegratorSimps& operator= (IntegratorSimps integ) noexcept = delete;
        // Destructor
        virtual ~IntegratorSimps(void);
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

#endif // INTEGRATOR_SIMPS_H


