/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA5                                                              *
* Date: 10/20/16                                                                           *
* Description: This program keeps track of absences for students in a classroom            *
*******************************************************************************************/

#include "Node.h"

Node::Node(int newData, int newID, string newName, string newEmail, string newUnits, string newProgram, string newLevel, int newAbsences, string newDates[])
{
	this->mData = newData;
	this->mID = newID;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnits;
	this->mProgram = newProgram;
	this->mLevel = newLevel;
	this->mAbsences = newAbsences;
	for (int i = 0; i < 365; i++)
	{
		this->mDates[i] = newDates[i];
	}

	mpNext = nullptr;
}

Node::Node(const Node &copy)
{
	mData = copy.mData;
	this->mID = copy.mID;
	this->mName = copy.mName;
	this->mEmail = copy.mEmail;
	this->mUnits = copy.mUnits;
	this->mProgram = copy.mProgram;
	this->mLevel = copy.mLevel;
	this->mAbsences = copy.mAbsences;
	for (int i = 0; i < 365; i++)
	{
		this->mDates[i] = copy.mDates[i];
	}
	mpNext = copy.mpNext;
}

Node::~Node()
{
	cout << "Inside ListNode's destructor!" << endl;
}

int Node::getData() const
{
	return mData;
}

int Node::getID() const
{
	return this->mID;
}

string Node::getName() const
{
	return this->mName;
}

string Node::getEmail() const
{
	return this->mEmail;
}

string Node::getUnits() const
{
	return this->mUnits;
}

string Node::getProgram() const
{
	return this->mProgram;
}

string Node::getLevel() const
{
	return this->mLevel;
}

int Node::getAbsences() const
{
	return this->mAbsences;
}

string Node::getDates(int i) 
{
	return this->mDates[i];
}

Node * Node::getNextPtr() const
{
	return mpNext;
}

void Node::setData(const int newData)
{
	mData = newData;
}

void Node::setID(const int newData)
{
	this->mID = newData;
}

void Node::setName(const string newData)
{
	this->mName = newData;
}

void Node::setEmail(const string newData)
{
	this->mEmail = newData;
}

void Node::setUnits(const string newData)
{
	this->mUnits = newData;
}

void Node::setProgram(const string newData)
{
	this->mProgram = newData;
}

void Node::setLevel(const string newData)
{
	this->mLevel = newData;
}

void Node::setAbsences(const int newData)
{
	this->mAbsences = newData;
}

void Node::setDates(string newData[])
{
	for (int i = 0; i < 365; i++)
	{
		this->mDates[i] = newData[i];
	}
}

void Node::setNextPtr(Node * const pNewNext)
{
	mpNext = pNewNext;
}