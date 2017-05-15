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

#include "BST.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::ios;

using std::cout;
using std::endl;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void OpenCloseFile();
	void readLine();
	void displayTrees();
	void printStats();
};