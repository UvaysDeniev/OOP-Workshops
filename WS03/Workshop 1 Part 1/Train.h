/*****************************************************************************
                           WORKSHOP 3 - PART 1
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-09-29
*****************************************************************************/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
   // Constant values
   const int MIN_TIME = 700;
   const int MAX_TIME = 2300;
   const int MAX_NO_OF_PASSENGERS = 1000;

   class Train {
   private:
      char* m_name;
      int m_noOfPassengers;
      int m_departureTime;

   public:
      void initialize();
      bool validTime(int value) const;
      bool validNoOfPassengers(int value) const;
      void set(const char* name);
      void set(int noOfPassengers, int departure);
      void set(const char* name, int noOfPassengers, int departure);
      void finalize();
      bool isInvalid() const;
      int noOfPassengers() const;
      const char* getName() const;
      int getDepartureTime() const;
      void display() const;
   };
}

#endif // SDDS_TRAIN_H
