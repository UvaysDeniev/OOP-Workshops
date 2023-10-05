#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"

namespace sdds {

   void CarInventory::resetInfo()
   {
      m_type = nullptr;
      m_brand = nullptr;
      m_model = nullptr;
      m_year = 0;
      m_code = 0;
      m_price = 0.0;
   }


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


   bool CarInventory::isValid() const 
   {  
      return m_type != nullptr && m_brand != nullptr && m_model != nullptr
         && m_year >= 1990 && (m_code >= 100 && m_code <= 999) && m_price > 0;
   }

   bool CarInventory::isSimilarTo(const CarInventory& car) const
   {
      if (car.isValid() == this->isValid())
         return true;
      else
         return false;
   }


   int find_similar(CarInventory car[], const int num_cars)
   {
      return 0;
   }

}

