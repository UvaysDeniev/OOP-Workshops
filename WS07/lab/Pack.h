/*****************************************************************************
                           WORKHOP 7 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-10
*****************************************************************************/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include "Container.h"

namespace sdds {
    // The Pack class, derived from Container, represents a pack of units
    class Pack : public Container {
    private:
        int c_unitSize; // Size of each unit in the pack

    public:
        // Constructor
        Pack(const char* cont, int size, int unitSize = 330, int numUnits = 0);

        // Operator overloads for adding and removing units
        int operator+=(int numUnits);
        int operator-=(int numUnits);

        // Queries for unit size, number of units, and pack size
        int unit() const;
        int noOfUntis() const;
        int size() const;
        
        // Method to clear and reset the pack
        void clear(int size, int unitSize, const char* cont);

        // Print and read methods
        void print(std::ostream& out) const;
        void read(std::istream& in);
    };

    // Overloaded stream insertion and extraction operators
    std::ostream& operator<<(std::ostream& out, const Pack& p);
    std::istream& operator>>(std::istream& in, Pack& p);
}

#endif // SDDS_PACK_H
