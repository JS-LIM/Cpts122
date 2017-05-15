/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA4                                                              *
* Date: 10/7/16                                                                            *
* Description: This program stores data about diet and exercise plans. It can read in data,*
* write out data, edit data, and display data using C++.                                   *
*******************************************************************************************/

#include "Header.h"

FitnessAppWrapper::DietPlan::DietPlan()
{
	goal = 0;
	name = "";
	date = "";
}

FitnessAppWrapper::DietPlan::DietPlan(DietPlan &copy)
{
	setGoal(copy.getGoal());
	setName(copy.getName());
	setDate(copy.getDate());
}

FitnessAppWrapper::DietPlan::~DietPlan()
{
	//cout << "inside destructor for DietPlan" << endl;
}

void FitnessAppWrapper::DietPlan::setGoal(int newGoal)
{
	goal = newGoal;
}

void FitnessAppWrapper::DietPlan::setName(string newName)
{
	name = newName;
}

void FitnessAppWrapper::DietPlan::setDate(string newDate)
{
	date = newDate;
}

int FitnessAppWrapper::DietPlan::getGoal()
{
	return goal;
}

string FitnessAppWrapper::DietPlan::getName()
{
	return name;
}

string FitnessAppWrapper::DietPlan::getDate()
{
	return date;
}

FitnessAppWrapper::ExercisePlan::ExercisePlan()
{
	goal = 0;
	name = "";
	date = "";
}

FitnessAppWrapper::ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	setGoal(copy.getGoal());
	setName(copy.getName());
	setDate(copy.getDate());
}

FitnessAppWrapper::ExercisePlan::~ExercisePlan()
{
	//cout << "inside destructor for ExercisePlan" << endl;
}

void FitnessAppWrapper::ExercisePlan::setGoal(int newGoal)
{
	goal = newGoal;
}

void FitnessAppWrapper::ExercisePlan::setName(string newName)
{
	name = newName;
}

void FitnessAppWrapper::ExercisePlan::setDate(string newDate)
{
	date = newDate;
}

int FitnessAppWrapper::ExercisePlan::getGoal()
{
	return goal;
}

string FitnessAppWrapper::ExercisePlan::getName()
{
	return name;
}

string FitnessAppWrapper::ExercisePlan::getDate()
{
	return date;
}

void displayMenu()
{
	cout << "Enter in the number of your choice" << endl;

	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit. " << endl;
}

void FitnessAppWrapper::DietPlan::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	char name[100];
	fileStream.getline(name, 100);
	plan.setName(name);

	int num;
	fileStream >> num;
	plan.setGoal(num);

	fileStream.getline(name, 100);

	char date[100];
	fileStream.getline(date, 100);
	plan.setDate(date);

	fileStream.getline(date, 100);
}

void FitnessAppWrapper::DietPlan::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	fileStream >> weeklyPlan;
}

void FitnessAppWrapper::DietPlan::displayDailyPlan(DietPlan &plan)
{
	cout << plan.getName() << endl;
	cout << plan.getGoal() << endl;
	cout << plan.getDate() << endl;
	cout << endl;
}

void FitnessAppWrapper::DietPlan::displayWeeklyPlan(DietPlan weeklyPlan[])
{
	cout << weeklyPlan;
}

void FitnessAppWrapper::ExercisePlan::loadDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	char name[100];
	fileStream.getline(name, 100);
	plan.setName(name);

	int num;
	fileStream >> num;
	plan.setGoal(num);

	fileStream.getline(name, 100);

	char date[100];
	fileStream.getline(date, 100);
	plan.setDate(date);

	fileStream.getline(date, 100);
}

void FitnessAppWrapper::ExercisePlan::loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[])
{
	fileStream >> weeklyPlan;
}

void FitnessAppWrapper::ExercisePlan::displayDailyPlan(ExercisePlan &plan)
{
	cout << plan.getName() << endl;
	cout << plan.getGoal() << endl;
	cout << plan.getDate() << endl;
	cout << endl;
}

void FitnessAppWrapper::ExercisePlan::displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	cout << weeklyPlan;
}

void FitnessAppWrapper::DietPlan::storeDailyPlan(fstream &fileStream, DietPlan &plan)
{
	cout << "Enter in a name" << endl;
	string name;
	cin >> name;
	fileStream << name << endl;

	cout << "Enter in the number of calories" << endl;
	int num;
	cin >> num;
	fileStream << num << endl;

	cout << "Enter in the date" << endl;
	string date;
	cin >> date;
	fileStream << date << endl << endl;
}

