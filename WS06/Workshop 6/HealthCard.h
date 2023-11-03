/*****************************************************************************
                           WORKSHOP 6 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-03
*****************************************************************************/

#ifndef HEALTHCARD_H
#define HEALTHCARD_H

#include <iostream>

namespace sdds {

   // Maximum length for a name
   const int MaxNameLength = 55;

   class HealthCard {
   private:
      char* m_name{}; //  to hold the full name of a person which is Dynamically allocated
      long long m_number; // to hold the main health card number
      char m_vCode[3]; // Version code of the card
      char m_sNumber[10]; // Stock Control Number

      // Validates the four parts of the ID card
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;

      // Sets the HealthCard object to a recognizable empty (invalid) state
      void setEmpty();

      // Allocates memory for name and copies the content
      void allocateAndCopy(const char* name);

      // Checks and extracts a character from the input stream
      void extractChar(std::istream& istr, char ch) const;

      // Inserts the three parts related to the main card number, version code, and stock number
      std::ostream& printIDInfo(std::ostream& ostr) const;

      // Validates the arguments and sets the object attributes
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);

   public:
      // Constructors
      HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
      HealthCard(const HealthCard& hc); // Copy constructor

      // Copy assignment operator
      HealthCard& operator=(const HealthCard& hc);

      // Destructor
      ~HealthCard();

      // Boolean type conversion operator
      operator bool() const;

      // Prints the HealthCard information
      std::ostream& print(std::ostream& ostr, bool toFile = true) const;

      // Reads the HealthCard information from an input stream
      std::istream& read(std::istream& istr);
   };

   // Overloaded insertion operator for output
   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);

   // Overloaded extraction operator for input
   std::istream& operator>>(std::istream& istr, HealthCard& hc);

}


#endif // HEALTHCARD_H
