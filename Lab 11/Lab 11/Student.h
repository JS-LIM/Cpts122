#pragma once

#include "Person.h"

class Student : public Person
{
public:
	Student();
	~Student();

	int getCoursesTaken();
	int getTotalCredits();

	void setCoursesTaken(int newData);
	void setTotalCredits(int newData);

private:
	//Course *mCourse;
	int mCoursesTaken;
	int mTotalCredits;
};

typedef struct course
{
	string CourseName;
	int Credits;
	char Grade[2];
} Course;

