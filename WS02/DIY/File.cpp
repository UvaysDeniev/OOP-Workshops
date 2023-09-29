/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
/*****************************************************************************
                           WORKSHOP 2 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-28
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   bool readRecord(char* postalCode, int& population) {
      return fscanf(fptr, "%3[^,],%d\n", postalCode, &population) == 2;
   }

   void rewindFile() {
      rewind(fptr);
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }
}

