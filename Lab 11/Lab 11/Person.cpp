#include "Person.h"

Person::Person()
{
	this->mAge = 0;
	this->mGender = '/0';
	this->mHeight = 0;
	this->mName = "";
}

Person::~Person()
{
	//Inside destructor
}

string Person::getName()
{
	return this->mName;
}

int Person::getAge()
{
	return this->mAge;
}

char Person::getGender()
{
	return this->mGender;
}

int Person::getHeight()
{
	return this->mHeight;
}

void Person::setName(string newData)
{
	this->mName = newData;
}

void Person::setAge(int newData)
{
	this->mAge = newData;
}

void Person::setGender(char newData)
{
	this->mGender = newData;
}

void Person::setHeight(int newData)
{
	this->mHeight = newData;
}

