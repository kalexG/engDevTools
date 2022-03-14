//----------------------------------------
// Filename: NumericalMethods_unitTest.cpp
// Created: 03/14/2022
// Last Modified: 03/14/2022
// Author: Kevin Gomez
//----------------------------------------

#include "../inc/MathUnitTest.h"

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

double function_3(double x)
{
    double f_x = x - pow(2,-x);
    return f_x;
}

double function_4(double x)
{
    double f_x = exp(x) - pow(x,2) + 3 * x - 2;
    return f_x;
}

double function_5(double x)
{
    double f_x = 2 * x * cos(2 * x) - pow(x + 1,2);
    return f_x;
}

double function_6(double x)
{
    double f_x = x * cos(x) - 2 * pow(x,2) + 3 * x - 1;
    return f_x;
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_1)
{
    std::vector<bisection_ret> ans = NumericalMethods::bisection_method(&function_1, 0, 1);
    EXPECT_NEAR(ans[2].p_n, 0.625, 1e-03);
    EXPECT_EQ(ans[2].n, 2);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_3)
{
    // a
    std::vector<bisection_ret> ans = NumericalMethods::bisection_method(&function_2, 0, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 0.5859, 1e-04);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
    // b
    ans = NumericalMethods::bisection_method(&function_2, 1, 3.2, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.002, 1e-03);
    EXPECT_EQ(ans.back().n, 7);
    ans.clear();
    // c
    ans = NumericalMethods::bisection_method(&function_2, 3.2, 4, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.419, 1e-03);
    EXPECT_EQ(ans.back().n, 6);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_5)
{
    // a
    std::vector<bisection_ret> ans = NumericalMethods::bisection_method(&function_3, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.641182, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // b
    ans = NumericalMethods::bisection_method(&function_4, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257530, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // c1
    ans = NumericalMethods::bisection_method(&function_5, -3, -2, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -2.191307, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // c2
    ans = NumericalMethods::bisection_method(&function_5, -1, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -0.798164, 1e-06);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // d1
    ans = NumericalMethods::bisection_method(&function_6, 0.2, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.297528, 1e-06);
    EXPECT_EQ(ans.back().n, 13);
    ans.clear();
    // d2
    ans = NumericalMethods::bisection_method(&function_6, 1.2, 1.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 1.256622, 1e-06);
    EXPECT_EQ(ans.back().n, 13);
}