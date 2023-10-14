/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*****************************************************************************
                           WORKSHOP 5 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-13
*****************************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      //Binary arithmetic: + - * / %
      //Assignment(simple and compound): = += -= *= /= %=
      //Unary(pre - fix post - fix plus minus): ++ -- + -
      //Relational: == < > <= >= !=
      //Logical: && || !
      //Insertion, extraction: << >>

      // Unary(one operand) : Post - fix increment / decrement, pre - fix increment / decrement, pre - fix plus, pre - fix minus
      // Binary(two operand) : Assignment, compound assignment, arithmetic, relational, logical
      // Ternary(three operands) : Conditional operator

      
      /* type conversion operators */
      
      //operator bool
      operator bool() const;

      //operator int
      operator int() const;

      //operator double
      operator double() const;
      
      //operator const char*
      operator const char* () const;

      /* Unary member operator */
      /* return_type operator symbol() */

      // **bool operator ~**
      bool operator~() const;

      /*Binary member operators */
      /*return_type operator symbol (type [identifier])*/
  
      //assignment operators:  = += -= *= /= %=*/
     
      //overload the assignment operator so a Flight can be set to another Flight object.
      Flight& operator=(Flight& rhs); // right hand side
      //Overload the assignment operator so a Flight can be set to an integer.
      Flight& operator=(int passangers);
      //Overload the assignment operator so a Flight can be set to a double. 
      Flight& operator=(double fuel);
      //Overload the += operator to add a double value to a Flight.
      Flight& operator+=(double fuel);
      //Overload the += operator to add an integer value to a Flight.
      Flight& operator+=(int newPassangers);
      //overload the -= operator to reduce a Flight fuel by a double value. 
      Flight& operator -=(double newFuel);
      //Overload the -= operator to reduce the number of passengers in a Flight fuel by an integer value.
      Flight& operator -=(int newPassangers);
      //Overload the << operator* (left shift operator) to move passengers from the right Flight to the left.
      Flight& operator <<(Flight& rightToLeft);
      //Overload the >> operator (right shift operator) to move passengers from the left Flight to the right.
      Flight& operator >>(Flight& leftToRight);

      //Overload the binary member + operator that accepts a constant Flight reference and returns a int value.
      int operator+(const Flight& flight) const;
   };

   //create a binary stand alone helper += operator that accepts an int reference at left
   //and a constant Flight reference at right and returns an int value. 
   int operator+=(int& lhs, const Flight& rhs);

}
#endif // SDDS_FLIGHT_H