///////////////////////////////////////
//       NAME: Skye Bragg            //
//	    EMAIL: sbragg@myseneca.ca    //
//  STUDENT #: 107842171             //
///////////////////////////////////////
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds
{
	const int MAX_MENU_ITEMS = 20u;

	class Menu;

	class MenuItem
	{
		friend class Menu;
	private:
		char* desc;

		MenuItem();
		MenuItem(const char* desc1);
		virtual ~MenuItem();

		MenuItem operator=(MenuItem&) = delete;  //copy constructor, unusable
		MenuItem(MenuItem&) = delete;			 //assignemnt operator, unusable
		operator bool() const;					 //returns true if desc is empty
		operator const char*() const;			 //returns description
		std::ostream& display(std::ostream& os = std::cout); //displays discription to screen
	};

	class Menu
	{
		MenuItem title;
		MenuItem *items[MAX_MENU_ITEMS];
		int count;

	public:
		Menu(const char* title1 = '\0');		//sets to safe empty state with title default to null

		unsigned int getSelection();			//validates user selection
		unsigned int operator~();				//returns selection
		operator unsigned int() const;			//returns count value
		operator bool() const;					//returns true if count has value greater than 0
		const char* operator[](int index) const;//loops back to menuitem 1 if selection is greater than menu items
		Menu& operator<<(const char* desc);		//adds menu item to menu
		std::ostream& displayTitle(std::ostream& os);	//displays the title of menu
		std::ostream& displayMenu(std::ostream& os);	//displays menu items
	};
	std::ostream& operator<<(std::ostream& os, Menu& m); //prints menu title
}
#endif