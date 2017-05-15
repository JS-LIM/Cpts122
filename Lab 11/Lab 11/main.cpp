#include "Person.h"
#include "TestPerson.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
	Person p;
	TestPerson tp;
	Student s;
	Teacher t;

	cout << p.getGender() << endl;
	cout << tp.getGender() << endl;
	cout << s.getGender() << endl;
	cout << t.getGender() << endl;

	tp.testNamePerson();


	return 0;
}