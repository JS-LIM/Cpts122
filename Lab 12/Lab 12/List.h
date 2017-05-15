#pragma once

#include "ListNode.h"
#include <iostream>

using std::cout;
using std::endl;

template <class NODETYPE> class ListNode;
template <class NODETYPE> class List
{
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE &newData);
	void insertAtBack(const NODETYPE &newData);
	//bool removeFromFront(NODETYPE &removedData);
	//bool removeFromBack(NODETYPE &removedData);
	bool isEmpty() const;
	void print() const;

	void setFirstPtr(ListNode <NODETYPE> *tempPtr);
	void setLastPtr(ListNode <NODETYPE> *tempPtr);

private:
	ListNode <NODETYPE> *firstPtr;  // pointer to first node
	ListNode <NODETYPE> *lastPtr;   // pointer to last node

	// Utility function to allocate a new node
	//ListNode <NODETYPE> *getNewNode(const NODETYPE &newData);
};

template <class NODETYPE>
List<NODETYPE>::List()
{
	this->firstPtr = nullptr;
	this->lastPtr = nullptr;
}

template <class NODETYPE>
List<NODETYPE>::~List()
{
	//Inside destructor
}

template <class NODETYPE>
void List<NODETYPE>::setFirstPtr(ListNode <NODETYPE> *tempPtr)
{
	this->firstPtr = tempPtr;
}

template <class NODETYPE>
void List<NODETYPE>::setLastPtr(ListNode <NODETYPE> *tempPtr)
{
	this->lastPtr = tempPtr;
}

template <class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &newData)
{
	ListNode<NODETYPE> *pMem = new ListNode<NODETYPE>(newData);
	ListNode<NODETYPE> *pCur = nullptr;

	if (pMem != nullptr)
	{
		pMem->setNextPtr(firstPtr);
		firstPtr = pMem;

		pCur = firstPtr;
		while (pCur->getNextPtr() != nullptr)
		{
			pCur = pCur->getNextPtr();
		}

		lastPtr = pCur;
	}
}

template <class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &newData)
{
	//ListNode<NODETYPE> *pMem = new ListNode<NODETYPE>(newData);
	//ListNode<NODETYPE> *pCur = nullptr;

	//if (pMem != nullptr)
	//{
	//	cout << "lastPtr: " << lastPtr->getData() << endl;
	//	pCur = lastPtr;
	//	//pCur->getNextPtr() = pMem;
	//	cout << "pMem: " << pMem->getData() << endl;
	//	lastPtr = pMem;
	//	cout << "lastPtr: " << lastPtr->getData() << endl;
	//}
}

template <class NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
	return (firstPtr == nullptr);
}

template <class NODETYPE>
void List<NODETYPE>::print() const
{
	ListNode<NODETYPE> *pCur = firstPtr;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;

		pCur = pCur->getNextPtr();
	}
}