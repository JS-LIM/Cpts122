/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA6                                                              *
* Date: 10/26/16                                                                           *
* Description: This program uses a tree data structure to organize a Morse table and       *
*			   convert the data from Convert.txt into Morse.                               *
*******************************************************************************************/

#include "BSTNode.h"

BSTNode::BSTNode(char newData, string newData1)
{
	this->mEnglish = newData;
	this->mMorse = newData1;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

BSTNode::~BSTNode()
{
	//Inside destructor
}

char BSTNode::getEnglish()
{
	return this->mEnglish;
}

string BSTNode::getMorse()
{
	return this->mMorse;
}

BSTNode *& BSTNode::getLeft()
{
	return this->mpLeft;
}

BSTNode *& BSTNode::getRight()
{
	return this->mpRight;
}

void BSTNode::setEnglish(char newData)
{
	this->mEnglish = newData;
}

void BSTNode::setMorse(string newData)
{
	this->mMorse = newData;
}

void BSTNode::setLeft(BSTNode *pnewData)
{
	this->mpLeft = pnewData;
}

void BSTNode::setRight(BSTNode *pnewData)
{
	this->mpRight = pnewData;
}
