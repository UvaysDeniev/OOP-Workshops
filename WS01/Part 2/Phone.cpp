/*****************************************************************************
                           WORKSHOP 1 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-19
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;

namespace sdds {

   void displayRecord(const char* name, const char* areaCode, const char* prefix, const char* number) {
      cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
   }

   void phoneDir(const char* programTitle, const char* fileName) {

      char name[51], areaCode[4], prefix[4], number[5];
      char search[51];
      char lowerName[51];
      char lowerSearch[51];
      bool found;

      FILE* phoneFile = fopen(fileName, "r");

      cout << programTitle << " phone direcotry search" << endl;
      cout << "-------------------------------------------------------" << endl;

      if (!phoneFile) {
         cout << fileName << " file not found!" << endl;
      }
      else {
         do {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin >> search;

            toLowerCaseAndCopy(lowerSearch, search); // Convert search to lowercase

            if (lowerSearch[0] != '!') {
               found = false;
               rewind(phoneFile); // Reset file pointer to beginning

               while (fscanf(phoneFile, "%[^\t]\t%s\t%s\t%s\n", name, areaCode, prefix, number) != EOF) {

                  toLowerCaseAndCopy(lowerName, name); // Convert name to lowercase

                  if (strStr(lowerName, lowerSearch)) {
                     displayRecord(name, areaCode, prefix, number);
                     found = true;
                  }
               }
               if (!found) {
                  // do nothing
               }
            }
         } while (lowerSearch[0] != '!');
         fclose(phoneFile);
      }
      cout << "Thank you for using " << programTitle << " directory." << endl;
   }
}