/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*****************************************************************************
                           WORKSHOP 5 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-17
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <ostream> // for std ostream
#include <iostream> // for cout
#include "Portfolio.h"


using namespace std;
namespace sdds {

   void Portfolio::emptyPortfolio()
   {
      m_value = 0;
      m_stock[0] = 0;
      m_type = 'E';
   }

   Portfolio::Portfolio() {
      emptyPortfolio();
   }


   Portfolio::Portfolio(double value, const char* stock, char type) {
      emptyPortfolio();
      if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
         m_value = value;
         m_type = type;
         strcpy(m_stock, stock);
      }
   }

   void Portfolio::dispPortfolio() const {
      cout << " ";
      cout.width(10);
      cout << (const char*)(*this);
      cout << " | ";
      cout << "Value: ";
      cout.width(10);
      cout << double(*this);
      cout << " | ";
      cout << " Type: ";
      cout << char(*this);
   }
   std::ostream& Portfolio::display() const {

      if (~*this) {
         cout << " Portfolio  |  Bad-NG |";
         dispPortfolio();
      }
      else if (*this) {
         cout << " Portfolio  |  Active |";
         dispPortfolio();

      }
      else {
         cout << " Portfolio  |  EMPTY  |";
         dispPortfolio();
      }
      return cout;
   }





}