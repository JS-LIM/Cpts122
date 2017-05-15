/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA6                                                              *
* Date: 10/26/16                                                                           *
* Description: This program uses a tree data structure to organize a Morse table and       *
*			   convert the data from Convert.txt into Morse.                               *
*******************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>

#include "BSTNode.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class BST
{
public:
	BST();
	BST(BST &copy);
	~BST();

	BSTNode *getRoot();
	string getsearchFound();

	void setRoot(BSTNode *pnewData);
	void setsearchFound(string newData);

	void insert(char &newData, string &newData1);
	void print();
	string search(char &newData);
	void readConvertFile();

private:
	BSTNode *mpRoot;
	ifstream mInputStream;
	ifstream mInputStream1;
	string searchFound;
	
	void insert(BSTNode *& pTree, char &newData, string &newData1);
	void print(BSTNode *pTree);
	string search(BSTNode *pTree, char &newData);
	void readConvertFile(BSTNode *pTree);
	void destroyTree(BSTNode *pTree);
};