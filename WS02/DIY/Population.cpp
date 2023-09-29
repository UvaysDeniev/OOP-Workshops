/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
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

#include <iostream>
#include <cstring>
#include "File.h"
#include "Population.h"

using namespace std;

namespace sdds {

   // Global variables to access in the code
   Population* populations = nullptr;
   int noOfPopulations = 0;
   
   // Given
   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   // Asking for user's input
   bool getPostalCode(char* postal_code_prefix) {
      std::cout << "Population Report" << std::endl;
      std::cout << "-----------------" << std::endl;
      std::cout << "Enter postal code:" << std::endl;
      std::cout << "> ";
      std::cin >> postal_code_prefix;
      return strcmp(postal_code_prefix, "!") != 0;
   }

   // Load
   bool load(const char* filename, const char* partial_postal_code_prefix) {
      // Opens the file
      if (!openFile(filename)) return false;

      // Check if the input is "all"
      bool loadAll = strcmp(partial_postal_code_prefix, "all") == 0;

      // Count the number of matching records
      char code[4];
      int population;
      while (readRecord(code, population)) {
         if (loadAll || startsWith(code, partial_postal_code_prefix)) {
            noOfPopulations++;
         }
      }

      // Allocate new memory
      populations = new Population[noOfPopulations];

      // Reset file pointer and load data
      rewindFile();
      int i = 0;
      while (readRecord(code, population)) {
         if (loadAll || startsWith(code, partial_postal_code_prefix)) {
            strcpy(populations[i].postalCode, code);
            populations[i].population = population;
            i++;
         }
      }

      // Close the file
      closeFile();

      return true;
   }

   // Copied and modified from Workshop 1
   void sort() {
      int i, j;
      Population temp;
      for (i = noOfPopulations - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (populations[j].population > populations[j + 1].population) {
               temp = populations[j];
               populations[j] = populations[j + 1];
               populations[j + 1] = temp;
            }
         }
      }
   }

   // Display the data
   void display() {
      sort();
      std::cout << "Postal Code: population" << std::endl;
      std::cout << "-------------------------" << std::endl;
      int totalPopulation = 0;
      for (int i = 0; i < noOfPopulations; i++) {
         std::cout << i + 1 << "- " << populations[i].postalCode 
                   << ":  " << populations[i].population << std::endl;
         totalPopulation += populations[i].population;
      }
      std::cout << "-------------------------" << std::endl;
      std::cout << "Population of the listed areas: " << totalPopulation << "\n" << std::endl;
   }

   // Should deallocate :D
   void deallocateMemory() {
      delete[] populations;
      populations = nullptr;
      noOfPopulations = 0;
   }

}

