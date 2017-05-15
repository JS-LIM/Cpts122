/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA8                                                              *
* Date: 11/15/16                                                                           *
* Description: This Program takes data from a csv file and places them in order in two     *
*			   different trees based off of the third data value. Then it returns stats    *
*			   based off of the minimum and maximum values.								   *
*******************************************************************************************/

#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Node
{
public:
	Node(const string &newData, Node *newLeft = nullptr, Node *newRight = nullptr);
	~Node();
	
	void setData(string newData);
	void setLeft(Node *newData);
	void setRight(Node *newData);

	string getData();
	Node *& getLeft();
	Node *& getRight();

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};