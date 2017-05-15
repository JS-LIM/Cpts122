/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA7                                                              *
* Date: 11/8/16                                                                            *
* Description: This program builds a simple computer called the Simpletron. It can         *
*			   manipulate data, read, write, store, and much more.						   *
*******************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::fstream;

class Simpletron
{
public:
	Simpletron();
	~Simpletron();

	void fetch();
	bool decodeAndExec();
	bool execute(int opcode, int operand);
	void printMenu(int action);

private:
	int mAccumulator;
	int mCur_instr;
	int *mpInst_ptr;
	int mData[10]; 
	int mCode[25];
	int mCodeSize;
	fstream mFileStream;
};