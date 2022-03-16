//-------------------------------------------
// Filename: FixedPointIteration_unitTest.cpp
// Created: 03/16/2022
// Last Modified: 03/16/2022
// Author: Kevin Gomez
//-------------------------------------------

#include "../inc/MathUnitTest.h"

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
    std::vector<fixedPointIteration_ret> ans = NumericalMethods::fixedPointIteration_method(&function_22_1, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 1.94332, 1e-05);
    EXPECT_EQ(ans.back().n, 5);
}

TEST_F(NumericalMethodsUnitTest, FixedIterationMethod_2_2_11)
{
    // a
    std::vector<fixedPointIteration_ret> ans = NumericalMethods::fixedPointIteration_method(&function_22_2, 0, 1e-05);
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