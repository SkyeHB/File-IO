///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;
namespace sdds
{
	Menu::Menu(const char* title1) : title(title1)
	{
		count = 0;
		items[0] = nullptr;
	}

	unsigned int Menu::getSelection()
	{
		size_t select = 256;
		displayMenu(cout);
		while (select == 256)
		{
			cin >> select;
			if (cin.fail() || select < 0 || select > operator unsigned int())
			{
				cin.clear();
				cout << "Invalid Selection, try again: ";
				select = 256;
			}
			cin.ignore(256, '\n');
			if (select >= 0 && select <= operator unsigned int())
			{
				return select;
			}
		}
		return 0;
	}

	unsigned int Menu::operator~()
	{
		return getSelection();
	}

	Menu::operator unsigned int() const
	{
		return count;
	}

	Menu::operator bool() const
	{
		if (count >= 1)
		{
			return true;
		}
		return false;
	}

	ostream& Menu::displayTitle(ostream& os)
	{
		if (title != nullptr)
		{
			os << Menu::title.operator const char* ();
			return os;
		}
		return os;
	}

	std::ostream& Menu::displayMenu(std::ostream& os)
	{
		if (title.operator bool() == true) {
			displayTitle(os);
			os << ":" << endl;
		}
		for (int i = 0; i < count; i++)
		{
			os << " " << i + 1 << "- ";
			items[i]->display(os);
			os << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	Menu& Menu::operator<<(const char* desc)
	{
		if (operator unsigned int() < MAX_MENU_ITEMS)
		{
			MenuItem* tmp;
			tmp = new MenuItem(desc);
			items[operator unsigned int()] = tmp;
			tmp = nullptr;
			count++;
		}
		else
		{
		}
		return *this;
	}

	const char* Menu::operator[](int index) const
	{
		if (index < Menu::count)
		{
			return items[index]->operator const char* ();
		}
		else
		{
			return items[0]->operator const char* (); //this might need to loop instead
		}
	}

	std::ostream& operator<<(std::ostream& os, Menu& m)
	{
		m.displayTitle(os);
		return os;
	}

	MenuItem::MenuItem() : desc(nullptr)
	{}

	MenuItem::MenuItem(const char* desc1)
	{
		if (desc1 != nullptr)
		{
			desc = new char[strlen(desc1) + 1];
			strcpy(desc, desc1);
		}
		else
		{
			desc = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] desc;
	}

	MenuItem::operator bool() const
	{
		if (desc != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	MenuItem::operator const char* () const
	{
		return desc;
	}

	ostream& MenuItem::display(ostream& os)
	{
		os << desc;
		return os;
	}
}
