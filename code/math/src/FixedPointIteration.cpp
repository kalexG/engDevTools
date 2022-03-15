//----------------------------------
// Filename: FixedPointIteration.cpp
// Created: 03/15/2022
// Last Modified: 03/15/2022
// Author: Kevin Gomez
//----------------------------------

#include "../inc/NumericalMethods.h"

using namespace NumericalMethods;

std::vector<fixedPointIteration_ret> NumericalMethods::fixedPointIteration_method(std::function<double(double)> f_x, 
                                                                                  double p_0, 
                                                                                  double tol, 
                                                                                  uint32_t max_it )
{
    std::vector<fixedPointIteration_ret> ret;
    struct fixedPointIteration_ret entry;    
    uint32_t n = 0;
    while ( n <= max_it )
    {
        // Store metadata
        entry.n = n;
        entry.p_0 = p_0;
        entry.p_n = f_x(entry.p_0);
        ret.push_back(entry);

        if ( fabs( entry.p_n - entry.p_0 ) < tol )
        {
            return ret;
        }

        n++;
        p_0 = entry.p_n;
    }
    return ret;   
}
    
std::string NumericalMethods::fixedPointIteration_results(std::vector<fixedPointIteration_ret> ans)
{
    std::ostringstream tmpStream;
    for ( uint32_t i = 0; i < ans.size(); i++)
    {
        tmpStream << "n = "     << ans[ i ].n     << " | " <<
                     "p_0 = "   << ans[ i ].p_0   << " | " <<
                     "p_n = "   << ans[ i ].p_n << " |\n";
    }
    std::string tmpString = tmpStream.str();
    return tmpString;
}