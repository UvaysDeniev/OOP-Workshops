/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
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
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
   struct Population {
      char postalCode[4];
      int population;
   };

   bool startsWith(const char* cString, const char* subString);
   bool getPostalCode(char* postal_code_prefix);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   void sort();
   void display();
   void deallocateMemory();

}
#endif // !SDDS_POPULATION_H_