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
#include "Magazine.h"

using namespace std;
namespace sdds
{
	//sets magazine to safe empty state
	Magazine::Magazine() : PubRecord(), m_volume(0), m_issueNo(0)
	{}
	//copy constructor 
	Magazine::Magazine(const Magazine& mag)
	{
		*this = mag;
	}
	//assignment operator
	Magazine& Magazine::operator=(const Magazine& mag)
	{
		if (this != &mag)
		{
			m_issueNo = mag.m_issueNo;
			m_volume = mag.m_volume;
			PubRecord::operator=(mag);
		}
		return *this;
	}
	
	char Magazine::recID() const
	{
		return 'M';
	}
	
	void Magazine::checkIn()
	{
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	void Magazine::checkOut()
	{
		cout << "Magazines cannot be checked in or out!" << endl;
	}
	//reads a magazine from console or file
	std::istream& Magazine::read(std::istream& is)
	{
		char tmpName[41];
		int tmpVol;
		int tmpIss;
		int tmpShelfNo;
		int check = -1;
		if (mediaType() == SDDS_CONSOLE)
		{
			cout << "Magazine Name: ";
			while (check != 1)
			{
				is.getline(tmpName, 40, '\n');
				if (is.fail() || strlen(tmpName) > 40)
				{
					cout << "Magazine name too long, Enter again: ";
					is.clear();
					while (is.get() != '\n');
					check = -1;
				}
				else
				{
					check = 1;
				}
			}
			cout << "Volume: ";
			while (check != 2)
			{
				is >> tmpVol;
				if (is.fail() || tmpVol > 99 || tmpVol < 1)
				{
					cout << "Invalid Volume number, Enter again : ";
					is.clear();
					while (is.get() != '\n');
					check = -1;
				}
				else
				{
					check = 2;
				}
			}
			cout << "Issue: ";
			while (check != 3)
			{
				is >> tmpIss;
				if (is.fail() || tmpIss > 99 || tmpIss < 1)
				{
					cout << "Invalid Issue number, Enter again: ";
					is.clear();
					while (is.get() != '\n');
					check = -1;
				}
				else
				{
					check = 3;
				}
			}
			cout << "Shelf Number: ";
			readShelfNo();
			PubRecord::name(tmpName);
			m_volume = tmpVol;
			m_issueNo = tmpIss;

		}
		if (mediaType() == SDDS_FILE)
		{
			is.getline(tmpName, 40, '\t');
			is >> tmpVol;
			is.ignore(512, '\t');
			is >> tmpIss;
			is.ignore(512, '\t');
			is >> tmpShelfNo;
			is.ignore(512, '\n');
			if (is.fail() || tmpIss > 99 || tmpIss < 1 || tmpVol > 99 || tmpVol < 1 || strlen(tmpName) > 40 || tmpShelfNo > 999 || tmpShelfNo < 100)
			{
			}
			else
			{
				PubRecord::name(tmpName);
				m_volume = tmpVol;
				m_issueNo = tmpIss;
				shelfNo(tmpShelfNo);
			}
		}
		return is;
	}
	//writes a magazine to console or file
	std::ostream& Magazine::write(std::ostream& os) const
	{
		if (mediaType() == SDDS_CONSOLE)
		{
			os << left << setw(41) << name();
			os << "       ";
			os << right << setfill('0') << setw(2) << m_volume;
			os << setfill(' ');
			os << "(";
			os << right << setfill('0') << setw(2) << m_issueNo;
			os << ")  ";
			os << setfill(' ');
			os << shelfNo();
		}
		if (mediaType() == SDDS_FILE)
		{
			os << recID() << name() << '\t' << m_volume << '\t' << m_issueNo << '\t' << shelfNo() << endl;
		}
		return os;
	}

}