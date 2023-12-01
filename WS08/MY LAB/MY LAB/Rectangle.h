/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include<iostream>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* Cstring, int height, int width);
		void getSpecs(std::istream& istr) override;
		void draw(std::ostream& ostr ) const override;
	};
}
#endif // !SHAPE_H