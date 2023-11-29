/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-22
*****************************************************************************/

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {

    class Student {
    protected:
        char* name;
        int age;

    public:
        Student();
        Student(const char* name, int age);
        Student(const Student& other);
        Student& operator=(const Student& other);
        virtual ~Student();
        virtual void display() const;
    };

}

#endif //SDDS_GRADUATE_H
