/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   // Additional functions to read a record from the file and rewind the file
   bool readRecord(char* postalCode, int& population);
   void rewindFile();
   void closeFile();
}

#endif // !SDDS_FILE_H_


