///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#ifndef SDDS_READWRITEABLE_H__
#define SDDS_READWRITEABLE_H__
#include <iostream>

namespace sdds
{
	class ReadWriteable
	{
	public:
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
	};
	std::ostream& operator<<(std::ostream& os, const ReadWriteable& write);		//writes an object
	std::istream& operator>>(std::istream& is, ReadWriteable& read);			//reads an object
}

#endif
