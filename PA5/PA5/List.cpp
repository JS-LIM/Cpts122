/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA5                                                              *
* Date: 10/20/16                                                                           *
* Description: This program keeps track of absences for students in a classroom            *
*******************************************************************************************/

#include "List.h"

List::List()
{
	mpHead = nullptr;
}

List::List(const List &copyList)
{
	this->mpHead = nullptr;

	Node *pPrev = nullptr;
	Node *temp_to = this->getHeadPtr();
	Node *temp_from = copyList.getHeadPtr();

	while (temp_from != nullptr)
	{
		temp_to = new Node(*temp_from);
		if (pPrev != nullptr)
		{
			pPrev->setNextPtr(temp_to);
		}

		temp_from = temp_from->getNextPtr();
		pPrev = temp_to;
		temp_to = temp_to->getNextPtr();
	}
}

List::~List()            
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

List & List::operator= (const List &rhs)
{
	return (*this);
}

Node * List::getHeadPtr() const
{
	return mpHead;
}

void List::setHeadPtr(Node * const pNewHead)
{
	mpHead = pNewHead;
}

bool List::insertAtFront(const int newData, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newAbsences, string newDates[])
{
	Node *pMem = makeNode(newData, newID, newName, newEmail, newUnits, newProgram, newLevel, newAbsences, newDates);
	bool success = false;            

	if (pMem != nullptr)
	{
		success = true;
				
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

bool List::isEmpty()
{
	return (mpHead == nullptr);
}

Node * List::makeNode(const int newData, const int newID, const string newName, const string newEmail, const string newUnits, const string newProgram, const string newLevel, const int newAbsences, string newDates[])
{
	Node *pMem = new Node(newData, newID, newName, newEmail, newUnits, newProgram, newLevel, newAbsences, newDates);

	return pMem;
}

void List::destroyListHelper(Node * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;   
	}
}

void List::destroyList()
{
	destroyListHelper(mpHead);
}

void List::printNameID()
{
	Node *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getID() << pCur->getName() << endl;

		pCur = pCur->getNextPtr();
	}
}