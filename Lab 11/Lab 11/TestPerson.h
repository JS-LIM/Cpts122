#pragma once

#include "Person.h"

class TestPerson : public Person
{
public:
	TestPerson();
	~TestPerson();

	void testNamePerson();
	void testAgePerson();
	void testGenderPerson();
	void testHeightPerson();
};