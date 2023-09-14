/***********************************************************************
// OOP244 Workshop #1 lab
//
// File  w1p1.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Word.h"
#include "cStrTools.h"

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
