/*****************************************************************************
                           WORKSHOP 4 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-10
*****************************************************************************/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

#include "Label.h"

namespace sdds {

   class LabelMaker {
   
      Label* lm_labels;
      int lm_noOfLabels;

   public:
      LabelMaker(int noOfLabels);
      ~LabelMaker();

      void readLabels();
      void printLabels();
   };

   
}

#endif // SDDS_LABELMAKER_H
