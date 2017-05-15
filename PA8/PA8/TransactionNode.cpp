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
#include "TransactionNode.h"

TransactionNode::TransactionNode(const int &newData, const string &Data, Node *newRight, Node *newLeft) : Node(Data, newLeft, newRight)
{
	this->mUnits = newData;
	this->mData = Data;
}

TransactionNode::~TransactionNode()
{
	//Inside Destructor
}

void TransactionNode::setUnits(int newData)
{
	this->mUnits = newData;
}

int TransactionNode::getUnits()
{
	return this->mUnits;
}

void TransactionNode::printData()
{
	cout << "Units: " << getUnits() << " Type: " << getData() << endl;
}