/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {


   void Flight::emptyPlane() {
      m_passengers = 0;
      m_fuel = 0;
      strcpy(m_title, "EmptyPlane");
   }

   // New Flight
   Flight::Flight() {
      emptyPlane();
   }
   Flight::Flight(int passengers, double fuel, const char* title) {
      emptyPlane();
      if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
         fuel <= FuelTankCapacity) {
         m_passengers = passengers;
         m_fuel = fuel;
         strcpy(m_title, title);
      }
   }
   std::ostream& Flight::display() const {

      if (*this) {
         cout << " Flight  |  Ready to Depart";
         cout << " ";
         cout.width(10);
         cout << std::string(*this);
         cout << " | ";
         cout << "Pass: ";
         cout.width(10);
         cout << int(*this);
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << double(*this);
         cout.unsetf(ios::right);
         cout << " Liters";
      }
      else if (~*this) {
         cout << " Flight  |  Empty Plane    ";
      }
      else {
         cout << " Flight  |  Low Fuel       ";
         cout << " ";
         cout.width(10);
         cout << (const char*)(*this);
         cout << " | ";
         cout << "Pass: ";
         cout.width(10);
         cout << int(*this);
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << double(*this);
         cout.unsetf(ios::right);
         cout << " Liters";
      }
      return cout;
   }

   //operator bool
   //Returns true if the Flight number of passengers is greater than 0,
   //and the amount of fuel in the plane's tank is equal to or greater than
   //the minimum required to carry the number of passengers currently on the plane.
   //otherwise false. This operator can not modify the Flight object.*/
   // The plane needs a minimum of 600 Liters of fuel for each passenger.
   // A Flight is considered Ready to Depart if there is at least one passenger on board,
   Flight::operator bool() const
   {
      return m_passengers > 0 && m_fuel >= m_passengers * 600;

   }

   //Returns the Flight number of passengers.This operator can not modify the Flight object.
   Flight::operator int() const
   {
      return m_passengers;
   }

   //Returns the Flight Fuel.This operator can not modify the Flight object.
   Flight::operator double() const
   {
      return m_fuel;
   }

   //Returns the Flight Title.This operator can not modify the Flight object.
   Flight::operator const char* () const
   {
      return m_title;
   }

   //This operator returns true if the Flight number of passengers is equal to 0,
   //otherwise, it will return false.This operator can not modify the Flight object.
   bool Flight::operator~() const // it took me TWO EFIN HOURS to realize that I missed const T_T
   {
      return m_passengers == 0;
   }

   // This action should move the Flight passengers and the Flight fuel, Flight title from one Flight to another;
   // therefore unlike the usual assignment operator that affects the left operand only,
   //this operator will affect both operands; the details of the left Flight will be set to the details of the right
   //Flightand the right Flight number of passengers will be set to 0, fuel to 0.00, and title to EmptyPlane.
    //A reference of the current object (Flight) should be returned.
   Flight& Flight::operator=(Flight& rhs) //rhs = right hand side
   {
      if (this != &rhs) {
         m_passengers = rhs.m_passengers;
         m_fuel = rhs.m_fuel;
         strcpy(m_title, rhs.m_title);
         rhs.m_passengers = 0;
         rhs.m_fuel = 0.00;
         strcpy(rhs.m_title, "EmptyPlane");

      }
      return *this;
   }

   //Doing so should set the Flight number of passengers of the Flight to the integer value,
   //only if the integer value is positive and less than or equal to the Boeing 747 Passenger Max Capacity.
   //A reference of the current object (Flight) should be returned.
   Flight& Flight::operator=(int passangers)
   {
      if (passangers > 0 && passangers <= Boen747Capacity) {
         m_passengers = passangers;
      }
      return *this;
   }

   // Doing so should set the Flight fuel of the Flight to the double value,
   // only if the double value is positive and less than the Boeng747 Fuel Tank Max Capacity.
   // A reference of the current object(Flight) should be returned.
   Flight& Flight::operator=(double fuel)
   {
      if (fuel > 0 && fuel < FuelTankCapacity) {
         m_fuel = fuel;
      }
      return *this;
   }

   //This should act like adding fuel into the Flight Tank. (i.e.the value of the double should be added to the m_fuel)
   //If the double value is negative or Flight Tank is full, no action should be taken.
   // You can fill the Flight Tank with more fuel, the double value, until the Flight Tank is full
   //In any case, a reference of the current object(Flight) should be returned.
   Flight& sdds::Flight::operator+=(double fuelAmount)
   {
      //if (fuelAmount > 0 && m_fuel + fuelAmount <= FuelTankCapacity) {
      //   m_fuel += fuelAmount;
      //}
      if (fuelAmount >= 0) {
         m_fuel += fuelAmount;
         if (m_fuel > FuelTankCapacity) m_fuel = FuelTankCapacity;
      }
      return *this;
   }

   //This should act like adding more passengers to the Flight.
   //(i.e.the value of the integer should be added to the m_passengers)
   //If the integer value is negative or Flight full, no action should be taken.
   //You can board more passengers into the Flight, the integer value, until the Flight FULL
   Flight& Flight::operator+=(int passangerCount)
   {
      if (passangerCount > 0 && passangerCount + m_passengers <= Boen747Capacity) {
         m_passengers += passangerCount;
      }
      return *this;
   }

   // This should act like pumping out fuel from the Flight Fuel Tank.
   //  (i.e. the value of the Flight fuel should be reduced by the double value)
   // If the double value is negative no action should be taken.You can pump fuel out of the Flight Tank until is empty.
   // It is not allowed for the m_fuel to be a negative number
   // In any case, a reference of the current object(Flight) should be returned.
   Flight& Flight::operator-=(double fuelAmount) {

      if (fuelAmount > 0) {
         m_fuel = (m_fuel - fuelAmount >= 0) ? m_fuel - fuelAmount : 0;
         // if (m_fuel - fuelAmount >= 0){
         // m_fuel -= fuelAmount;
         // } else {
         // m_fuel = 0;
         //}
      }
      return *this;
   }

   //This should act like disembarking a number of passengers from the Flight.
   //(i.e.the value of the Flight m_passengers should be reduced by the integer value)
   // If the integer value is negative no action should be taken.
   // The maximum you can deplane is the number of passengers the Flight currently has.
   // It is not allowed for the m_passengers to be a negative number
   // In any case, a reference of the current object(Flight) should be returned.
   Flight& Flight::operator-=(int passengerCount) {

      if (passengerCount > 0) {
         m_passengers = (m_passengers - passengerCount >= 0) ? m_passengers - passengerCount : 0;
      }
      return *this;
   }

   // After this operation,
   // the total number of passengers in the left Flight will be the sum of both up to the Maximum Capacity of the Boeing 747,
   // and the number of passengers in the right Flight will be zero or
   // the remaining number of passengers after the left plane reached its maximum capacity.
   // It is not allowed to move passengers from a plane back to itself. 
   // If any of the two flights don't evaluate to TRUE, no action should be taken.
   // A reference of the current object(Flight) should be returned.
   Flight& Flight::operator<<(Flight& rhs) {
      if (this != &rhs && *this && rhs) {
         int spaceLeft = Boen747Capacity - m_passengers;
         int totsPassengers = (spaceLeft > rhs.m_passengers) ? rhs.m_passengers : spaceLeft;
         // int passengersToMove;
         // if (spaceLeft > rhs.m_passengers) {
         //   passengersToMove = rhs.m_passengers;
         // }
         // else {
         //   passengersToMove = spaceLeft;
         // }*/
         m_passengers += totsPassengers;
         rhs.m_passengers -= totsPassengers;
      }
      return *this;
   }

   Flight& Flight::operator>>(Flight& rhs) {
      if (this != &rhs && *this && rhs) {
         int spaceLeft = Boen747Capacity - rhs.m_passengers;
         int totsPassengers = (spaceLeft > m_passengers) ? m_passengers : spaceLeft;
         rhs.m_passengers += totsPassengers;
         m_passengers -= totsPassengers;
      }
      return *this;
   }


   //he int value should be the sum of the number of passengers of the current flight and the other Flight.
   //If any of the two Flights don't evaluate to TRUE, then zero is returned.
   //This operator can not modify the Flight objects.
   int Flight::operator+(const Flight& other) const
   {
      if (*this && other) {
         return this->m_passengers + other.m_passengers;
      }
      else {
         return 0;
      }
   }

   //The number of the passengers of the right operand(Flight reference) should be added to the left operand(integer reference)
   //Then the value of the integer reference is returned.
   int operator+=(int& lhs, const Flight& rhs) {
      lhs += int(rhs);
      return lhs;
   }
}
