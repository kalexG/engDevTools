//---------------------------------------
// Filename: NumericalMethods_devTest.cpp
// Created: 03/12/2018
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//---------------------------------------

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/NumericalMethods.h"

using namespace NumericalMethods;

double function_1(double x)
{
    double f_x = sqrt(x)-cos(x);
    return f_x;
}

double function_2(double x)
{
    double f_x = pow(x,3) - 7 * pow(x, 2) + 14 * x -6;
    return f_x;
}
int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for NumericalMethods!\n\n");

    printf("NM Bisection Method Test\n\n");
    double ans = NumericalMethods::bisection_method(&function_1, 0, 1, 1e-05, 3);
    printf("2.1-1 = %f\n",ans);
    ans = NumericalMethods::bisection_method(&function_2, 0, 1, 1e-02, 100);
    printf("2.1-3.a = %f\n",ans);
    ans = NumericalMethods::bisection_method(&function_2, 1, 3.2, 1e-02, 100);
    printf("2.1-3.b = %f\n",ans);
    ans = NumericalMethods::bisection_method(&function_2, 3.2, 4, 1e-02, 100);
    printf("2.1-3.c = %f\n",ans);

    return 0;
}
