#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "HealthCard.h"
using namespace std;

namespace sdds {

   
    //Full name is a Cstring that is not null and not empty.
    //The main health number consists of 10 digits (>999999999 and <9999999999)
    //The version number consists of two characters
    //The Stock control number consists of nine characters

   bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
      return name && name[0] != '\0' && // Validate the full name
             number > 999999999 && number < 10000000000 && // Validate the main health number
             vCode[0] != '\0' && vCode[1] != '\0' && vCode[2] == '\0' && // Validate the version code
             sNumber[8] != '\0' && sNumber[9] == '\0'; // Validate the stock control number
   }


   //Sets the HeathCard object to a recognizable empty(invalid) state by setting m_name to nullptr;
   void HealthCard::setEmpty() {
      m_name = nullptr;
      m_number = 0;
      m_vCode[0] = '\0';
      m_sNumber[0] = '\0';
   }


   // Free the memory pointed by m_name
   // Allocate enough memory to store name Cstring
   // Copy the Cstring pointed by name into the newly allocated memory pointed by m_name

   void HealthCard::allocateAndCopy(const char* name)
   {
      delete[] m_name;
      if (name != nullptr) {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
   }

   //"peek()" and see if the next character in the keyboard buffer is the same as the ch argument

   //If it is the same, Remove it from the keyboard and throw it away!(i.e.istr.ignore())
   //   If not:
   //Ignore all the remaining characters(up to 1000 characters) or the value of ch(use istr.ignore(int n, char c))
   //   Set the istream into a fail state(use istr.setstate(iso::failbit))

   void HealthCard::extractChar(std::istream& istr, char ch) const
   {
      if (istr.peek() == ch) {
         istr.ignore();
      }
      else {
         istr.ignore(1000, ch);
         istr.setstate(std::ios::failbit);
      }


   }

   // Inserts the three parts related to the main card number,
   //  version code and stock number of the health card information into the ostr object in the following format :
   // 1234567890 - AB, XY7652341
   //   and then returns the ostr object reference

   std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const
   {
      ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
      // TODO: insert return statement here
      return ostr;
   }


   //Validates the arguments, reallocates memory for the name and sets the object attributes to their corresponding values.

   //   If the name and the three parts are valid(see Validation) call the private function to validate
   //   Calls the reallocateAndCopy function to set the name
   //   Sets the three parts to their values(m_number, m_vCode, m_sNumber)
   //   If not, it deletes the memory pointed by m_name and sets the object to a safe empty state(setEmpty())

   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      if (validID(name, number, vCode, sNumber)) {
         allocateAndCopy(name);
         m_number = number; 
         //strncpy(m_vCode, vCode, sizeof(m_vCode));
         strncpy(m_vCode, vCode, 2);
         m_vCode[2] = '\0'; // Ensure null-termination
         //strncpy(m_sNumber, sNumber, sizeof(m_sNumber));
         strncpy(m_sNumber, sNumber, 9);
         m_sNumber[9] = '\0';
      }
      else {
         if (m_name != nullptr) {
            delete[] m_name;
         }
         setEmpty();         
      }
   }

   HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      set(name, number, vCode, sNumber);
   }

   // if the hc object is valid it will set the values of the current object 
   // to those of the incoming argument (hc using assignment to *this).
   HealthCard::HealthCard(const HealthCard& hc){
      if (this != &hc) { // Protect against self-assignment
         set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
   }

   //First, it will make sure that this is not a "self-copy" by comparing the address of the current object
   //  and the address of the incoming argument.
   //   If it is not a self copy this function works exactly like the copy constructor
   //   If it is a self copy don't perform any action At the end return the reference of the current object.
   HealthCard& HealthCard::operator=(const HealthCard& hc)
   {
      if (this != &hc) {  // Protect against self-assignment
         set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
      }
      // TODO: insert return statement here
      return *this;
   }

   // deletes the memory pointed by m_name.
   HealthCard::~HealthCard()
   {
      delete[] m_name;
   }

   // Returns true if m_name is not nullptr, else it will return false
   HealthCard::operator bool() const
   {
      return m_name != nullptr;
   }

   // If the current object is in a valid state it inserts the values of the card information in two different formats based on the value of the toFile argument:

  // if toFile is true, prints the data in a comma - separated format :
  // prints the name
  //    print comma
  //    print the health card ID information using the private function printIDInfo
  //    if toFile is false prints the data in the following format :
  // In 50 characters, left - justified and padded with dots('.') : prints the name
  //    print the health card ID information using the private function printIDInfo
  //    At the end, it returns the ostr reference*/

   std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const
   {
      if (toFile) {
         ostr << m_name << ", ";
         printIDInfo(ostr);
      }
      else {
         ostr << std::left << std::setw(50) << std::setfill('.') << m_name;
         printIDInfo(ostr);
      }
      // TODO: insert return statement here
      return ostr;
   }

   
    // define local variables for the four parts.
    // using istream::get() read the name up to MaxNameLength or a comma (do not extract comma)
    // extract a comma using extractChar private function
    // extract the main health number into a local variable (istr >> m_number;)
    // extract a dash '-' using extractChar private function
    // extract the version number code into a vCode local variable using get for 3 char or up to ',' whichever comes first
    // extract a comma ',' using extractChar private function
    // extract the stock control number to the local variable (using get to read 10 char or up to '\n' whichever comes first)

    // if istr is not in a failure state
    // all data were read successfully, use the set private function to set values of the object to read value
    // before returning, clear the state using istr.clear() and ignore the remaining of the line until '\n'
    // at the end return the istr reference
 
   std::istream& HealthCard::read(std::istream& istr)
   {
      char name[MaxNameLength + 1];
      long long number; 
      char vCode[3]; 
      char sNumber[10];

      istr.get(name, MaxNameLength, ',');
      extractChar(istr, ',');
      istr >> number;
      extractChar(istr, '-');
      istr.get(vCode, 3, ',');
      extractChar(istr, ',');
      istr.get(sNumber, 10, '\n');

      if (!istr.fail()) {
         set(name, number, vCode, sNumber);
      }
      else {
         setEmpty();
      }

      istr.clear();
      istr.ignore(1000, '\n');
      // TODO: insert return statement here
      return istr;
   }

   // if hc is valid it will print it using the print function on the screen and not on File, 
   // (i.e. onFile is false). Otherwise, it will print "Invalid Card Number".
   // In the end, it will return the ostr reference.
   std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
   {
      if (hc) { //if valid
         hc.print(ostr, false); //// Print the health card information on the screen (not to file)
      }
      else {
         ostr << "Invalid Health Card Record";
      }
      // TODO: insert return statement here
      return ostr;
   }

   // returns the read method of the hc argument.
   std::istream& operator>>(std::istream& istr, HealthCard& hc)
   {
      // TODO: insert return statement here
      return hc.read(istr);
   }

}

