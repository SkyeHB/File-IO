///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#ifndef SDDS_MAGAZINE_H__
#define SDDS_MAGAZINE_H__
#include <iostream>
#include "PubRecord.h"

namespace sdds
{
	class Magazine : public PubRecord
	{
		int m_volume;
		int	m_issueNo;

	public:
		Magazine();
		Magazine(const Magazine& mag); //copy cons
		Magazine& operator=(const Magazine&); //assignment operator
		char recID()const; //returns media type in char form
		void checkIn(); // returns cant check out message
		void checkOut(); //returns cant check out message
		std::istream& read(std::istream& is = std::cin); //reads a magazine
		std::ostream& write(std::ostream& os = std::cout) const; //writes a magazine
	};
}
#endif
