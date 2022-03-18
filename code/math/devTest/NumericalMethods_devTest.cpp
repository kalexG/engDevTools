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

double function_1(double x)
{
    double f_x = pow(x,3) + 4 * pow(x, 2) - 10;
    return f_x;
}

double function_2(double x)
{
    //double f_x = sqrt(2/(pow(x,2)-3));  
    double f_x = pow( 3 * (pow(x,2) + 1 ), 0.25);
    //double f_x = sqrt((pow(x,4)-3)/3);
    return f_x;
}

double function_3(double x)
{
    double f_x = pow(x,2) - 6;
    return f_x;
}

double function_3p(double x)
{
    double fp_x = 2 * x;
    return fp_x;
}

int main( int argc, char *argv[] ) {

    using namespace NumericalMethods;
    // Inputs
    printf("You made it to test function for NumericalMethods!\n\n");
    std::vector<NumericalMethods::rootSolver_ret> ans1, ans2, ans3;
    printf("NM Bisection Method Test\n\n");
    ans1 = NumericalMethods::bisection_method(&function_1, 1, 2, 1e-04);
    std::string res1 = NumericalMethods::rootSolver_results(ans1);
    printf("%s\n", res1.c_str());
    
    printf("NM Fixed-Point Iteration Method Test\n\n");
    ans2 = NumericalMethods::fixedPointIteration_method(&function_2, 1, 1e-02);
    std::string res2 = NumericalMethods::rootSolver_results(ans2);
    printf("%s\n", res2.c_str());
    
    printf("NM Newton's Method Test\n\n");
    ans3 = NumericalMethods::newtons_method(&function_3, &function_3p, 1);
    std::string res3 = NumericalMethods::rootSolver_results(ans3);
    printf("%s", res3.c_str());

    return 0;
}
