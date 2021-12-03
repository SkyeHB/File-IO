///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "PubRecord.h"

namespace sdds
{
	class Book : public PubRecord
	{
		Date b_dueDate;
		long long b_ISBN;
		int b_memID;
		
	public:
		Book(); //set to safe empty state
		Book(const Book& bo); //copy con
		Book& operator=(const Book& bo); //assignment operator
		char recID() const; //returns media type in char form
		int memberID()const;//returns memID
		void checkIn(); //sets memID to 0 prints checked in
		void checkOut(); //checks out a book
		std::istream& read(std::istream& is = std::cin); //reads book object
		std::ostream& write(std::ostream& os = std::cout) const; //writes a book


	};
}
#endif	
