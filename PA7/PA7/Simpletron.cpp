/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA7                                                              *
* Date: 11/8/16                                                                            *
* Description: This program builds a simple computer called the Simpletron. It can         *
*			   manipulate data, read, write, store, and much more.						   *
*******************************************************************************************/

#include "Simpletron.h"

Simpletron::Simpletron()
{
	mFileStream.open("SML.txt", ios::in);

	mAccumulator = 0;
	mpInst_ptr = mCode;

	int location = 0, instruction;

	while (!mFileStream.eof())
	{
		mFileStream >> instruction;

		mCode[location] = instruction;
		mData[location] = 0;

		location++;
	}

	mCodeSize = location;

	

	if (mFileStream.is_open())
	{
		mFileStream.close();
	}
}

Simpletron::~Simpletron()
{
	//Inside Destructor
}

void Simpletron::fetch()
{
	mCur_instr = *mpInst_ptr;
	mpInst_ptr++;
}

bool Simpletron::decodeAndExec()
{
	int opcode = mCur_instr / 1000;
	int operand = mCur_instr % 1000;
	return execute(opcode, operand);
}

bool Simpletron::execute(int opcode, int operand)
{
	cout << "opcode: " << opcode << endl;
	cout << "operand: " << operand << endl;

	int tmp;

	switch (opcode)
	{
	case 10: 
		cout << "Read" << endl << "Enter a number: ";
		cin >> tmp;
		mData[operand - 1] = tmp;
		break;
	case 11:
		cout << "Write" << endl;
		cout << "Enter a number: ";
		cin >> tmp;
		mAccumulator = tmp;
		break;
	case 20:
		cout << "Load" << endl;
		mData[operand - 1] = mAccumulator;
		break;
	case 21:
		cout << "Store" << endl;
		mAccumulator = mData[operand - 1];
		break;
	case 30:
		cout << "Add" << endl;
		mAccumulator += mData[operand - 1];
		break;
	case 31:
		cout << "Subtract" << endl;
		mAccumulator -= mData[operand - 1];
		break;
	case 32:
		cout << "Divide" << endl;
		mAccumulator /= mData[operand - 1];
		break;
	case 33:
		cout << "Multiply" << endl;
		mAccumulator *= mData[operand - 1];
		break;
	case 34:
		cout << "Modulus" << endl;
		mAccumulator %= mData[operand - 1];
		break;
	case 35:
		tmp = mAccumulator;
		cout << "Exponentiation" << endl;
		mAccumulator = pow(tmp, mData[operand - 1]);
		break;
	case 36:
		cout << "Branch" << endl;
		break;
	case 37:
		cout << "BranchNeg" << endl;
		break;
	case 38:
		cout << "BranchZero" << endl;
		break;
	case 43:
		cout << "Halting" << endl;
		return false;
	case 0: 
		cout << "Print: " << mData[operand - 1] << endl;
		break;
	}

	return true;
}

void Simpletron::printMenu(int action)
{
	int i = 0, j;

	cout << "Welcome to Simpletron" << endl << endl;
	
	cout << "Action: " << mCode[action] << endl;

	cout << "Actions in queue: ";
	for (i = action + 1; i < mCodeSize; i++)
	{
		cout << mCode[i] << " ";
	}
	cout << endl << endl;

	cout << "Store: " << mAccumulator << endl;

	cout << "Data" << endl;

	for (j = 0; j < 10; j++)
	{
		cout << "[ " << mData[j] << " ] " << " ";
	}
	cout << endl << endl;
}