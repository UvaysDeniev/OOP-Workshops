#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include<iostream>
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_lenght;
	public:
		Line();
		Line(const char* Cstring, int lenght);
		void getSpecs(std::istream& istr)override;
		void draw(std::ostream& ostr)const override;
	};
}
#endif // !SHAPE_H