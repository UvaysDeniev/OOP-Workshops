/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_


namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

      void emptyPortfolio();

   public:

      Portfolio();
      Portfolio(double value, const char* stock, char type);

      void dispPortfolio() const;
      std::ostream& display() const;

      /****Operatorand conversion overloads****/

      // Portfolio can be casted to a double(double type).
      operator double() const;

      // Portfolio can be casted to C - string(const char* type).
      operator const char* () const;

      // Portfolio can be casted to a char(char type).
      operator char() const;

      // Portfolio can be casted to a bool(boolean type).
      operator bool() const;

      // The bool operator ~() will return true if m_value is negative.
      // This operator can not modify the Portfolio object.
      bool operator~() const;

      // A double can be added to the value of the Portfolio m_value using += operator;
      Portfolio& operator+=(double pValue);

      // A double can be subtracted from the value of the Portfolio m_value using -= operator;
      Portfolio& operator-=(double nValue);

      // overload the << operator* (left shift operator) to move $dollar investment value m_value from Portfolio in the right to the left.
      Portfolio& operator<<(Portfolio& rhs);

      // overload the >> operator* (right shift operator) to move $dollar investment value m_value from Portfolio in the left to the right.
      Portfolio& operator>>(Portfolio& rhs);
   };

   /****Binary helper operators****/

   // create a binary stand alone helper + operator that accepts a constant Portfolio reference at left and another constant Portfolio reference at right and returns a double value.
   double operator+(const Portfolio& left, const Portfolio& right);

   // create a binary stand alone helper += operator that accepts a double reference at left and a constant Portfolio reference at right and returns a double value.
   double operator+=(double& value, const Portfolio& portfolio);
}
#endif // SDDS_Portfolio_H_