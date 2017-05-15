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
#include <string>

using std::string;

class BSTNode
{
	friend class BST;

public: 
	BSTNode(char newData, string newData1);
	~BSTNode();

	char getEnglish();
	string getMorse();
	
	void setEnglish(char newData);
	void setMorse(string newData);
	void setLeft(BSTNode *pnewData);
	void setRight(BSTNode *pnewData);

private:
	char mEnglish;
	string mMorse;
	BSTNode *mpLeft;
	BSTNode *mpRight;

	BSTNode *& getLeft();
	BSTNode *& getRight();
};