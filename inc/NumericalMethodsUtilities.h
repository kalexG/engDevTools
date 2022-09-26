#ifndef NUMERICALMETHODSUTILITIES_H
#define NUMERICALMETHODSUTILITIES_H

#include "NumericalMethods.h"

namespace Utilities
{
    // Function: Print root solver results
    std::string rootSolver_results(std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans);
}

#endif