/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA5                                                              *
* Date: 10/20/16                                                                           *
* Description: This program keeps track of absences for students in a classroom            *
*******************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <time.h>

#include "Node.h"
#include "List.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::to_string;

class Menu
{
public:
	Menu();
	~Menu();

	void runApp(void);
	void displayMenu();
	int enterChoice();
	string displayDate();
	void markAbsences(List &master);
	int displayReport();
	void write_all(List &master);
	void write_x(List &master);
	void write_date(List &master);
	void editAbsences(List &master);

private:
	ifstream mInputStream;  
	ifstream mInputStream1;
	ofstream mOutputStream; 
	ofstream mOutputStream1;
	ofstream mOutputStream2;
	ofstream mOutputStream3;
	List mList; 
};

ifstream & operator >> (ifstream &input, List &rhs);
ofstream & operator << (ofstream &output, List &rhs);