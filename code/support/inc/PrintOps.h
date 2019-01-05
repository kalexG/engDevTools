//--------------------------
// Filename: PrintOps.h
// Created: 01/03/2018
// Last Modified: 01/03/2018
// Author: Kevin Gomez
//--------------------------

#ifndef PRINTOPS_H
#define PRINTOPS_H

#include <string>
#include <sstream>
#include "../../math/inc/Array.h"

namespace PrintOps
{
    std::string printArray(Array& arr);
    std::string printArrayInfo(Array& arr);
}

#endif // PRINTOPS_H
