//------------------------------
// Filename: BisectionMethod.cpp
// Created: 03/12/2022
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//------------------------------

#include "../inc/NumericalMethods.h"

using namespace NumericalMethods;

std::vector<bisection_ret> NumericalMethods::bisection_method(std::function<double(double)> f_x, 
                                                              double a, 
                                                              double b, 
                                                              double tol, 
                                                              uint32_t max_it )
{
    std::vector<bisection_ret> ret;
    struct bisection_ret entry;    
    double f_a = f_x(a);
    uint32_t n = 0;
    while ( n <= max_it )
    {
        // Store metadata
        entry.n = n;
        entry.a_n = a;
        entry.b_n = b;
        entry.p_n = entry.a_n + ( entry.b_n - entry.a_n ) / 2;
        entry.f_p_n = f_x(entry.p_n);
        ret.push_back(entry);

        if ( entry.f_p_n == 0 || ( entry.b_n - entry.a_n ) / 2 < tol )
        {
            return ret;
        }

        if ( f_a * entry.f_p_n > 0 )
        {
            a = entry.p_n;
            f_a = entry.f_p_n;
        }
        else
        {
            b = entry.p_n;
        }
        
        n++;
    }
    return ret;   
}
    
std::string NumericalMethods::bisection_results(std::vector<bisection_ret> ans)
{
    std::ostringstream tmpStream;
    for ( uint32_t i = 0; i < ans.size(); i++)
    {
        tmpStream << "n = "     << ans[ i ].n     << " | " <<
                     "a_n = "   << ans[ i ].a_n   << " | " <<
                     "b_n = "   << ans[ i ].b_n   << " | " <<
                     "p_n = "   << ans[ i ].p_n   << " | " <<
                     "f_p_n = " << ans[ i ].f_p_n << " |\n";
    }
    std::string tmpString = tmpStream.str();
    return tmpString;
}