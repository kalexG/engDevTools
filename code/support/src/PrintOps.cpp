//--------------------------
// Filename: PrintOps.cpp
// Created: 01/03/2018
// Last Modified: 01/03/2018
// Author: Kevin Gomez
//--------------------------

#include "../inc/PrintOps.h"

std::string PrintOps::printArray(Array& arr)
{
    int rows = arr.getMyRows();
    int cols = arr.getMyCols();
    std::ostringstream tmpStream;
    for (int i = 0; i < rows; i++)
    {
        tmpStream << "| ";
        for(int j = 0; j < cols; j++)
        {
            tmpStream << arr(i,j);
            if (j == cols - 1)
            {
                tmpStream << " |\n";
            }
            else
            {
                tmpStream << " | ";
            }
        }
    }
    std::string tmpString = tmpStream.str();
    tmpString.erase(tmpString.length() - 1);
    return tmpString;
}

std::string PrintOps::printArrayInfo(Array& arr)
{
    std::ostringstream tmpStream;
    tmpStream << "Dimensions - " << arr.getMyRows() << "x" << arr.getMyCols() << "\n";
    tmpStream << "Elements - " << arr.getMyElements() << "\n";
    tmpStream << "Size - " << arr.getMyArraySize() << " Bytes\n";
    tmpStream << "Square Array - " << std::boolalpha << arr.getIsSquare();
    std::string tmpString = tmpStream.str();
    return tmpString;
}
