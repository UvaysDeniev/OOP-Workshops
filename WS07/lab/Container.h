/*****************************************************************************
						   WORKHOP 7 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-10
*****************************************************************************/

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds {

	// The Container class represents a generic container
	class Container {
		char c_content[51]; // Description of the container's content
		int c_capacity; // Maximum capacity of the container
		int c_content_volume; // Current volume of content in the container

	protected:
		// Protected methods for internal use
		void setEmpty();
		int getCapacity() const;
		int getVolume() const;

	public:
		// Constructor
		Container(const char* content, int capacity, int contentVolume = 0);

		// Operator overloads for modifying content volume
		int operator+=(int value);
		int operator-=(int value);
		
		// Type conversion to bool for validity check
		operator bool() const;

		// Methods for clearing, printing, and reading container data
		void clear(int cap, const char* cont);
		void print(std::ostream& out) const;
		void read(std::istream& in);
	};

	// Overloaded stream insertion and extraction operators
	std::ostream& operator<<(std::ostream& out, const Container& cc);
	std::istream& operator>>(std::istream& in, Container& cc);
}

#endif // SDDS_CONTAINER_H