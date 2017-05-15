/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA5                                                              *
* Date: 10/20/16                                                                           *
* Description: This program keeps track of absences for students in a classroom            *
*******************************************************************************************/

#pragma once

#include <iostream>

#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::fstream;

class List
{
public:
	List();                     
	List(const List &copyList); 							
	~List();                    

	List & operator= (const List &rhs); 

	Node * getHeadPtr() const;
	void setHeadPtr(Node * const pNewHead);

	bool insertAtFront(const int newData, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newAbsences, string newDates[]);
	bool isEmpty();                           
	void printNameID();

private:
	Node *mpHead;

	Node * makeNode(const int newData, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newAbsences, string newDates[]);
	void destroyList();                        
	void destroyListHelper(Node * const pMem);
};