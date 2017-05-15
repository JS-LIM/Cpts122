#pragma once

// Added the Stack template 10/24

#include "ListTemplate.h"

template <class T>
class Stack
{
public:
	// setting the mStack varable by using the constructor
	// for the List
	Stack(int newSize = 1) : mStack(newSize) {}; 

	bool push(T &newData);
	void printStack();

private:
	List<T> mStack;

};

// we are pushing data to the end of the array, because
// it allows for constant inserts and deletes
template <class T>
bool Stack<T>::push(T &newData)
{
	int size = this->mStack.getEnd();
	mStack.insertPosN(size, newData);
	//this->mStack.setEnd(++size);

	return true;
}

template <class T>
void Stack<T>::printStack()
{
	int index = this->mStack.getEnd() - 1;
	while (index >= 0)
	{
		this->mStack.printItem(index);
		--index;
	}
}