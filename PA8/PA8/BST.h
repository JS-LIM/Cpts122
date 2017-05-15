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
#include "TransactionNode.h"
#include <iostream>

using std::cout;
using std::endl;

class BST
{
public:
	BST();
	~BST();

	void setRoot(Node *newData);

	Node *& getRoot();
	
	void insert(int &newData, string &newData1);
	void inOrderTraversal();
	
	TransactionNode & findSmallest(Node *pTree);
	TransactionNode & findLargest(Node *pTree);

private:
	Node *mpRoot;

	void destroyTree(Node *pTree);
	void insert(Node *& pTree, int &newData, string &newData1);
	void inOrderTraversal(Node *pTree);
};