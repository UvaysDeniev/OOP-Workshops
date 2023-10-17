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
#include <cstring> // for strcpy
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

   // The result would be the value of the Portfolio m_value.
   // This operator can not modify the Portfolio object.
   Portfolio::operator double() const
   {
      return m_value;
   }

   // The result would be the name of the stock m_stock.
   // This operator can not modify the Portfolio object.
   Portfolio::operator const char* () const
   {
      return m_stock;
   }

   // The result would be the type of investment m_type.
   // This operator can not modify the Portfolio object.
   Portfolio::operator char() const
   {
      return m_type;
   }

   // This will return TRUE if the type of the investment m_type is Growth 'G' or Value 'V or Investment 'I'.
   // For any other types, it will return FALSE.
   Portfolio::operator bool() const
   {
      return m_type == 'G' || m_type == 'V' ||  m_type == 'I';
   }


   // The bool operator ~() will return true if m_value is negative.
   // This operator can not modify the Portfolio object.
   bool Portfolio::operator~() const
   {
      return m_value < 0;
   }

   // if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted.
   // Reference of the Portfolio is returned after the operation.
   Portfolio& Portfolio::operator+=(double pValue)
   {
      // Checks if the current Portfolio object is valid and the input value is non-negative
      if (*this && pValue >= 0) {
         m_value += pValue;
      }
      return *this;
   }

   // if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted.
   // Reference of the Portfolio is returned after the operation.
   Portfolio& Portfolio::operator-=(double nValue)
   {
      // Checks if the current Portfolio object is valid and the input value is non-negative
      if (*this && nValue >= 0) {
         m_value -= nValue;
      }
      return *this;
   }

   // After this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios.
   // The Portfolio on the right is set to empty.
   // It is not allowed to invest values from a Portfolio back to itself. 
   // If any of the two portfolios don't evaluate to TRUE, no action should be taken.
   Portfolio& Portfolio::operator<<(Portfolio& rhs)
   {
      // Ensure the portfolios are different, and both portfolios evaluate to TRUE
      if (this != &rhs && *this && rhs) {
         m_value += rhs.m_value; // Transfer the value from rhs portfolio to this portfolio
         rhs.emptyPortfolio(); //rhs reset
      }
      return *this;
   }

   // After this operation, the total investment value of the Portfolio in the right will be the sum of both Portfolios.
   // The Portfolio on the left is set to empty.
   // It is not allowed to invest values from a Portfolio back to itself.If any of the two portfolios don't evaluate to TRUE, no action should be taken.
   Portfolio& Portfolio::operator>>(Portfolio& rhs)
   {
      // Ensure the portfolios are different, and both portfolios evaluate to TRUE
      if (this != &rhs && *this && rhs) {
         rhs.m_value += m_value; // Transfer the value from rhs portfolio to this portfolio
         emptyPortfolio();
      }
      return *this;
   }

   // The double value should be the sum of the m_values of the two Flights.
   // If any of the two Portfolios don't evaluate to TRUE, then zero is returned.
   double operator+(const Portfolio& lhs, const Portfolio& rhs) {
      if (lhs && rhs) {
         return double(lhs) + double(rhs);
      }
      return 0;
   }

   // The $dollar investment value of the right operand(Portfolio reference) should be added to the left operand(double reference)
   // Then the value of the double reference is returned.
   double operator+=(double& value, const Portfolio& portfolio) {
      if (portfolio) {
         value += double(portfolio);
      }
      return value;
   }

}