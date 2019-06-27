//------------------------------
// Filename: IntegratorTrapz.cpp
// Created: 01/10/2018
// Last Modified: 01/10/2018
// Author: Kevin Gomez
//------------------------------

#include "../inc/IntegratorTrapz.h"

IntegratorTrapz::IntegratorTrapz(void)
{}

IntegratorTrapz::~IntegratorTrapz(void)
{}

double IntegratorTrapz::integrate(const LongVector &dx)
{
    double tmp = 0;
    return tmp;
}

LongVector IntegratorTrapz::integrateComposite(const LongVector &dx, const LongVector &t, const double init)
{
    LongVector tmp(5);
    return tmp;
}

Vector IntegratorTrapz::integrate(const Vector &vec)
{
    Vector tmp;
    return tmp;
}
