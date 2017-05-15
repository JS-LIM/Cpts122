#include "Manager.h"

Manager::Manager(const string &newName, const double &newPayRate, const double &newHours, 
	const bool &newSalariedEmployee) : Employee (newName, newPayRate, newHours)
{
	this->mIsASalaried = newSalariedEmployee;
}

Manager::~Manager()
{

}

bool Manager::getIsSalaried()
{
	return this->mIsASalaried;
}
void Manager::setIsSalaried(bool newIsSalaried)
{
	this->mIsASalaried = newIsSalaried;
}

double Manager::calculatePay()
{
	double pay = 0.0;

	if (this->mIsASalaried) // true = salaried employee
	{
		// mPayRate stays the same = is the pay rate for period
		pay = this->getPayRate();
	}
	else // hourly employee
	{
		pay = Employee::calculatePay();
	}

	return pay;
}