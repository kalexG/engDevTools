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

#pragma once
namespace NumericalMethods
{
    // Return struct for root solvers
    struct rootSolver_ret
    {
        uint32_t n;
        double   p_n;
    };

    // Bisection Method
    inline std::vector<rootSolver_ret> bisection_method(std::function<double(double)> f_x, 
                                                 double a, 
                                                 double b, 
                                                 double tol = 1e-05, 
                                                 uint32_t max_it = std::numeric_limits<uint32_t>::max() )
    {
        std::vector<rootSolver_ret> ret;
        rootSolver_ret entry;    
        double f_a = f_x(a);
        double f_p_n;
        uint32_t n = 0;
        while ( n <= max_it )
        {
            // Store metadata
            entry.n = n;
            entry.p_n = a + ( b - a ) / 2;
            f_p_n = f_x(entry.p_n);
            ret.push_back(entry);

            if ( f_p_n == 0 || ( b - a ) / 2 < tol )
            {
                return ret;
            }

            if ( f_a * f_p_n > 0 )
            {
                a = entry.p_n;
                f_a = f_p_n;
            }
            else
            {
                b = entry.p_n;
            }
            
            n++;
        }
        return ret;   
    };

    // Fixed-Point Iteration Method
    inline std::vector<rootSolver_ret> fixedPointIteration_method(std::function<double(double)> f_x, 
                                                           double p_0, 
                                                           double tol = 1e-05, 
                                                           uint32_t max_it = std::numeric_limits<uint32_t>::max() )
    {
        std::vector<rootSolver_ret> ret;
        rootSolver_ret entry;    
        uint32_t n = 0;
        while ( n <= max_it )
        {
            // Store metadata
            entry.n = n;
            entry.p_n = f_x(p_0);
            ret.push_back(entry);

            if ( fabs( entry.p_n - p_0 ) < tol )
            {
                return ret;
            }

            n++;
            p_0 = entry.p_n;
        }
        return ret;
    };

    // Netwon's Method
    inline std::vector<rootSolver_ret> newtons_method(std::function<double(double)> f_x, 
                                               std::function<double(double)> fp_x,
                                               double p_0, 
                                               double tol = 1e-05, 
                                               uint32_t max_it = std::numeric_limits<uint32_t>::max() )
    {
        std::vector<rootSolver_ret> ret;
        rootSolver_ret entry;    
        uint32_t n = 1;
        // First entry 
        entry.n = 0;
        entry.p_n = p_0;
        ret.push_back(entry);
        while ( n <= max_it )
        {
            // Store metadata
            entry.n = n;
            entry.p_n = p_0 - f_x(p_0) / fp_x(p_0);
            ret.push_back(entry);

            if ( fabs( entry.p_n - p_0) < tol )
            {
                return ret;
            }
            p_0 = entry.p_n;
            n++;
        }
        return ret;   
    };
    
    // Secant Method
    inline std::vector<rootSolver_ret> secant_method(std::function<double(double)> f_x, 
                                                     double p_0, 
                                                     double p_1, 
                                                     double tol = 1e-05, 
                                                     uint32_t max_it = std::numeric_limits<uint32_t>::max() )
    {
        std::vector<rootSolver_ret> ret;
        rootSolver_ret entry;   
        uint32_t n = 2;
        double q_0 = f_x(p_0);
        double q_1 = f_x(p_1);
        // First entry 
        entry.n = 0;
        entry.p_n = p_0;
        ret.push_back(entry);
        // Second entry 
        entry.n = 1;
        entry.p_n = p_1;
        ret.push_back(entry);
        while ( n <= max_it )
        {
            // Store metadata
            entry.n = n;
            entry.p_n = p_1 - q_1 * (p_1 - p_0) / (q_1 - q_0);
            ret.push_back(entry);

            if ( fabs( entry.p_n - p_1 ) < tol )
            {
                return ret;
            }

            p_0 = p_1;
            q_0 = q_1;
            p_1 = entry.p_n;
            q_1 = f_x(entry.p_n);
            n++;
        }
        return ret;   
    };

    // Method of False Position
    inline std::vector<rootSolver_ret> falsePosition_method(std::function<double(double)> f_x, 
                                                            double p_0, 
                                                            double p_1, 
                                                            double tol = 1e-05, 
                                                            uint32_t max_it = std::numeric_limits<uint32_t>::max() )
    {
        std::vector<rootSolver_ret> ret;
        rootSolver_ret entry;   
        uint32_t n = 2;
        double q_0 = f_x(p_0);
        double q_1 = f_x(p_1);
        // First entry 
        entry.n = 0;
        entry.p_n = p_0;
        ret.push_back(entry);
        // Second entry 
        entry.n = 1;
        entry.p_n = p_1;
        ret.push_back(entry);
        while ( n <= max_it )
        {
            // Store metadata
            entry.n = n;
            entry.p_n = p_1 - q_1 * (p_1 - p_0) / (q_1 - q_0);
            ret.push_back(entry);

            if ( fabs( entry.p_n - p_1 ) < tol )
            {
                return ret;
            }

            if (f_x(entry.p_n) * q_1 < 0)
            {
                p_0 = p_1;
                q_0 = q_1;
            }

            p_1 = entry.p_n;
            q_1 = f_x(entry.p_n);
            n++;
        }
        return ret;   
    };
    inline std::string rootSolver_results(std::vector<rootSolver_ret> ans)
    {
        std::ostringstream tmpStream;
        for ( uint32_t i = 0; i < ans.size(); i++)
        {
            tmpStream << "n = "     << ans[ i ].n     << " | " <<
                         "p_n = "   << ans[ i ].p_n << " |\n";
        }
        std::string tmpString = tmpStream.str();
        return tmpString;
    };

}

#endif