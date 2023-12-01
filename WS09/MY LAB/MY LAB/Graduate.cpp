/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-22
*****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include "Graduate.h"


namespace sdds {

    Graduate::Graduate() : Student(), thesisTitle(nullptr), supervisor(nullptr) {}

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor)
        : Student(name, age) {
        // Allocate and copy thesis title
        this->thesisTitle = new char[strlen(thesisTitle) + 1];
        strcpy(this->thesisTitle, thesisTitle);

        // Allocate and copy supervisor name
        this->supervisor = new char[strlen(supervisor) + 1];
        strcpy(this->supervisor, supervisor);
    }

    Graduate::Graduate(const Graduate& other) : Student(other) {
        // Copy thesis title
        if (other.thesisTitle) {
            thesisTitle = new char[strlen(other.thesisTitle) + 1];
            strcpy(thesisTitle, other.thesisTitle);
        }
        else {
            thesisTitle = nullptr;
        }

        // Copy supervisor name
        if (other.supervisor) {
            supervisor = new char[strlen(other.supervisor) + 1];
            strcpy(supervisor, other.supervisor);
        }
        else {
            supervisor = nullptr;
        }
    }

    Graduate& Graduate::operator=(const Graduate& other) {
        if (this != &other) {
            // Call base class assignment operator
            Student::operator=(other);

            // Delete existing data
            delete[] thesisTitle;
            delete[] supervisor;

            // Copy thesis title
            if (other.thesisTitle) {
                thesisTitle = new char[strlen(other.thesisTitle) + 1];
                strcpy(thesisTitle, other.thesisTitle);
            }
            else {
                thesisTitle = nullptr;
            }

            // Copy supervisor name
            if (other.supervisor) {
                supervisor = new char[strlen(other.supervisor) + 1];
                strcpy(supervisor, other.supervisor);
            }
            else {
                supervisor = nullptr;
            }
        }
        return *this;
    }

    Graduate::~Graduate() {
        // Free allocated memory
        delete[] thesisTitle;
        delete[] supervisor;
    }

    void Graduate::display() const {
        // Display student information
        Student::display();

        // Display graduate-specific information
        std::cout << "Thesis Title: " << (thesisTitle ? thesisTitle : "N/A") << "\nSupervisor: " << (supervisor ? supervisor : "N/A") << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }


}