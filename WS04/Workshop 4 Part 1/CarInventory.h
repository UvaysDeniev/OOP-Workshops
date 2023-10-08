/*****************************************************************************
                           WORKSHOP 4 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-06
*****************************************************************************/

#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

namespace sdds {

   class CarInventory {
      char* m_type;
      char* m_brand;
      char* m_model;
      int m_year;
      int m_code;
      double m_price;

      void resetInfo();

   public:
      

      CarInventory(); // Default Constructor
      CarInventory(const char* type, const char* brand, const char* model,
                   int year = 2022, int code = 100, double price = 1.0); // Overloaded Constructor
      ~CarInventory(); // Destructor bby!
      CarInventory& setInfo(const char* type, const char* brand, const char* model,
                             int year, int code, double price);

      void printInfo() const;
      bool isValid() const;
      bool isSimilarTo(const CarInventory& car) const;
   };

   // to check whether there are duplicate entries in the entire inventory:
   int find_similar(CarInventory car[], const int num_cars);

}


#endif //SDDS_CARINVENTORY_H