// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 11/4 - Worked on the Manager class. Manager class is
//                 derived from Employee class. A Manager object
//                 is-a(n) Employee object, but not the other way
//                 around!

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

int main(void)
{
	Employee e;
	Manager m;

	e.setHours(10);
	m.setHours(100);

	cout << "Rate " << e.calculatePay() << endl;
	cout << "Rate " << m.calculatePay() << endl;


	return 0;
}