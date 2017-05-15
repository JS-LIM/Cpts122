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

#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	//Inside Constructor
}

DataAnalysis::~DataAnalysis()
{
	//Inside Destructor
}

void DataAnalysis::runAnalysis()
{
	displayTrees();
}

void DataAnalysis::OpenCloseFile()
{
	if (mCsvStream.is_open())
		mCsvStream.close();

	else
		mCsvStream.open("data.csv", ios::in);
}

void DataAnalysis::readLine()
{
	int units;
	char line[100] = "", type[100];
	string sType = "";

	mCsvStream.getline(line, 100, ',');
	units = atoi(line);

	mCsvStream.getline(type, 100, ',');
	sType = type;

	mCsvStream.getline(line, 100);

	if (strcmp(line, "Purchased") == 0)
	{
		mTreePurchased.insert(units, sType);
	}

	else
	{
		mTreeSold.insert(units, sType);
	}
}

void DataAnalysis::displayTrees()
{
	char line[100] = "";

	OpenCloseFile();

	mCsvStream.getline(line, 100);
	while (!mCsvStream.eof())
	{
		readLine();
	}

	mTreePurchased.inOrderTraversal();
	cout << endl;
	mTreeSold.inOrderTraversal();
	cout << endl;

	printStats();

	OpenCloseFile();
}

void DataAnalysis::printStats()
{
	cout << "Smallest Purchased: ";
	mTreePurchased.findSmallest(mTreePurchased.getRoot());

	cout << "Largest Purchased: ";
	mTreePurchased.findLargest(mTreePurchased.getRoot());
	cout << endl;

	cout << "Smallest Sold: ";
	mTreeSold.findSmallest(mTreeSold.getRoot());

	cout << "Largest Sold: ";
	mTreeSold.findLargest(mTreeSold.getRoot());
	cout << endl;
}