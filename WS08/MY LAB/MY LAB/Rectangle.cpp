/*****************************************************************************
                           WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include<iomanip>
#include<iostream>
#include<cstring>
#include "Rectangle.h"

namespace sdds {
    // Default constructor
    Rectangle::Rectangle() :LblShape(), m_width(0), m_height(0) {}

    // Constructor with parameters
    Rectangle::Rectangle(const char* Cstring, int width, int height) :LblShape(Cstring), m_width(width), m_height(height) {
        if (m_height < 3 || m_width < static_cast<int>(strlen(label())) + 2) {
            setLabelToNull();
            m_width = 0;
            m_height = 0;
        }
    }


    // Function to read additional specifications for the rectangle
    void Rectangle::getSpecs(std::istream& istr) {
        LblShape::getSpecs(istr);
        istr.ignore(0, ',');
        istr >> m_width;
        istr.ignore(1, ',');
        istr >> m_height;
        istr.ignore(1000, '\n');
    }

    // Function to draw the rectangle
    void Rectangle::draw(std::ostream& ostr) const {
        if (this != nullptr && m_width > 0 && m_height > 0) {
            // Drawing the top of the rectangle
            ostr << '+';
            ostr << std::setw(m_width - 1) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;

            // Drawing the label line
            ostr << '|' << std::setw(m_width - 2) << std::left << label();
            ostr << std::right << std::setfill(' ') << '|' << std::endl;

            // Drawing the inside of the rectangle
            for (int i = 0; i < m_height - 3; ++i) {
                ostr << '|' << std::setw(m_width - 1) << std::right << '|' << std::endl;
            }

            // Drawing the bottom of the rectangle
            ostr << '+' << std::setw(m_width - 1) << std::setfill('-') << '+' << std::setfill(' ');
        }
    }
}

