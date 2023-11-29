/*****************************************************************************
                           WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"

namespace sdds {
    // Overloaded output operator for Shape
    std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }

    // Overloaded input operator for Shape
    std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}

