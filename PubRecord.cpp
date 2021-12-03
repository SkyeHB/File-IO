///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "PubRecord.h"

using namespace std;
namespace sdds
{
	//sets p_pubName dynammically 
	void PubRecord::name(const char* name)
	{
		if (name != nullptr)
		{
			p_pubName = new char[strlen(name)+1];
			strcpy(p_pubName, name);
		}
		else
		{
			p_pubName = nullptr;
		}
	}

	const char* PubRecord::name() const
	{
		return p_pubName;
	}
	//validates shelfNo
	void PubRecord::shelfNo(int value)
	{
		if (cin.fail() || value > 999 || value < 100)
		{
			p_shelfNum = 0;
		}
		else
		{
			p_shelfNum = value;
		}
	}
	
	PubRecord::PubRecord() : p_pubName{ nullptr }, p_shelfNum(0), p_media(0)
	{}
	//copy consturctor
	PubRecord::PubRecord(const PubRecord& rec)
	{
		*this = rec;
	}

	PubRecord::~PubRecord()
	{
		delete[] p_pubName;
	}
	//creates new dynamic memory for p_pubName after its been validated
	PubRecord& PubRecord::operator=(const PubRecord& rec)
	{
		if (this != &rec)
		{
			p_shelfNum = rec.p_shelfNum;
			p_media = rec.p_media;

			if (rec.p_pubName != nullptr)
			{
				p_pubName = new char[strlen(rec.p_pubName)+1];
				strcpy(p_pubName, rec.p_pubName);
			}
			else
			{
				p_pubName = nullptr;
			}
		}
		return *this;
	}
	
	void PubRecord::mediaType(int mediaT)
	{
		p_media = mediaT;
	}
	
	int PubRecord::mediaType() const
	{
		return p_media;
	}
	
	int PubRecord::shelfNo() const
	{
		return p_shelfNum;
	}
	//Reads the shelf number  from user input, validates it and returns it. 
	int PubRecord::readShelfNo()						
	{
		int check = -1;
		int input;
		while (check == -1)
		{
			cin >> input;
			if (cin.fail() || input > 999 || input < 100)
			{
				cout << "Invalid Shelf Number, Enter again: ";
				cin.clear();
				while (cin.get() != '\n');
				check = -1;
			}
			else
			{
				p_shelfNum = input;
				check = 1;
			}
		}
		return input;
	}
	//compares incoming value to recID, returns true if matches
	bool PubRecord::operator==(char val) const
	{
		if (recID() == val)
		{
			return true;
		}
		return false;
	}
	//compares incoming value to recID, returns true if matches one char
	bool PubRecord::operator==(const char* val) const 
	{
		char tmp[1];
		tmp[0] = recID();
		if (strstr(val,tmp) != nullptr)
		{
			return false;
		}
		return true;
	}
	//returns true if PubRecord is empty
	PubRecord::operator bool() const
	{
		if (p_pubName != nullptr && p_media != -1 && p_shelfNum != -1)
		{
			return true;
		}
		return false;
	}
}