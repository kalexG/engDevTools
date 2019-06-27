//--------------------------------
// Filename: PrintOps_unitTest.cpp
// Created: 01/03/2018
// Last Modified: 01/03/2018
// Author: Kevin Gomez
//--------------------------------

#include "../inc/SupportUnitTest.h"

TEST(PrintOpsTest, testPrintArray_squareArray)
{
    Array arr(4, 4);
    arr.setIncrement(1, 1);
    std::string arr_p = PrintOps::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 10 | 11 | 12 |\n| 13 | 14 | 15 | 16 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST(PrintOpsTest, testPrintArray_moreRows)
{
    Array arr(4, 3);
    arr.setIncrement(1, 1);
    std::string arr_p = PrintOps::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 |\n| 4 | 5 | 6 |\n| 7 | 8 | 9 |\n| 10 | 11 | 12 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST(PrintOpsTest, testPrintArray_moreCols)
{
    Array arr(3, 4);
    arr.setIncrement(1, 1);
    std::string arr_p = PrintOps::printArray(arr);
    std::string expectedString = "| 1 | 2 | 3 | 4 |\n| 5 | 6 | 7 | 8 |\n| 9 | 10 | 11 | 12 |"; 
    EXPECT_EQ(arr_p, expectedString); 
}

TEST(PrintOpsTest, testPrintArrayInfo_squareArray)
{
    Array arr(3, 3);
    std::string arr_i = PrintOps::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 3x3\nElements - 9\nSize - 72 Bytes\nSquare Array - true"; 
    EXPECT_EQ(arr_i, expectedString); 
}

TEST(PrintOpsTest, testPrintArrayInfo_moreRows)
{
    Array arr(4, 3);
    std::string arr_i = PrintOps::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 4x3\nElements - 12\nSize - 96 Bytes\nSquare Array - false"; 
    EXPECT_EQ(arr_i, expectedString); 
}

TEST(PrintOpsTest, testPrintArrayInfo_moreCols)
{
    Array arr(3, 5);
    std::string arr_i = PrintOps::printArrayInfo(arr);
    std::string expectedString = "Dimensions - 3x5\nElements - 15\nSize - 120 Bytes\nSquare Array - false"; 
    EXPECT_EQ(arr_i, expectedString); 
}
