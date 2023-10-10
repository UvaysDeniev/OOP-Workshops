/*****************************************************************************
                           WORKSHOP 4 - PART 2
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-10-10
*****************************************************************************/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

const char MAX_CHAR_SIZE = 70;

namespace sdds {

   class Label {
   private:
      char* m_frameArg;
      char* m_content;

   public:
      Label();
      Label(const char* frameArg);
      Label(const char* frameArg, const char* content);
      ~Label();

      std::istream& readLabel();
      std::ostream& printLabel() const;
      Label& text(const char* content);

   };

}

#endif // SDDS_LABEL_H