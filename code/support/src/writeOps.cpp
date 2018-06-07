//--------------------------
// Filename: writeOps.cpp
// Created: 05/25/2018
// Last Modified: 05/25/2018
// Author: Kevin Gomez
//--------------------------

// Need class definition
#include "../inc/supportOps.h"

void supportOps::wDppArray2Csv(tuple<double**,int,int> arr, string fileName)
{
   int row = get<1>(arr);
   int col = get<2>(arr);
   fileWrite = fopen (fileName.c_str(),"w");
   fprintf(fileWrite,"%dx%d Array\n",row,col);
   for (int i=0;i<row;i++)
   {
      for (int j=0;j<col;j++)
      {
         if (j+1==col)
         {
            fprintf(fileWrite,"%f", get<0>(arr)[i][j]);
         }
         else
         {
            fprintf(fileWrite,"%f, ", get<0>(arr)[i][j]);
         }
      }
      fprintf(fileWrite,"\n");
   }
   
   fclose (fileWrite);
}
