//---------------------------------
// Filename: Integrator_devTest.cpp
// Created: 01/02/2018
// Last Modified: 01/02/2018
// Author: Kevin Gomez
//---------------------------------

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/Integrator.h"
#include "../inc/IntegratorTrapz.h"
#include "../inc/IntegratorSimps.h"
#include "../inc/IntegratorMidpoint.h"

int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for Integrator!\n\n");

    // Creating Integrator object
    Integrator *integ1 = new IntegratorTrapz();
    Integrator *integ2 = new IntegratorSimps();
    Integrator *integ3 = new IntegratorMidpoint();
    
    // Free memory
    delete integ1;
    delete integ2;
    delete integ3;
    // Declaring variables

    return 0;
}