void FitnessAppWrapper::DietPlan::storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	fileStream << weeklyPlan;
}

void FitnessAppWrapper::ExercisePlan::storeDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	cout << "Enter in a name" << endl;
	string name;
	cin >> name;
	fileStream << name << endl;

	cout << "Enter in the number of calories" << endl;
	int num;
	cin >> num;
	fileStream << num << endl;

	cout << "Enter in the date" << endl;
	string date;
	cin >> date;
	fileStream << date << endl << endl;
}

void FitnessAppWrapper::DietPlan::writeDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream << plan.getName() << endl;
	fileStream << plan.getGoal() << endl;
	fileStream << plan.getDate() << endl << endl;
}

void FitnessAppWrapper::ExercisePlan::writeDailyPlan(fstream &fileStream, ExercisePlan &plan)
{
	fileStream << plan.getName() << endl;
	fileStream << plan.getGoal() << endl;
	fileStream << plan.getDate() << endl << endl;
}

void FitnessAppWrapper::DietPlan::writeWeeklyPlan(fstream &fileStream, DietPlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		writeDailyPlan(fileStream, plan[i]);
	}
}

void FitnessAppWrapper::ExercisePlan::writeWeeklyPlan(fstream &fileStream, ExercisePlan plan[])
{
	for (int i = 0; i < 7; i++)
	{
		writeDailyPlan(fileStream, plan[i]);
	}
}

void FitnessAppWrapper::ExercisePlan::storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::DietPlan::editDailyPlan(DietPlan &plan)
{
	cout << "Enter in a name" << endl;
	string name;
	cin >> name;
	plan.setName(name);

	cout << "Enter in the number of calories" << endl;
	int num;
	cin >> num;
	plan.setGoal(num);

	cout << "Enter in the date" << endl;
	string date;
	cin >> date;
	plan.setDate(date);
}

void FitnessAppWrapper::ExercisePlan::editDailyPlan(ExercisePlan &plan)
{
	cout << "Enter in a name" << endl;
	string name;
	cin >> name;
	plan.setName(name);

	cout << "Enter in the number of calories" << endl;
	int num;
	cin >> num;
	plan.setGoal(num);

	cout << "Enter in the date" << endl;
	string date;
	cin >> date;
	plan.setDate(date);
}

void FitnessAppWrapper::DietPlan::editWeeklyPlan(DietPlan plan[])
{
	cout << "Which plan would you like to edit? Enter in the number of your choice" << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1) << endl;
		plan[i].displayDailyPlan(plan[i]);
	}

	int choice;
	cin >> choice;

	plan[choice - 1].editDailyPlan(plan[choice - 1]);
}

void FitnessAppWrapper::ExercisePlan::editWeeklyPlan(ExercisePlan plan[])
{
	cout << "Which plan would you like to edit? Enter in the number of your choice" << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << (i + 1) << endl;
		plan[i].displayDailyPlan(plan[i]);
	}

	int choice;
	cin >> choice;

	plan[choice - 1].editDailyPlan(plan[choice - 1]);
}

ostream & operator << (ostream &lhs, FitnessAppWrapper::DietPlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		lhs << rhs[i].getName() << endl;
		lhs << rhs[i].getGoal() << endl;
		lhs << rhs[i].getDate() << endl;
		lhs << endl;
	}

	return lhs;
}

ostream & operator << (ostream &lhs, FitnessAppWrapper::ExercisePlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		lhs << rhs[i].getName() << endl;
		lhs << rhs[i].getGoal() << endl;
		lhs << rhs[i].getDate() << endl;
		lhs << endl;
	}

	return lhs;
}

fstream & operator >> (fstream &lhs, FitnessAppWrapper::DietPlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		rhs[i].loadDailyPlan(lhs, rhs[i]);
	}

	return lhs;
}

fstream & operator >> (fstream &lhs, FitnessAppWrapper::ExercisePlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		rhs[i].loadDailyPlan(lhs, rhs[i]);
	}

	return lhs;
}

fstream & operator << (fstream &lhs, FitnessAppWrapper::DietPlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		rhs[i].storeDailyPlan(lhs, rhs[i]);
	}

	return lhs;
}

fstream & operator << (fstream &lhs, FitnessAppWrapper::ExercisePlan rhs[])
{
	for (int i = 0; i < 7; i++)
	{
		rhs[i].storeDailyPlan(lhs, rhs[i]);
	}

	return lhs;
}

