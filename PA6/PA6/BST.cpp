/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA6                                                              *
* Date: 10/26/16                                                                           *
* Description: This program uses a tree data structure to organize a Morse table and       *
*			   convert the data from Convert.txt into Morse.                               *
*******************************************************************************************/

#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::BST(BST &copy)
{
	char temp[2] = "";
	char temp1[7] = "";

	this->mpRoot = copy.mpRoot;

	this->mInputStream.open("MorseTable.txt", ios::in);

	while (!mInputStream.eof())
	{
		mInputStream.getline(temp, 2, ' ');
		mInputStream.getline(temp1, 7);

		char English = temp[0];
		string Morse = temp1;
		copy.insert(English, Morse);
	}

	if (mInputStream.is_open())
	{
		mInputStream.close();
	}
}

BST::~BST()
{
	cout << "Inside BSTList destructor" << endl;
	this->destroyTree(this->mpRoot);
}

BSTNode * BST::getRoot()
{
	return this->mpRoot;
}

string BST::getsearchFound()
{
	return this->searchFound;
}

void BST::setRoot(BSTNode *pnewData)
{
	this->mpRoot = pnewData;
}

void BST::setsearchFound(string newData)
{
	this->searchFound = newData;
}

void BST::insert(BSTNode *& pTree, char &newData, string &newData1)
{
	if (pTree == nullptr)
	{
		pTree = new BSTNode(newData, newData1);
	}

	else if (newData > pTree->getEnglish())
	{
		insert(pTree->getRight(), newData, newData1);
	}

	else if (newData < pTree->getEnglish())
	{
		insert(pTree->getLeft(), newData, newData1);
	}

	else
	{
		cout << "Tried to insert a duplicate" << endl;
	}
}

void BST::insert(char &newData, string &newData1)
{
	insert(mpRoot, newData, newData1);
}

void BST::print(BSTNode *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		print(pTree->getLeft());
		cout << "English: " << pTree->getEnglish() << " Morse: " << pTree->getMorse() << endl;
		print(pTree->getRight());
	}
}

void BST::print()
{
	print(this->mpRoot);
}

void BST::destroyTree(BSTNode *pTree)
{
	if (pTree == nullptr)
	{
		return;
	}

	else
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

string BST::search(BSTNode *pTree, char &newData)
{
	string Morse = "";

	if (newData == pTree->getEnglish())
	{
		Morse = pTree->getMorse();
		this->setsearchFound(Morse);
	}

	else
	{
		if (newData > pTree->getEnglish())
		{
			search(pTree->getRight(), newData);
		}

		else if (newData < pTree->getEnglish())
		{
			search(pTree->getLeft(), newData);
		}
	}

	return getsearchFound();
}

string BST::search(char &newData)
{
	return search(mpRoot, newData);
}

void BST::readConvertFile(BSTNode *pTree)
{
	int i = 0;
	char tempc = '\0';
	char temp[100] = "";
	string temps = "";

	this->mInputStream1.open("Convert.txt", ios::in);

	while (!mInputStream1.eof())
	{
		for (int i = 0; i < 100; i++)
		{
			temp[i] = '\0';
		}
		mInputStream1.getline(temp, 100);

		while (temp[i] != '.' && temp[i] != '?')
		{
			tempc = temp[i];
			if (tempc != ' ')
			{
				tempc = toupper(tempc);
				temps = search(tempc);
				cout << temps << " ";
			}
			
			i++;
		}

		tempc = temp[i];
		temps = search(tempc);
		cout << temps << endl;
		
		i = 0;
	}

	if (mInputStream1.is_open())
	{
		mInputStream1.close();
	}
}

void BST::readConvertFile()
{
	this->readConvertFile(mpRoot);
}
