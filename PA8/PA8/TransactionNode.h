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

#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(const int &newData = 0, const string &Data = "", Node *newRight = nullptr, Node *newLeft = nullptr);
	~TransactionNode();

	void setUnits(int newData);

	int getUnits();

	void printData();

private:
	int mUnits;
};