///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__
#include <iostream>
#include "ReadWriteable.h"
#include "Date.h"

namespace sdds
{
	const int SDDS_CONSOLE = 512;
	const int SDDS_FILE = 128;

	class PubRecord : public ReadWriteable
	{
		char* p_pubName;
		int p_shelfNum;
		int p_media;

	protected:
		void name(const char* name); //sets name dynamiclly
		const char* name() const; //returns name
		void shelfNo(int value); //sets p_shelfNo

	public:
		PubRecord();
		PubRecord(const PubRecord& rec); //copy cons
		virtual ~PubRecord();
		PubRecord& operator=(const PubRecord&); //assignment operator
		void mediaType(int mediaT); //sets media type
		int mediaType() const; //returns mediatype
		int shelfNo() const; //returns Shelfno
		int readShelfNo(); //takes userinput of 3 digit shelf no
		bool operator==(char val)const; //compares val to recID
		bool operator==(const char* val)const; //compares val to nameofclass
		operator bool() const; //return true if !empty
		virtual void checkIn() = 0;
		virtual void checkOut() = 0;
		virtual char recID() const = 0;
	};

}
#endif