/*****************************************************************************
						   WORKHOP 8 - LAB
Author	    : Uvays Deniev
Student ID# : 123026221
Email       : udeniev@myseneca.ca
Section     : NCC
Date        : 2023-11-19
*****************************************************************************/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H


#include<iostream>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label;
	protected:
		const char* label()const;
	public:
		void setLabelToNull();
		LblShape();
		LblShape(const char* string);

		LblShape(const LblShape& other) = delete;
		LblShape& operator=(const LblShape& other) = delete;

		void getSpecs(std::istream& istr) override;

		~LblShape();
	};
}
#endif // !SHAPE_H