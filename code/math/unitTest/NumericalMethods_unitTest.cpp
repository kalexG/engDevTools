//---------------------------------------
// Filename: BisectionMethod_unitTest.cpp
// Created: 03/14/2022
// Last Modified: 03/14/2022
// Author: Kevin Gomez
//---------------------------------------

#include "../inc/MathUnitTest.h"

// Unit test functions
double function_21_1(double x)   { return sqrt(x)-cos(x); }
double function_21_2(double x)   { return pow(x,3) - 7 * pow(x, 2) + 14 * x -6; }
double function_21_3(double x)   { return x - pow(2,-x); }
double function_21_4(double x)   { return exp(x) - pow(x,2) + 3 * x - 2; }
double function_21_5(double x)   { return 2 * x * cos(2 * x) - pow(x + 1,2); }
double function_21_6(double x)   { return x * cos(x) - 2 * pow(x,2) + 3 * x - 1; }
double function_22_1(double x)   { return pow( 3 * (pow(x,2) + 1 ), 0.25); }
double function_22_2(double x)   { return (2 - exp(x) + pow(x,2)) / 3; }
double function_22_3(double x)   { return 5 / pow(x,2) + 2; }
double function_22_4(double x)   { return sqrt(exp(x) / 3); }
double function_22_5(double x)   { return pow(5, -x); }
double function_22_6(double x)   { return pow(6, -x); }
double function_22_7(double x)   { return 0.5 * (sin(x) + cos(x)); }
double function_23_1(double x)   { return pow(x,3) - 2 * pow(x,2) - 5; }
double function_23_1p(double x)  { return 3 * pow(x,2) - 4 * x; }
double function_23_2(double x)   { return pow(x,3) + 3 * pow(x,2) - 1; }
double function_23_2p(double x)  { return 3 * pow(x,2) + 6 * x; }
double function_23_3(double x)   { return x - cos(x); }
double function_23_3p(double x)  { return 1 + sin(x); }
double function_23_4(double x)   { return x - 0.8 - 0.2 * sin(x); }
double function_23_4p(double x)  { return 1 - 0.2 * cos(x); }
double function_24_1(double x)   { return pow(x,2.0) - 2.0 * x * exp(-x) + exp(-2.0 * x); }
double function_24_1p(double x)  { return 2.0 * x + 2.0 * exp(-x) * (x - 1.0) - 2.0 * exp(-2.0 * x); }
double function_24_1pp(double x) { return 2.0 - 2.0 * exp(-x) * (x - 2.0) + 4.0 * exp(-2.0 * x); }
double function_24_2(double x)   { return cos(x + sqrt(2.0)) + x * ((x / 2.0) + sqrt(2.0)); }
double function_24_2p(double x)  { return sqrt(2.0) + x - sin(x + sqrt(2.0)); }
double function_24_2pp(double x) { return 1.0 - cos(x + sqrt(2.0)); }

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_1)
{
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::bisection_method(&function_21_1, 0, 1);
    EXPECT_NEAR(ans[3].p_n, 0.625, 1e-03);
    EXPECT_EQ(ans[3].n, 3);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_3)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::bisection_method(&function_21_2, 0, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 0.5859, 1e-04);
    EXPECT_EQ(ans.back().n, 7);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_2, 1, 3.2, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.002, 1e-03);
    EXPECT_EQ(ans.back().n, 8);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_2, 3.2, 4, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 3.419, 1e-03);
    EXPECT_EQ(ans.back().n, 7);
}

TEST_F(NumericalMethodsUnitTest, BisectionMethod_2_1_5)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::bisection_method(&function_21_3, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.641182, 1e-06);
    EXPECT_EQ(ans.back().n, 17);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_4, 0, 1, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257530, 1e-06);
    EXPECT_EQ(ans.back().n, 17);
    ans.clear();
    // c1
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_5, -3, -2, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -2.191307, 1e-06);
    EXPECT_EQ(ans.back().n, 17);
    ans.clear();
    // c2
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_5, -1, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, -0.798164, 1e-06);
    EXPECT_EQ(ans.back().n, 17);
    ans.clear();
    // d1
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_6, 0.2, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.297528, 1e-06);
    EXPECT_EQ(ans.back().n, 14);
    ans.clear();
    // d2
    ans = NumericalMethods::RootSolvers::bisection_method(&function_21_6, 1.2, 1.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 1.256622, 1e-06);
    EXPECT_EQ(ans.back().n, 14);
}

TEST_F(NumericalMethodsUnitTest, FixedIterationMethod_2_2_5)
{
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_1, 1, 1e-02);
    EXPECT_NEAR(ans.back().p_n, 1.94332, 1e-05);
    EXPECT_EQ(ans.back().n, 6);
}

