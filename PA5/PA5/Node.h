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
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
public:
	Node(int newData, int newID, string newName, string newEmail, string newUnits, string newProgram, string newLevel, int newAbsences, string newDates[]);
	Node(const Node &copy);
	~Node();
							  
	int getData() const; 
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getAbsences() const;
	string getDates(int i);
	Node * getNextPtr() const;

	void setData(const int newData);
	void setID(const int newData);
	void setName(const string newData);
	void setEmail(const string newData);
	void setUnits(const string newData);
	void setProgram(const string newData);
	void setLevel(const string newData);
	void setAbsences(const int newData);
	void setDates(string newData[]);
	void setNextPtr(Node * const pNewNext);

private:
	int mData;
	int mID;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	int mAbsences;
	string mDates[365];
	Node *mpNext;
};