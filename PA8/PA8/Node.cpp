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

#include "Node.h"

Node::Node(const string &newData, Node *newLeft, Node *newRight)
{
	this->mData = newData;
	this->mpLeft = newLeft;
	this->mpRight = newRight;
}

Node::~Node()
{
	//Inside Destructor
}

void Node::setData(string newData)
{
	this->mData = newData;
}

void Node::setLeft(Node *newData)
{
	this->mpLeft = newData;
}

void Node::setRight(Node *newData)
{
	this->mpRight = newData;
}

string Node::getData()
{
	return this->mData;
}

Node *& Node::getLeft()
{
	return this->mpLeft;
}

Node *& Node::getRight()
{
	return this->mpRight;
}

void Node::printData()
{
	cout << getData() << endl;
}