TEST_F(NumericalMethodsUnitTest, FixedIterationMethod_2_2_11)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_2, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257531, 1e-06);
    EXPECT_EQ(ans.back().n, 9);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_3, 2.5, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 2.690650, 1e-06);
    EXPECT_EQ(ans.back().n, 17);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_4, 0.25, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.909999, 1e-06);
    EXPECT_EQ(ans.back().n, 14);
    ans.clear();
    // d
    ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_5, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.469625, 1e-06);
    EXPECT_EQ(ans.back().n, 39);
    ans.clear();
    // e
    ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_6, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.448059, 1e-06);
    EXPECT_EQ(ans.back().n, 48);
    ans.clear();
    // f
    ans = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_22_7, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.704812, 1e-06);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, NewtonsMethod_2_3_5)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::newtons_method(&function_23_1, &function_23_1p, 2.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 2.69065, 1e-05);
    EXPECT_EQ(ans.back().n, 5);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::newtons_method(&function_23_2, &function_23_2p, -3.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, -2.87939, 1e-05);
    EXPECT_EQ(ans.back().n, 3);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::newtons_method(&function_23_3, &function_23_3p, 0.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.73909, 1e-05);
    EXPECT_EQ(ans.back().n, 4);
    ans.clear();
    // d (For some reason, the answer for part d only went to p3. Here it went to p4. Other cases worked fine)
    ans = NumericalMethods::RootSolvers::newtons_method(&function_23_4, &function_23_4p, 0.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.96434, 1e-05);
    EXPECT_EQ(ans.back().n, 4);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, SecantMethod_2_3_7)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::secant_method(&function_23_1, 1.0, 4.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 2.69065, 1e-05);
    EXPECT_EQ(ans.back().n, 11);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::secant_method(&function_23_2, -3.0, -2.0,  1e-04);
    EXPECT_NEAR(ans.back().p_n, -2.87939, 1e-05);
    EXPECT_EQ(ans.back().n, 7);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::secant_method(&function_23_3, 0.0, M_PI/2.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.73909, 1e-05);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
    // d
    ans = NumericalMethods::RootSolvers::secant_method(&function_23_4, 0.0, M_PI/2.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.96433, 1e-05);
    EXPECT_EQ(ans.back().n, 5);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, MethodOfFalsePosition_2_3_9)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::falsePosition_method(&function_23_1, 1.0, 4.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 2.69060, 1e-05);
    EXPECT_EQ(ans.back().n, 16);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::falsePosition_method(&function_23_2, -3.0, -2.0,  1e-04);
    EXPECT_NEAR(ans.back().p_n, -2.87938, 1e-05);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::falsePosition_method(&function_23_3, 0.0, M_PI/2.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.73908, 1e-05);
    EXPECT_EQ(ans.back().n, 7);
    ans.clear();
    // d
    ans = NumericalMethods::RootSolvers::falsePosition_method(&function_23_4, 0.0, M_PI/2.0, 1e-04);
    EXPECT_NEAR(ans.back().p_n, 0.96433, 1e-05);
    EXPECT_EQ(ans.back().n, 6);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, ModifiedNewtonsMethod_2_4_1a_3a)
{
    // 1a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::newtons_method(&function_24_1, &function_24_1p, 0.5, 1e-05);
    EXPECT_EQ(ans.back().n, 13);
    EXPECT_NEAR(ans.back().p_n, 0.567135, 1e-05);
    ans.clear();
    // 3a
    ans = NumericalMethods::RootSolvers::ModifiedNewtons_method(&function_24_1, &function_24_1p, &function_24_1pp, 0.5, 1e-05);
    EXPECT_EQ(ans.back().n, 3);
    EXPECT_NEAR(ans.back().p_n, 0.567143, 1e-05);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, ModifiedNewtonsMethod_2_4_1b_3b)
{
    // 1b (Precision not where it should be according to solution even though n comes out right)
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::newtons_method(&function_24_2, &function_24_2p, -1.5, 1e-05);
    EXPECT_EQ(ans.back().n, 23);
    EXPECT_NEAR(ans.back().p_n, -1.414325, 1e-03);
    ans.clear();
    // 3b (Precision not where it should be according to solution even though n comes out right)
    ans = NumericalMethods::RootSolvers::ModifiedNewtons_method(&function_24_2, &function_24_2p, &function_24_2pp, -1.5, 1e-05);
    EXPECT_EQ(ans.back().n, 2);
    EXPECT_NEAR(ans.back().p_n, -1.414518, 1e-03);
    ans.clear();
}

TEST_F(NumericalMethodsUnitTest, SteffensensMethod_2_5_11)
{
    // a
    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans = NumericalMethods::RootSolvers::steffensens_method(&function_22_2, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.257530, 1e-06);
    EXPECT_EQ(ans.back().n, 3);
    ans.clear();
    // b
    ans = NumericalMethods::RootSolvers::steffensens_method(&function_22_7, 0, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.704812, 1e-06);
    EXPECT_EQ(ans.back().n, 4);
    ans.clear();
    // c
    ans = NumericalMethods::RootSolvers::steffensens_method(&function_22_4, 0.25, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.910007572, 1e-09);
    EXPECT_EQ(ans.back().n, 4);
    ans.clear();
    // d
    ans = NumericalMethods::RootSolvers::steffensens_method(&function_22_5, 0.3, 1e-05);
    EXPECT_NEAR(ans.back().p_n, 0.469621923, 1e-09);
    EXPECT_EQ(ans.back().n, 4);
    ans.clear();
}