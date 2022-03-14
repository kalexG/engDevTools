//---------------------------------------
// Filename: NumericalMethods_devTest.cpp
// Created: 03/12/2018
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//---------------------------------------

#include <iostream>
#include <math.h>
#include <string.h>
#include <limits>
#include "../inc/NumericalMethods.h"

using namespace NumericalMethods;

double function_1(double x)
{
    double f_x = pow(x,3) + 4 * pow(x, 2) - 10;
    return f_x;
}

int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for NumericalMethods!\n\n");

    printf("NM Bisection Method Test\n\n");
    std::vector<bisection_ret> ans = NumericalMethods::bisection_method(&function_1, 1, 2, 1e-04);
    std::string res = NumericalMethods::bisection_results(ans);
    printf("%s", res.c_str());

    return 0;
}
