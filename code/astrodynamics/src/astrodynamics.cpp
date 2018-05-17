// Filename: astrodynamics.cpp
// Created: 03/31/2018
// Last Modified: 03/31/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/astrodynamics.h"
using namespace std;

void twoBodyOrbitalMech::newtonLawOfG(double* Fg, double m1, double m2, double r_mag, double* r)
{
   double tmp; int i;
   tmp=-G*m1*m2/(r_mag*r_mag*r_mag);
   for(i=0;i<3;i++)
   {
   Fg[i]=tmp*r[i];
   }
}
