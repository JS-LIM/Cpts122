#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Person
{
public:
	Person();
	~Person();

	string getName();
	int getAge();
	char getGender();
	int getHeight();

	void setName(string newData);
	void setAge(int newData);
	void setGender(char newData);
	void setHeight(int newData);

protected:
	string mName;
	int mAge;
	char mGender;
	int mHeight;
};