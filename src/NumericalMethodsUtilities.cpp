#include "NumericalMethodsUtilities.h"
using namespace Utilities;

// Function: Print root solver results
std::string Utilities::rootSolver_results(std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans)
{
    std::ostringstream tmpStream;
    for ( uint32_t i = 0; i < ans.size(); i++)
    {
        tmpStream << "n = "     << ans[ i ].n     << " | " <<
                    "p_n = "   << ans[ i ].p_n << " |\n";
    }
    std::string tmpString = tmpStream.str();
    return tmpString;
}