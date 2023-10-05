#include "CarInventory.h"

namespace sdds {

   void CarInventory::resetInfo()
   {
      m_type = nullptr;
      m_brand = nullptr;
      m_model = nullptr;
      m_year = 0;
      m_code = 0;
      m_price = 0;
   }


   CarInventory::CarInventory()
   {
      resetInfo();
   }

   CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
   {
      resetInfo();

   }



   CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
   {
      // TODO: insert return statement here
   }

   void CarInventory::printInfo() const {

   }

   bool CarInventory::isValid() const
   {
      return false;
   }

   bool CarInventory::isSimilarTo(const CarInventory& car) const
   {
      return false;
   }


   int find_similar(CarInventory car[], const int num_cars)
   {
      return 0;
   }

}

