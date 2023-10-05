/*****************************************************************************
                           WORKSHOP 3 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-29
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"

namespace sdds {

   // Initializes the Train object to an invalid state
   void Train::initialize() {
      m_name = nullptr;
      m_noOfPassengers = -1; // if something is wrong, will display -1
      m_departureTime = -1; 
   }

   // Validates the time value
   bool Train::validTime(int value) const {
      return value >= MIN_TIME && value <= MAX_TIME && (value % 100) <= 59;
   }

   // Validates the number of passengers
   bool Train::validNoOfPassengers(int value) const {
      return value > 0 && value <= MAX_NO_OF_PASSENGERS;
   }
   // Sets the name of the Train dynamically
   void Train::set(const char* name) {
      delete[] m_name;
      m_name = nullptr;
      if (name && name[0] != '\0') {
         m_name = new char[strlen(name) + 1];
         strcpy(m_name, name);
      }
   }
   // Sets the number of passengers and departure time
   void Train::set(int noOfPassengers, int departure) {
      if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
         m_noOfPassengers = noOfPassengers;
         m_departureTime = departure;
      }
      else {
         m_noOfPassengers = -1;
         m_departureTime = -1;
      }
   }

   // Sets the name, number of passengers, and departure time
   void Train::set(const char* name, int noOfPassengers, int departure) {
      set(name);
      set(noOfPassengers, departure);
   }

   // Finalizes the use of the Train object
   void Train::finalize() {
      delete[] m_name;
      m_name = nullptr;
   }

   // Checks if any of the attributes are set to their invalid state
   bool Train::isInvalid() const {
      return !m_name || m_noOfPassengers == -1 || m_departureTime == -1;
   }

   // Returns the number of people on a train
   int Train::noOfPassengers() const {
      return m_noOfPassengers;
   }

   // Returns the name of a train
   const char* Train::getName() const {
      return m_name;
   }

   // Returns the time of departure
   int Train::getDepartureTime() const {
      return m_departureTime;
   }

   // Displays the information about a Train
   void Train::display() const {
      if (isInvalid()) {
         std::cout << "Train in an invalid State!" << std::endl;
      }
      else {
         std::cout << "NAME OF THE TRAIN:    " << m_name << std::endl;
         std::cout << "NUMBER OF PASSENGERS: " << m_noOfPassengers << std::endl;
         std::cout << "DEPARTURE TIME:       " << m_departureTime << std::endl;
      }
   }
}
