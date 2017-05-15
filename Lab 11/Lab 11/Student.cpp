#include "Student.h"

Student::Student() 
{
	this->mCoursesTaken = 0;
	this->mTotalCredits = 0;
}

Student::~Student()
{
	//Inside Destructor
}

int Student::getCoursesTaken()
{
	return this->mCoursesTaken;
}

int Student::getTotalCredits()
{
	return this->mTotalCredits;
}

void Student::setCoursesTaken(int newData)
{
	this->mCoursesTaken = newData;
}

void Student::setTotalCredits(int newData)
{
	this->mTotalCredits = newData;
}