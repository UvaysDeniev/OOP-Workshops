/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-22
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <cstring>
#include <iostream>

namespace sdds {

    // Default constructor
    Student::Student() : name(nullptr), age(0) {}

    // Parameterized constructor
    Student::Student(const char* name, int age) {
        this->age = age; // Set age

        // Allocate and copy name
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    // Copy constructor
    Student::Student(const Student& other) {
        age = other.age; // Copy age

        // Copy name
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else {
            name = nullptr;
        }
    }

    // Copy assignment operator
    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] name; // Free existing name

            age = other.age; // Copy age

            // Copy name
            if (other.name) {
                name = new char[strlen(other.name) + 1];
                strcpy(name, other.name);
            }
            else {
                name = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Student::~Student() {
        delete[] name; // Free allocated memory for name
    }

    // Display method
    void Student::display() const {
        // Display student information
        std::cout << "Name: " << (name ? name : "N/A") << "\nAge: " << age << std::endl;
    }

}