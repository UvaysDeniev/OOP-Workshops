/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-22
*****************************************************************************/

#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds {

    class Graduate : public Student {
    private:
        char* thesisTitle;
        char* supervisor;

    public:
        Graduate();
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        ~Graduate();
        void display() const override;
    };

}

#endif //SDDS_GRADUATE_H