//-------------------------------
// Filename: NumericalMethods.cpp
// Created: 03/12/2022
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//-------------------------------

#include "../inc/NumericalMethods.h"

using namespace NumericalMethods;

double NumericalMethods::bisection_method(std::function<double(double)> f_x, double ep_a, double ep_b, double tol, uint32_t max_it)
{
    uint32_t i = 1;
    double f_a, f_p, p, a, b;
    a = ep_a;
    b = ep_b;
    f_a = f_x(a);
    while (i <= max_it)
    {
        p = a + (b - a) / 2;
        f_p = f_x(p);
        if (f_p == 0 || (b - a) / 2 < tol)
        {
            return p;
        }
        i++;
        if (f_a * f_p > 0)
        {
            a = p;
            f_a = f_p;
        }
        else
        {
            b = p;
        }
    }
    return p;   
}