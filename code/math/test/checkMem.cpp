// Filename: testMvmaOps::cpp
// Created: 05/19/2018
// Last Modified: 05/19/2018
// Author: Kevin Gomez

#include <iostream>
#include <math.h>
#include <string.h>
#include "../inc/vmaOps.h"

int main( int argc, char *argv[] ) {

	// Inputs
	printf("You made it to test function for vmaOps!\n\n");

   // Creating vmaOps object
   //vmaOps vmaOps;

   // Declaring variables
   double **m1, **m2, **m3;
   myArray a1, a2, a3;

   //// Allocate Memory

   printf("Initializing matricies m[1-3]\n");
   vmaOps::mInit(&m1);
   vmaOps::mInit(&m2);
   vmaOps::mInit(&m3);

   printf("Initializing arrays a[1-3]\n");
   vmaOps::aInit(&a1, 4, 4);
   vmaOps::aInit(&a2, 4, 4);
   vmaOps::aInit(&a3, 4, 4);

   printf("Address of m1 is %p\n", (void *)m1);
   printf("Address of m2 is %p\n", (void *)m2);
   printf("Address of m3 is %p\n", (void *)m3);  
   printf("Address of a2 is %p\n", (void *)get<0>(a2));
   printf("Address of a1 is %p\n", (void *)get<0>(a1)); 
   printf("Address of a3 is %p\n", (void *)get<0>(a3)); 

   // Conduct Memory Tests

   //// Free Memory

   printf("Freeing matricies m[1-3]\n");
   vmaOps::mFree(&m1);
   vmaOps::mFree(&m2);
   vmaOps::mFree(&m3);

   printf("Freeing arrays a[1-3]\n");
   vmaOps::aFree(&a1);
   vmaOps::aFree(&a2);
   vmaOps::aFree(&a3);

   printf("Address of m1 is %p\n", (void *)m1);
   printf("Address of m2 is %p\n", (void *)m2);
   printf("Address of m3 is %p\n", (void *)m3);  
   printf("Address of a1 is %p\n", (void *)get<0>(a1)); 
   printf("Address of a2 is %p\n", (void *)get<0>(a2));
   printf("Address of a3 is %p\n", (void *)get<0>(a3)); 

   return 0;
}
