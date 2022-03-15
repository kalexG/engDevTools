//-----------------------------
// Filename: NumericalMethods.h
// Created: 03/12/2022
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//-----------------------------

#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

#include <functional>
#include <vector>
#include <limits>
#include <string.h>
#include <sstream>
#include <cmath>

namespace NumericalMethods
{
    // Bisection Method Definitions
    struct bisection_ret
    {
        uint32_t n;
        double a_n;
        double b_n;
        double p_n;
        double f_p_n;
    };

    std::vector<bisection_ret> bisection_method(std::function<double(double)> f_x, 
                                                double ep_a, 
                                                double ep_b, 
                                                double tol = 1e-05, 
                                                uint32_t max_it = std::numeric_limits<uint32_t>::max() );

    std::string bisection_results(std::vector<bisection_ret> ans);

    // Fixed-Point Iteration Method Definitions
    struct fixedPointIteration_ret
    {
        uint32_t n;
        double p_n;
        double p_0;
    };

    std::vector<fixedPointIteration_ret> fixedPointIteration_method(std::function<double(double)> f_x, 
                                                                    double p_0, 
                                                                    double tol = 1e-05, 
                                                                    uint32_t max_it = std::numeric_limits<uint32_t>::max() );

    std::string fixedPointIteration_results(std::vector<fixedPointIteration_ret> ans);
}

#endif