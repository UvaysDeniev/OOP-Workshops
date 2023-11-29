/*****************************************************************************
                           WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "Line.h"

namespace sdds {
    // Default constructor
    Line::Line() :LblShape(), m_lenght(0) {}

    // Constructor with parameters
    Line::Line(const char* Cstring, int lenght) :LblShape(Cstring), m_lenght(lenght) {}

    // Function to read additional specifications for the line
    void Line::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr);
        istr >> m_lenght;
        istr.ignore(10000, '\n');
    }

    // Function to draw the line
    void Line::draw(std::ostream& ostr) const {
        if (m_lenght > 0 && label() != nullptr) {
            ostr << label() << std::endl;
            for (int i = 0; i < m_lenght; i++) {
                ostr << '=';
            }
        }
    }
}
