/*****************************************************************************
                           WORKSHOP 1 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-14
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;

int main() {
   char filename[256];
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
