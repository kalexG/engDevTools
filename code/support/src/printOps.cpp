//--------------------------
// Filename: printOps.cpp
// Created: 05/25/2018
// Last Modified: 05/25/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/prwOps.h"

void prwOps::printBool(bool boolean, string str1)
{
   if (str1.empty())
   {
      printf(">>>\n");
   }
   else
   {
      printf(">>> %s\n",str1.c_str());
   }
   printf("%s\n", boolean ? "True" : "False");
}

void prwOps::printScalar(double scalar, string str1)
{
   if (str1.empty())
   {
      printf(">>>\n");
   }
   else
   {
      printf(">>> %s\n",str1.c_str());
   }
   printf("%f\n", scalar);
}

void prwOps::printVector(double* vector, string str1)
{
   if (str1.empty())
   {
      printf(">>>\n");
   }
   else
   {
      printf(">>> %s\n",str1.c_str());
   }
   printf("| %f %f %f |\n", vector[0], vector[1], vector[2]);
}

void prwOps::printMatrix(double** matrix, string str1)
{
   if (str1.empty())
   {
      printf(">>>\n");
   }
   else
   {
      printf(">>> %s\n",str1.c_str());
   }
   printf("| %f %f %f |\n", matrix[0][0], matrix[0][1], matrix[0][2]);
   printf("| %f %f %f |\n", matrix[1][0], matrix[1][1], matrix[1][2]);
   printf("| %f %f %f |\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

void prwOps::printArray(myArray arr, string str1)
{
   if (str1.empty())
   {
      printf(">>>\n");
   }
   else
   {
      printf(">>> %s\n",str1.c_str());
   }

   for (int i=0;i<get<1>(arr);i++)
   {
      printf("| ");
      for(int j=0;j<get<2>(arr);j++)
      {
         printf("%f ",get<0>(arr)[i][j]);
      }
      printf("|\n");
   }
}
