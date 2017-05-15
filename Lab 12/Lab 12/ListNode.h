#pragma once

#include "List.h"

template <class NODETYPE> class List; 
template <class NODETYPE> class ListNode
{
	friend class List<NODETYPE>; 

public:
	ListNode(const NODETYPE &newData);  
	NODETYPE getData() const;     
	ListNode <NODETYPE> *getNextPtr() const;

	void setNextPtr(ListNode <NODETYPE> *tempPtr);

private:
	NODETYPE data;                
	ListNode <NODETYPE> *nextPtr; 
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &newData)
{
	this->data = newData;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const
{
	return this->data;
}

template <class NODETYPE>
ListNode<NODETYPE> * ListNode<NODETYPE>::getNextPtr() const
{
	return this->nextPtr;
}

template <class NODETYPE>
void ListNode<NODETYPE>::setNextPtr(ListNode <NODETYPE> *tempPtr)
{
	this->nextPtr = tempPtr;
}
