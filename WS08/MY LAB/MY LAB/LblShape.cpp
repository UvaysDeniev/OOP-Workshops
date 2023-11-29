/*****************************************************************************
                           WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include<cstring>
#include "LblShape.h"

namespace sdds {
    // Function to get the label of the shape
    const char* LblShape::label() const {
        return m_label;
    }

    // Function to set the label to null
    void LblShape::setLabelToNull() {
        delete[] m_label;
        m_label = nullptr;
    }

    // Default constructor
    LblShape::LblShape() :m_label(nullptr) {}

    // Function to read the label from the input stream
    void LblShape::getSpecs(std::istream& istr) {
        setLabelToNull();
        if (istr) {
            char temp[100];
            istr.getline(temp, 1000, ',');
            m_label = new char[strlen(temp) + 1];
            strncpy(m_label, temp, strlen(temp) + 1);
        }
    }

    // Constructor with parameters
    LblShape::LblShape(const char* string) :m_label(nullptr) {
        if (string) {
            m_label = new char[strlen(string) + 1];
            strcpy(m_label, string);
        }
    }

    // Destructor
    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }
}



