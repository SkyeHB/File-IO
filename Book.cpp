///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds
{
	
	Book::Book() : PubRecord(), b_dueDate(), b_ISBN(0), b_memID(0)
	{}
	//Copy constructor 
	Book::Book(const Book& bo)
	{
		*this = bo;
	}
	//assignment operator
	Book& Book::operator=(const Book& bo)
	{
		if (this != &bo)
		{
			b_ISBN = bo.b_ISBN;
			b_memID = 0;
			PubRecord::operator=(bo);
			b_dueDate = bo.b_dueDate;
		}
		return *this;
	}
	
	char Book::recID() const
	{
		return 'B';
	}
	
	int Book::memberID() const
	{
		return b_memID;
	}
	//checks in a book
	void Book::checkIn()
	{
		b_memID = 0;
		cout << name() << " checked in!" << endl;
	}
	//validates member id, validates the return date and then checks out a book if valid
	void Book::checkOut()
	{
		int tmpMemID;
		int check = -1;
		Date tmpDate;
		cout << "Entere Member id: ";
		while (check != 1)
		{
			cin >> tmpMemID;
			if (cin.fail() || tmpMemID > 99999 || tmpMemID < 10000)
			{
				cout << "Invalid Member ID, Enter again: ";
				cin.clear();
				while (cin.get() != '\n');
				check = -1;
			}
			else
			{
				b_memID = tmpMemID;
				check = 1;
			}
		}
		while (check != 2)
		{
			cout << "Enter return date: ";
			b_dueDate.read();
			if (b_dueDate.errCode() == NO_ERROR)
			{
				check = 2;
			}
			else
			{
				cout << b_dueDate.errCode() << "." << endl;
				cout << "Please enter a future date." << endl;;
				check = -1;
			}

			if (b_dueDate - tmpDate > 30)
			{
				cout << "The return date must be earlier than 30 days away from today." << endl;
				check = -1;
			}
			else
			{
				check = 2;
			}
		}
	}
	//reads a book object for a file or the screen
	std::istream& Book::read(std::istream& is)
	{
		long long tmpISBN;
		char tmpName[41];
		int tmpShelfNo;
		int check = -1;
		if (mediaType() == SDDS_CONSOLE)
		{
			b_memID = 0;
			cout << "Book Name: ";
			while (check != 1)
			{
				is.clear();
				if (is.peek() == '\n')
				{
					is.ignore();
				}
				is.getline(tmpName, 40, '\n');
				if (is.fail() || strlen(tmpName) > 40)
				{
					cout << "Book name too long, Enter again: ";
					is.clear();
					while (is.get() != '\n');
					check = -1;
				}
				else
				{
					check = 1;
				}
			}
			cout << "ISBN: ";
			while (check != 2)
			{
				is >> tmpISBN;
				if (is.fail() || tmpISBN > 9999999999999 || tmpISBN < 1000000000000)
				{
					cout << "Invalid ISBN, Enter again : ";
					is.clear();
					while (is.get() != '\n');
					check = -1;
				}
				else
				{
					check = 2;
				}
			}
			cout << "Shelf Number: ";
			readShelfNo();
			PubRecord::name(tmpName);
			b_ISBN = tmpISBN;
		}
		if (mediaType() == SDDS_FILE)
		{
			is.getline(tmpName, 40, '\t');
			is >> tmpISBN;
			is.ignore(512, '\t');
			is >> tmpShelfNo;
			if (is.peek() != '\n')
			{
				is.ignore(512, '\t');
				is >> b_memID;
			}
			if (is.peek() != '\n')
			{
				is.ignore(512, '\t');
				is >> b_dueDate;
			}
			if (is.peek() == '\n')
			{
				is.ignore();
			};
			if (is.fail() || tmpISBN > 9999999999999 || tmpISBN < 1000000000000 || strlen(tmpName) > 40 || tmpShelfNo > 999 || tmpShelfNo < 100)
			{
			}
			else
			{
				PubRecord::name(tmpName);
				b_ISBN = tmpISBN;
				shelfNo(tmpShelfNo);
			}
		}
		return is;
	}
	//writes a book object to a file or a screen
	std::ostream& Book::write(std::ostream& os) const
	{
		if (mediaType() == SDDS_CONSOLE)
		{
			os << setfill(' ');
			os << left << setw(41) << name();
			os << b_ISBN;
			os << "  ";
			os << shelfNo();
			if (b_memID != 0)
			{
				os << " ";
				os << b_memID;
				os << "   ";
				b_dueDate.write();
			}
		}
		if (mediaType() == SDDS_FILE)
		{
			os << recID() << name() << '\t' << b_ISBN << '\t' << shelfNo() << "\t";
			if (b_memID != 0)
			{
				os << b_memID << "\t";
			}
			if (memberID() >= 10000 && memberID() <= 99999)
			{
				b_dueDate.write(os);
			}
			else
			{
				os << "0";
			}
			os << endl;
		}
		return os;
	}


}