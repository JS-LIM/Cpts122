/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA7                                                              *
* Date: 11/8/16                                                                            *
* Description: This program builds a simple computer called the Simpletron. It can         *
*			   manipulate data, read, write, store, and much more.						   *
*******************************************************************************************/

#include "Simpletron.h"

int main()
{
	Simpletron s;
	bool keep_going = true;
	int action = 0;

	while (keep_going)
	{
		s.printMenu(action);

		s.fetch();
		keep_going = s.decodeAndExec();

		action++;

		system("pause");
		system("cls");
	}

	return 0;
}