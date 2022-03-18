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

    inline std::vector<rootSolver_ret> newtons_method(std::function<double(double)> f_x, 
                                               std::function<double(double)> fp_x,
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
            entry.p_n = p_0;
            ret.push_back(entry);

            p_0 = entry.p_n - f_x(p_0) / fp_x(p_0);
            if ( fabs( p_0 - entry.p_n ) < tol )
            {
                return ret;
            }

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