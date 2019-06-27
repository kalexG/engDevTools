//---------------------------------------
// Filename: IntegratorTrapz_unitTest.cpp
// Created: 01/10/2018
// Last Modified: 01/10/2018
// Author: Kevin Gomez
//---------------------------------------

#include "../inc/MathUnitTest.h"

TEST_F(IntegratorTrapzUnitTest, integrateLongVector_w_timeVector_wo_init)
{
    Integrator *integ1 = new IntegratorTrapz();
    LongVector dx(5);
    LongVector t(5);
    dx(0) = 1; dx(1) = 4; dx(2) = 9; dx(3) = 16; dx(4) = 25;
    t(0) = 1; t(1) = 2; t(2) = 3; t(3) = 4; t(4) = 5;
    LongVector x(5);
    x = integ1->integrateComposite(dx, t);
    //EXPECT_EQ(integ1->integrateComposite(dx, t), 42);
}
