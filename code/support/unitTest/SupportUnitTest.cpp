//------------------------------
// Filename: SupportUnitTest.cpp
// Created: 01/03/2018
// Last Modified: 01/03/2018
// Author: Kevin Gomez
//------------------------------

#include "../inc/SupportUnitTest.h"

int main(int argc, char **argv) {

   testing::InitGoogleTest(&argc, argv);
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}
