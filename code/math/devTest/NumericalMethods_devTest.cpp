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

double function_2(double x)
{
    //double g_x = sqrt(2/(pow(x,2)-3));  
    double g_x = pow( 3 * (pow(x,2) + 1 ), 0.25);
    //double g_x = sqrt((pow(x,4)-3)/3);
    return g_x;
}


int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for NumericalMethods!\n\n");

    printf("NM Bisection Method Test\n\n");
    std::vector<bisection_ret> ans1 = NumericalMethods::bisection_method(&function_1, 1, 2, 1e-04);
    std::string res1 = NumericalMethods::bisection_results(ans1);
    printf("%s\n", res1.c_str());
    
    printf("NM Fixed-Point Iteration Method Test\n\n");
    std::vector<fixedPointIteration_ret> ans2 = NumericalMethods::fixedPointIteration_method(&function_2, 1, 1e-02);
    std::string res2 = NumericalMethods::fixedPointIteration_results(ans2);
    printf("%s", res2.c_str());

    return 0;
}
