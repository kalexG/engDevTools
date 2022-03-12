//-----------------------------
// Filename: NumericalMethods.h
// Created: 03/12/2022
// Last Modified: 03/12/2022
// Author: Kevin Gomez
//-----------------------------

#ifndef NUMERICALMETHODS_H
#define NUMERICALMETHODS_H

#include <functional>

#pragma once
namespace NumericalMethods {
    //struct bisection_ret;
    double bisection_method(std::function<double(double)> f_x, double ep_a, double ep_b, double tol, uint32_t max_it);
}

#endif