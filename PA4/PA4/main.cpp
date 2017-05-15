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

int main()
{
	FitnessAppWrapper::DietPlan a[7];
	FitnessAppWrapper::ExercisePlan b[7];
	fstream infile, infile2;

	displayMenu();
	int choice;
	cin >> choice;

	while (choice != 9)
	{
		system("cls");
		switch (choice)
		{
		case 1:
			infile.open("dietPlans.txt", ios::in);
			a->loadWeeklyPlan(infile, a);
			infile.close();
			displayMenu();
			cin >> choice;
			break;
		case 2:
			infile2.open("exercisePlans.txt", ios::in);
			b->loadWeeklyPlan(infile2, b);
			infile2.close();
			displayMenu();
			cin >> choice;
			break;
		case 3:
			infile.open("dietPlans.txt", ios::out);
			a->storeWeeklyPlan(infile, a);
			a->displayWeeklyPlan(a);
			infile.close();
			displayMenu();
			cin >> choice;
			break;
		case 4:
			infile2.open("exercisePlans.txt", ios::out);
			b->storeWeeklyPlan(infile, b);
			b->displayWeeklyPlan(b);
			infile2.close();
			displayMenu();
			cin >> choice;
			break;
		case 5:
			if (a[0].getDate() == "")
			{
				cout << "Data is empty. Load file" << endl;
				displayMenu();
				cin >> choice;
				break;
			}
			cout << a;
			displayMenu();
			cin >> choice;
			break;
		case 6:
			if (b[0].getDate() == "")
			{
				cout << "Data is empty. Load file" << endl;
				displayMenu();
				cin >> choice;
				break;
			}
			cout << b;
			displayMenu();
			cin >> choice;
			break;
		case 7:
			if (a[0].getDate() == "")
			{
				cout << "Data is empty. Load file" << endl;
				displayMenu();
				cin >> choice;
				break;
			}
			a->editWeeklyPlan(a);
			cout << "Edited:" << endl;
			a->displayWeeklyPlan(a);
			displayMenu();
			cin >> choice;
			break;
		case 8:
			if (b[0].getDate() == "")
			{
				cout << "Data is empty. Load file" << endl;
				displayMenu();
				cin >> choice;
				break;
			}
			b->editWeeklyPlan(b);
			cout << "Edited:" << endl;
			b->displayWeeklyPlan(b);
			displayMenu();
			cin >> choice;
			break;
		}
	}

	if (a[0].getDate() != "")
	{
		infile.open("dietPlans.txt", ios::out);
		a->writeWeeklyPlan(infile, a);
		infile.close();
	}

	if (b[0].getDate() != "")
	{
		infile2.open("exercisePlans.txt", ios::out);
		b->writeWeeklyPlan(infile2, b);
		infile2.close();
	}

	return 0;
}