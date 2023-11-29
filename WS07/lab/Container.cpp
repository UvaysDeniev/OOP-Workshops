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
#include <iomanip>
#include <cstring>
#include <ostream>

#include "Container.h"

namespace sdds {


    // Sets the Container to an invalid empty state.
    void Container::setEmpty() {
        c_content[0] = '\0';
        c_capacity = 0;
        c_content_volume = 0;
    }

    // Constructor
    // Initializes the Container object with the given content, capacity, and content volume.
    // If the content is null, the content description is too long, or the content volume exceeds the capacity,
    // the container is set to an invalid state.
    Container::Container(const char* cont, int cap, int vol) {
        if (cont == nullptr || std::strlen(cont) > 50 || vol > cap) {
            setEmpty();
        }
        else {
            std::strncpy(c_content, cont, 50);
            c_content[50] = '\0';
            c_capacity = cap;
            c_content_volume = vol;
        }
    }

    // A value can be added to the Container.
    // If the container has enough space for the value, it will be added to the content volume.
    // Returns the actual amount that is added to the container.
    int Container::operator+=(int value) {
        if (c_content_volume + value <= c_capacity) {
            c_content_volume += value;
            return value;
        }
        else {
            int added = c_capacity - c_content_volume;
            c_content_volume = c_capacity;
            return added;
        }
    }

    // A value can be deducted from the Container.
    // If the container has enough amount, it will reduce the content volume by the value.
    // Returns the actual reduced amount.
    int Container::operator-=(int value) {
        if (c_content_volume >= value) {
            c_content_volume -= value;
            return value;
        }
        else {
            int reduced = c_content_volume;
            c_content_volume = 0;
            return reduced;
        }
    }

    // Returns true if the Container is in a valid state (non-empty and volume within capacity).
    // Otherwise, returns false.
    Container::operator bool() const {
        return c_content[0] != '\0' && c_capacity >= c_content_volume;
    }

    // Returns the capacity of the container.
    int Container::getCapacity() const {
        return c_capacity;
    }

    // Returns the current content volume of the container.
    int Container::getVolume() const {
        return c_content_volume;
    }

    // Sets the capacity and content description of the container.
    // If the capacity is positive and the content description is valid, the container is made valid.
    // Otherwise, it is set to an empty state.
    void Container::clear(int cap,const char* cont) {
        if (cap > 0 && cont != nullptr && std::strlen(cont) <= 50) {
            std::strncpy(c_content, cont, 50);
            c_content[50] = '\0';
            c_capacity = cap;
            c_content_volume = 0;
        }
        else {
            setEmpty();
        }
    }

    // Prints the container's content description, current volume, and capacity.
    // If the container is invalid, prints a placeholder message.
    void Container::print(std::ostream& out) const {
        if (*this) {
            out << c_content << ": (" << c_content_volume << "cc/" << c_capacity << ")";
        }
        else {
            out << "****: (**cc/***)";
        }
    }

    // Reads an amount to be added to the container.
    // If the container is invalid, prints an error message and exits.
    // If valid, prompts for an amount and adds it to the container, printing the added amount.
    void Container::read(std::istream& in) {
        // Check if the container is in a valid state.
        if (!*this) {
            // If the container is invalid (broken), display a message and exit the function.
            std::cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << std::endl;
            //std::cin.ignore(1000, '\n');
            return;
        }

        // Print the current state of the container.
        std::cout << "Add to " << c_content << ": (" << c_content_volume << "cc/" << c_capacity << ")\n> ";

        int amount;
        // Loop to ensure valid and in-range input.
        while (!(in >> amount) || amount < 1 || amount > 220000) {
            // Clear the input stream's error state if the input is invalid.
            in.clear();
            // Ignore characters until the next newline to reset the input stream.
            std::cin.ignore(1000, '\n');
            // Display appropriate error message based on the type of input error.
            std::cout << (in.fail() ? "Invalid Integer, retry: " : "Value out of range [1<=val<=220000]: ");
        }

        // Add the entered amount to the container and store the amount actually added.
        int added = *this += amount;
        std::cout << "Added " << added << " CCs\n";
    }

    std::ostream& operator<<(std::ostream& out, const Container& cc) {
        cc.print(out);
        return out;
    }

    std::istream& operator>>(std::istream& in, Container& cc) {
        cc.read(in);
        return in;
    }


}

