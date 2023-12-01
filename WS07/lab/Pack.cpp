/*****************************************************************************
                           WORKHOP 7 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-10
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Pack.h"

namespace sdds {

    // Constructor
    // Initializes the Pack object with the given content, size, unit size, and number of units.
    // Calls the base class constructor with calculated capacity and content volume.
    // If the unit size is less than or equal to zero, sets the Pack to an empty state.
    Pack::Pack(const char* cont, int size, int unitSize, int numUnits)
        : Container(cont, size* unitSize, numUnits* unitSize), c_unitSize(unitSize) {
        if (unitSize <= 0) {
            setEmpty();
        }
    }

    // operator+=
    // Shadows the operator+= of the Base class
    // Receives a number to add units to the pack and returns the number of units successfully added.
    int Pack::operator+=(int numUnits) {
        int addedUnits = Container::operator+=(numUnits * c_unitSize) / c_unitSize;
        return addedUnits;
    }

    // operator-=
    // Shadows the operator-= of the Base class
    // Receives a number to remove units from the pack and returns the number of units successfully removed.
    int Pack::operator-=(int numUnits) {
        int removedUnits = Container::operator-=(numUnits * c_unitSize) / c_unitSize;
        return removedUnits;
    }

    // unit
    // Returns the unit size attribute.
    int Pack::unit() const {
        return c_unitSize;
    }

    // noOfUnits
    // Returns the content volume of the Base class divided by the unit size.
    int Pack::noOfUntis() const {
        return getVolume() / c_unitSize;
    }

    // size
    // Returns the capacity of the base class divided by the unit size.
    int Pack::size() const {
        return getCapacity() / c_unitSize;
    }

    // clear
    // Overloads the clear function of the Base class.
    // Accepts three arguments: the Pack size, the unit size, and the content description.
    void Pack::clear(int size, int unitSize, const char* cont) {
        if (unitSize > 0) {
            Container::clear(size * unitSize, cont);
            this->c_unitSize = unitSize;
        }
        else {
            setEmpty();
        }
    }

    // print
    // Shadows the print of the Base class.
    // Displays a valid Pack in a specific format if the current object is valid.
    void Pack::print(std::ostream& out) const {
        Container::print(out);
        if (*this) {
            out << ", " << noOfUntis() << " in a pack of " << size();
        }
    }

    // read
    // Shadows the read of the Base class.
    // Gets a number for the count of the units to be added to the pack if the pack is valid and not full.
    void Pack::read(std::istream& in) {
        // Check if the Pack is in a valid state
        if (!*this) {
            // If invalid, print error message and exit the function
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
            //std::cin.ignore(1000, '\n');
            return;
        }

        // Check if the Pack is not full
        if (noOfUntis() < size()) {
            // Print the current state of the Pack
            std::cout << "Add to ";
            print(std::cout); // Use the print method
            std::cout << "\n> ";

            int numUnits;
            int maxUnits = size() - noOfUntis();
            // Foolproof integer entry loop
            while (!(in >> numUnits) || numUnits < 1 || numUnits > maxUnits) {
                // Clear the input stream and ignore incorrect input
                in.clear();
                std::cin.ignore(1000, '\n');
                // Print appropriate error message based on the type of input error
                if (in.fail()) {
                    std::cout << "Invalid Integer, retry: ";
                }
                else {
                    std::cout << "Value out of range [1<=val<=" << maxUnits << "]: ";
                }
            }

            // Add the entered number of units to the Pack
            int added = *this += numUnits;
            // Print the number of units successfully added
            std::cout << "Added " << added << "\n";
        }
        else {
            // If the Pack is full, print message and exit the function
            std::cout << "Pack is full!, press <ENTER> to continue..." << std::endl;
            std::cin.ignore(1000, '\n');
        }
    }

    std::ostream& operator<<(std::ostream& out, const Pack& p) {
        p.print(out);
        return out;
    }

    std::istream& operator>>(std::istream& in, Pack& p) {
        p.read(in);
        return in;
    }


}
