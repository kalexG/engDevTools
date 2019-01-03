//---------------------------
// Filename: MathUnitTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//---------------------------

#include "../inc/MathUnitTest.h"

int main(int argc, char **argv) {

   testing::InitGoogleTest(&argc, argv);
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}
