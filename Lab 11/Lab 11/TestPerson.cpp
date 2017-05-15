#include "TestPerson.h"

TestPerson::TestPerson() 
{

}

TestPerson::~TestPerson()
{
	//Inside Destructor
}

void TestPerson::testNamePerson()
{
	if (mName == "")
		cout << "Name tests true" << endl;

	else
		cout << "Name tests false" << endl;
}

void TestPerson::testAgePerson()
{
	if (this->getAge() == 0)
		cout << "Age tests true" << endl;

	else
		cout << "Age tests false" << endl;
}

void TestPerson::testGenderPerson()
{
	if (this->getGender() == '/0')
		cout << "Gender tests true" << endl;

	else
		cout << "Gender tests false" << endl;
}

void TestPerson::testHeightPerson()
{
	if (this->getHeight() == 0)
		cout << "Height tests true" << endl;

	else
		cout << "Height tests false" << endl;
}