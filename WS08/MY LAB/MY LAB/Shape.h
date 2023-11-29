/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
	class Shape {
	public: 
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape() {};
	};
	std::istream& operator>>(std::istream& istr, Shape& shape);
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
}
#endif // !SHAPE_H

