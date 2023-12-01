/*****************************************************************************
                           WORKSHOP 10 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-12-01
*****************************************************************************/
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H

#include <cstddef> // for size_t
#include <iostream>

namespace sdds {

   // Function template for 'select'
   template <typename arrayType, typename keyType>
   int* select(const arrayType array[], const keyType& key, size_t size) {
      // Count occurrences of key
      int count = 0;
      for (size_t i = 0; i < size; ++i) {
         if (array[i] == key) {
            ++count;
         }
      }

      // Allocate dynamic array for indices
      int* indices = new int[count + 1]; // +1 for the terminator -1
      int idx = 0;

      for (size_t i = 0; i < size; ++i) {
         if (array[i] == key) {
            indices[idx++] = i;
         }
      }
      indices[idx] = -1; // Set the terminator
      return indices;
   }

   // Function template for 'csvDisplaySelection'
   template <typename arrayType>
   void csvDisplaySelection(const char* title, const arrayType array[], const int indices[]) {
      std::cout << title;
      if (indices && indices[0] != -1) { // Check if indices array is not null and not empty
         std::cout << std::endl;
         for (int i = 0; indices[i] != -1; ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << array[indices[i]];
         }
      }
      else {
         std::cout << "Empty Selection";
      }
      std::cout << std::endl;
   }

} // namespace sdds

#endif // SELECTION_H
