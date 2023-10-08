/*****************************************************************************
                           WORKSHOP 4 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-06
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"

namespace sdds {

   //This method resets the values for all member variables by setting type, brand, and model to nullptr
   // and setting the year, code, and price to 0.
   void CarInventory::resetInfo()
   {
      m_type = nullptr;
      m_brand = nullptr;
      m_model = nullptr;
      m_year = 0;
      m_code = 0;
      m_price = 0.0;
   }

   //The default constructor will initialize the member variables by calling the resetInfo() method
   CarInventory::CarInventory()
   {
      resetInfo();
   }

   //This constructor will first reset the data and then dynamically keep
   //the values of the C-string argument in their corresponding attributes
   //and set the rest of the attributes the corresponding argument values if they pass validation.
   //When instantiated using this constructor, if the year, code or price arguments are not provided     
   //they will be set to 2022, 100 and 1.0 using default values for the arguments.
   CarInventory::CarInventory(const char* type, const char* brand, const char* model,
                              int year, int code, double price)
   {
      resetInfo();

      this->m_type = new char[strlen(type) + 1];
      strcpy(this->m_type, type);

      this->m_brand = new char[strlen(brand) + 1];
      strcpy(this->m_brand, brand);

      this->m_model = new char[strlen(model) + 1];
      strcpy(this->m_model, model);

      m_year = year;
      m_code = code;
      m_price = price;

   }

   // Not sure if this is correct but I felt like destructor was a must.
   CarInventory::~CarInventory()
   {
      delete[] m_type;
      delete[] m_brand;
      delete[] m_model;
   }


   // This method will first deallocate all the allocated memory and then set the attributes to 
   // the corresponding arguments exactly like the 6 - argument constructor.
   CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model,
                                                              int year, int code, double price)
   {
      delete[] m_type;
      delete[] m_brand;
      delete[] m_model;

      this->m_type = new char[strlen(type) + 1];
      strcpy(this->m_type, type);

      this->m_brand = new char[strlen(brand) + 1];
      strcpy(this->m_brand, brand);

      this->m_model = new char[strlen(model) + 1];
      strcpy(this->m_model, model);

      m_year = year;
      m_code = code;
      m_price = price;
      
      return *this;
   }

   //This method prints the values of all the member variables on the screen in the following format.
   //Order:
   //TYPE, BRAND, MODEL, YEAR, CODE, PRICE
   //  Spacing :
   //| 10  spaces | 16        spaces | 16        spaces | 9999 |   999 | 999999.99 |
   //| Left       | left             | Left             |      | right |     right |
   void CarInventory::printInfo() const {
      std::cout << "| " << std::left << std::setw(11) << m_type
                << "| " << std::setw(17) << m_brand
                << "| " << std::setw(17) << m_model
                << "|" << std::right << std::setw(5) << m_year
                << " | " << std::setw(4) << m_code
                << " |" << std::setw(10) << std::fixed << std::setprecision(2) << m_price
                << " |" << std::endl;
   }

   //This method returns whether all member variables have valid values
   //or not based on the criteria stated in the Private Member Variables.
   bool CarInventory::isValid() const 
   {  
      return m_type != nullptr && m_brand != nullptr && m_model != nullptr
         && m_year >= 1990 && (m_code >= 100 && m_code <= 999) && m_price > 0;
   }

   //This function is to check whether the type, make, brand and year of an object of CarInventory
   // are equal to another object of this class.
   //The function will return true only if all those values match.
   bool CarInventory::isSimilarTo(const CarInventory& car) const
   {
      if (!m_type || !m_brand || !m_model || !car.m_type || !car.m_brand || !car.m_model) {
         return false;
      }
      return strcmp(m_type, car.m_type) == 0 &&
             strcmp(m_brand, car.m_brand) == 0 &&
             strcmp(m_model, car.m_model) == 0 &&
             m_year == car.m_year;
   }

   // It returns the index of the first match, if it finds two CarInventory objects that have
   // similar information in the car array.See below for the function implementation logic:
   int find_similar(CarInventory car[], const int num_cars)
   {
      for (int i = 0; i < num_cars; i++) {
         for (int j = i + 1; j < num_cars; j++) {
            if (car[i].isSimilarTo(car[j])) {
               return i;
            }
         }
      }
      return -1; // if wrong return -1
   }

}

