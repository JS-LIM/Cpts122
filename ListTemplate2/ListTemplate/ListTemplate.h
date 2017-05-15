#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class T>
class List
{
	public:
//		List(int newMaxSize = 0) : mCurNum(0), mMaxSize(newMaxSize);
		List(int newMaxSize = 1);

		~List();

		int getEnd() const;
		void setEnd(int newEnd);

		bool insertPosN(int pos, T &newData);
		void printItem(int pos);

	private:
		T *mpList; // this will be a dynamic array
		int mMaxSize;
		int end; // actual number of nodes in array
		int front; // should be set to 0

};

template <class T>
List<T>::List(int newMaxSize)
{
	if (newMaxSize > 0) // validate 
	{
		this->mpList = new T[newMaxSize];
		this->mMaxSize = newMaxSize;
	}
	else
	{
		this->mpList = new T[1];
		this->mMaxSize = 1;
	}

	this->end = this->front = 0;

}

template <class T>
List<T>::~List()
{
	delete[] this->mpList;
}

template <class T>
int List<T>::getEnd() const
{
	return this->end;
}

template <class T>
void List<T>::setEnd(int newEnd)
{
	this->end = newEnd;
}

template <class T>
bool List<T>::insertPosN(int pos, T &newData)
{
	bool success = false;
	if ((pos <= this->end) && (this->end < this->mMaxSize)) // valid range for inserting
	{
		success = true;
		int index = end - 1;
		while (index >= pos)
		{
			this->mpList[index + 1] = this->mpList[index];
			--index;
		}
		this->mpList[pos] = newData;
		(this->end)++;
	}

	// write shift code later
	this->mpList[pos] = newData;

	return success;
}

template <class T>
void List<T>::printItem(int pos)
{
	cout << this->mpList[pos] << endl;
}