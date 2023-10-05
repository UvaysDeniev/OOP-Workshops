/*****************************************************************************
                           WORKSHOP 3 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-03
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Train.h"

namespace sdds {


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

   // Attempts to board passengers onto the Train.
   // If the total number of passengers after boarding exceeds the maximum limit,
   // it sets the unboardedPassengers to the number of passengers left unboarded.
   // Returns true if all passengers are boarded, false otherwise.
   bool Train::load(int& unboardedPassangers)
   {
      int passangersToBoard;

      std::cout << "Enter number of passengers boarding:" << std::endl;
      std::cout << "> ";
      std::cin  >> passangersToBoard;

      if (m_noOfPassengers + passangersToBoard > MAX_NO_OF_PASSENGERS) {
         unboardedPassangers = (m_noOfPassengers + passangersToBoard) - MAX_NO_OF_PASSENGERS;
         m_noOfPassengers = MAX_NO_OF_PASSENGERS;
         return false;
      }
      else {
         m_noOfPassengers += passangersToBoard;
         unboardedPassangers = 0;
         return true;
      }
   }


   // Prompts the user to update the departure time of the train.
   // Validates the entered time and updates the departure time if valid.
   // If the entered time is not valid, sets the departure time to -1.
   // Returns true if the update was successful, false otherwise.
   bool Train::updateDepartureTime()
   {
      int enteredTime;
      std::cout << "Enter new departure time:" << std::endl;
      std::cout << "> ";
      std::cin >> enteredTime;

      if (validTime(enteredTime)) {
         m_departureTime = enteredTime;
         return true;
      }
      else {
         m_departureTime = -1;
         return false;
      }
   }

   // Transfers passengers from another Train (provided as an argument)
   //  to the current Train.
   // Also concatenates the names of the two trains.
   // Returns true if the transfer was successful, false otherwise.
   bool Train::transfer(const Train& otherChooChoo) {

      // Check if both the current Train (this) and the otherChooChoo Train are in valid states.
      if (!this->isInvalid() && !otherChooChoo.isInvalid()) {

         // Dynamically allocate memory for a new C-string to store the concatenated names of the two trains.
         char* newName = new char[strlen(m_name) + strlen(otherChooChoo.m_name) + 3]; // +3 for ", " and null terminator

         // Copy the name of the current Train object into the newName string.
         strcpy(newName, m_name);
         // Append a comma and space to the newName string.
         strcat(newName, ", ");
         // Append the name of the otherChooChoo Train object to the newName string.
         strcat(newName, otherChooChoo.m_name);

         // Calculate the total number of passengers by adding the passengers from the current Train and the otherChooChoo Train.
         int newPassengers = m_noOfPassengers + otherChooChoo.m_noOfPassengers;

         if (newPassengers > MAX_NO_OF_PASSENGERS) {
            std::cout << "Train is full; " << (newPassengers - MAX_NO_OF_PASSENGERS)
                      << " passengers of " << otherChooChoo.m_name << " could not be boarded!" << std::endl;
            newPassengers = MAX_NO_OF_PASSENGERS;
         }
         delete[] m_name; // Delete the old name of the current Train object to free up the memory.
         m_name = newName;// Assign the concatenated name (newName) to the current Train object.
         m_noOfPassengers = newPassengers; // Update the passenger count of the current Train object with the new total.
         return true;
      }
      else {
         return false;
      }
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