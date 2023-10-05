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

      //This method resets the values for all member variables by setting type, brand, and model to nullptr
      // and setting the year, code, and price to 0.
      void resetInfo();

   public:
      
      //The default constructor will initialize the member variables by calling the resetInfo() method
      CarInventory(); // Default Constructor


      //This constructor will first reset the data and then dynamically keep
      //the values of the C-string argument in their corresponding attributes
      //and set the rest of the attributes the corresponding argument values if they pass validation.
      //When instantiated using this constructor, if the year, code or price arguments are not provided
      //they will be set to 2022, 100 and 1.0 using default values for the arguments.
      CarInventory(const char* type, const char* brand, const char* model,
                   int year, int code, double price); // Overloaded Constructor

      //This method will first deallocate all the allocated memoryand then set the attributes to 
      //the corresponding arguments exactly like the 6 - argument constructor.
      CarInventory& setInfo(const char* type, const char* brand, const char* model,
                             int year, int code, double price);

      //This method prints the values of all the member variables on the screen in the following format.
      //Order:
      //TYPE, BRAND, MODEL, YEAR, CODE, PRICE
      //  Spacing :
      //| 10  spaces | 16        spaces | 16        spaces | 9999 |   999 | 999999.99 |
      //| Left       | left             | Left             |      | right |     right |
      void printInfo() const;

      //This method returns whether all member variables have valid values
      //or not based on the criteria stated in the Private Member Variables.
      bool isValid() const;

      //This function is to check whether the type, make, brand and year of an object of CarInventory
      // are equal to another object of this class.
      //The function will return true only if all those values match.
      bool isSimilarTo(const CarInventory& car) const;

   };
   // to check whether there are duplicate entries in the entire inventory:
   int find_similar(CarInventory car[], const int num_cars);

}


#endif //SDDS_CARINVENTORY_H