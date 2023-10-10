/*****************************************************************************
                           WORKSHOP 4 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-10
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "LabelMaker.h"


namespace sdds {

   // creates a dynamic array of Labels to the size of noOfLabels
   LabelMaker::LabelMaker(int noOfLabels)
   {
      lm_noOfLabels = noOfLabels;
      lm_labels = new Label[noOfLabels];
   }

   // Deallocates the memory when LabelMaker goes out of scope.
   LabelMaker::~LabelMaker()
   {
      delete[] lm_labels;
   }

   // Prints the Labels as demonstrated below 
   // (Assuming the above two labels are added to LabelMaker):
   void LabelMaker::readLabels()
   {
      for (int i = 0; i < lm_noOfLabels; ++i) {
         std::cout << "Enter label number " << (i + 1) << std::endl;
         std::cout << "> ";
         lm_labels[i].readLabel();
      }
   }

   // Gets the contents of the Labels as demonstrated below 
   // (Assuming there are two labels in the LabelMaker):
   void LabelMaker::printLabels()
   {
      for (int i = 0; i < lm_noOfLabels; ++i) {
         lm_labels[i].printLabel();
         std::cout << std::endl;
      }
   }

}