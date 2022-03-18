//---------------------------------------
// Filename: BisectionMethod_unitTest.cpp
// Created: 03/14/2022
// Last Modified: 03/14/2022
// Author: Kevin Gomez
//---------------------------------------

#include "../inc/MathUnitTest.h"

double function_21_1(double x)
{
    double f_x = sqrt(x)-cos(x);
    return f_x;
}

double function_21_2(double x)
{
    double f_x = pow(x,3) - 7 * pow(x, 2) + 14 * x -6;
    return f_x;
}

double function_21_3(double x)
{
    double f_x = x - pow(2,-x);
    return f_x;
}

double function_21_4(double x)
{
    double f_x = exp(x) - pow(x,2) + 3 * x - 2;
    return f_x;
}

double function_21_5(double x)
{
    double f_x = 2 * x * cos(2 * x) - pow(x + 1,2);
    return f_x;
}

double function_21_6(double x)
{
    double f_x = x * cos(x) - 2 * pow(x,2) + 3 * x - 1;
    return f_x;
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_1)
{
    std::vector<NumericalMethods::rootSolver_ret> ans = NumericalMethods::bisection_method(&function_21_1, 0, 1);
    EXPECT_NEAR(ans[2].p_n, 0.625, 1e-03);
    EXPECT_EQ(ans[2].n, 2);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_3)
{
    // a
    std::vector<NumericalMethods::rootSolver_ret> ans = NumericalMethods::bisection_method(&function_21_2, 0, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 0.5859, 1e-04);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
    // b
    ans = NumericalMethods::bisection_method(&function_21_2, 1, 3.2, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.002, 1e-03);
    EXPECT_EQ(ans.back().n, 7);
    ans.clear();
    // c
    ans = NumericalMethods::bisection_method(&function_21_2, 3.2, 4, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.419, 1e-03);
    EXPECT_EQ(ans.back().n, 6);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_5)
{
    // a
    std::vector<NumericalMethods::rootSolver_ret> ans = NumericalMethods::bisection_method(&function_21_3, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.641182, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // b
    ans = NumericalMethods::bisection_method(&function_21_4, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257530, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // c1
    ans = NumericalMethods::bisection_method(&function_21_5, -3, -2, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -2.191307, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // c2
    ans = NumericalMethods::bisection_method(&function_21_5, -1, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -0.798164, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // d1
    ans = NumericalMethods::bisection_method(&function_21_6, 0.2, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.297528, 1e-06);
    EXPECT_EQ(ans.back().n, 13);
    ans.clear();
    // d2
    ans = NumericalMethods::bisection_method(&function_21_6, 1.2, 1.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 1.256622, 1e-06);
    EXPECT_EQ(ans.back().n, 13);
}

double function_22_1(double x)
{
    double f_x = pow( 3 * (pow(x,2) + 1 ), 0.25);
    return f_x;
}

double function_22_2(double x)
{
    double f_x = (2 - exp(x) + pow(x,2)) / 3;
    return f_x;
}

double function_22_3(double x)
{
    double f_x = 5 / pow(x,2) + 2;
    return f_x;
}

double function_22_4(double x)
{
    double f_x = sqrt(exp(x) / 3);
    return f_x;
}

double function_22_5(double x)
{
    double f_x = pow(5, -x);
    return f_x;
}

double function_22_6(double x)
{
    double f_x = pow(6, -x);
    return f_x;
}

double function_22_7(double x)
{
    double f_x = 0.5 * (sin(x) + cos(x));
    return f_x;
}

TEST_F(NumericalMethodsUnitTest, FixedIterationMethod_2_2_5)
{
    std::vector<NumericalMethods::rootSolver_ret> ans = NumericalMethods::fixedPointIteration_method(&function_22_1, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 1.94332, 1e-05);
    EXPECT_EQ(ans.back().n, 5);
}

TEST_F(NumericalMethodsUnitTest, FixedIterationMethod_2_2_11)
{
    // a
    std::vector<NumericalMethods::rootSolver_ret> ans = NumericalMethods::fixedPointIteration_method(&function_22_2, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257531, 1e-06);
    EXPECT_EQ(ans.back().n, 8);
    ans.clear();
    // b
    ans = NumericalMethods::fixedPointIteration_method(&function_22_3, 2.5, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 2.690650, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // c
    ans = NumericalMethods::fixedPointIteration_method(&function_22_4, 0.25, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.909999, 1e-06);
    EXPECT_EQ(ans.back().n, 13);
    ans.clear();
    // d
    ans = NumericalMethods::fixedPointIteration_method(&function_22_5, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.469625, 1e-06);
    EXPECT_EQ(ans.back().n, 38);
    ans.clear();
    // e
    ans = NumericalMethods::fixedPointIteration_method(&function_22_6, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.448059, 1e-06);
    EXPECT_EQ(ans.back().n, 47);
    ans.clear();
    // f
    ans = NumericalMethods::fixedPointIteration_method(&function_22_7, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.704812, 1e-06);
    EXPECT_EQ(ans.back().n, 5);
    ans.clear();
}