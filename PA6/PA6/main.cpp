/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA6                                                              *
* Date: 10/26/16                                                                           *
* Description: This program uses a tree data structure to organize a Morse table and       *
*			   convert the data from Convert.txt into Morse.                               *
*******************************************************************************************/

#include "BST.h"

int main()
{
	BST a;
	BST b(a);
	//copy constructor modifies a, not b!!

	a.print();
	a.readConvertFile();

	return 0;
}