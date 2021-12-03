///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "ReadWriteable.h"

using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const ReadWriteable& write) 
	{
		write.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, ReadWriteable& read)
	{
		read.read(is);
		return is;
	}
}