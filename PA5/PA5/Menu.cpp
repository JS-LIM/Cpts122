/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA5                                                              *
* Date: 10/20/16                                                                           *
* Description: This program keeps track of absences for students in a classroom            *
*******************************************************************************************/

#include "Menu.h"

Menu::Menu()
{
	mInputStream.open("ExamScores.csv", ios::in);
}

Menu::~Menu()
{
	cout << "Inside ListApp's destructor! Closing open files!" << endl;

	if (mInputStream.is_open())
	{
		mInputStream.close();
	}
}

void Menu::displayMenu()
{
	cout << "Welcome to the Attendance Tracker" << endl << "What would you like to do? Enter in the decision of your choice" << endl;
	cout << "1. Import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl;
}

int Menu::enterChoice()
{
	int choice = 0;

	do
	{
		cout << "Enter in a valid choice" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 7);
	system("cls");

	return choice;
}

void Menu::runApp(void)
{
	Node *pMem;
	pMem = mList.getHeadPtr();

	displayMenu();
	int choice = 0, report = 0, check = 0;
	choice = enterChoice();

	do
	{
		switch (choice)
		{
		case 1:
			if (check == 2)
			{
				cout << "File has already been loaded" << endl;
				break;
			}
			
			if (mInputStream.is_open())
			{
				mInputStream >> mList;
				cout << "File loaded successfully" << endl;
				check = 1;
			}

			else
				cout << "Loading file failed" << endl;
			break;
		case 2:
			mInputStream1.open("Master.txt", ios::in);
			if (mInputStream1.is_open())
			{
				if (check == 1)
				{
					cout << "File has already been loaded" << endl;
					break;
				}

				mInputStream1 >> mList;
				if (mList.getHeadPtr() == nullptr)
				{
					cout << "Load Data first. No data has been entered" << endl;
					check = 0;
					break;
				}

				cout << "File loaded successfully" << endl;
				check = 2;
				mInputStream1.close();
			}

			else
				cout << "Loading file failed" << endl;
			break;
		case 3:
			mOutputStream.open("Master.txt", ios::out);

			if (mList.getHeadPtr() == nullptr)
			{
				cout << "Load Data first. No data has been entered" << endl;
				break;
			} 

			if (mOutputStream.is_open())
			{
				mOutputStream << mList;
				cout << "Data stored successfully" << endl;
				mOutputStream.close();
			}
			break;
		case 4:
			if (mList.getHeadPtr() == nullptr)
			{
				cout << "Load Data first. No data has been entered" << endl;
				break;
			}
			markAbsences(mList);
			break;
		case 5:
			if (mList.getHeadPtr() == nullptr)
			{
				cout << "Load Data first. No data has been entered" << endl;
				break;
			}
			editAbsences(mList);
			break;
		case 6:
			if (mList.getHeadPtr() == nullptr)
			{
				cout << "Load Data first. No data has been entered" << endl;
				break;
			}
			report = displayReport();

			if (report == 1)
			{
				mOutputStream1.open("all_report.txt", ios::out);
				if (mOutputStream1.is_open())
				{
					write_all(mList);
					cout << "File loaded successfully" << endl;
					mOutputStream1.close();
				}
			}

			else if (report == 2)
			{
				mOutputStream2.open("x_report.txt", ios::out);
				if (mOutputStream2.is_open())
				{
					write_x(mList);
					cout << "File loaded successfully" << endl;
					mOutputStream2.close();
				}
			}

			else if (report == 3)
			{
				mOutputStream3.open("date_report.txt", ios::out);
				if (mOutputStream3.is_open())
				{
					write_date(mList);
					cout << "File loaded successfully" << endl;
					mOutputStream3.close();
				}
			}

			break;
		}
		displayMenu();
		choice = enterChoice();

	} while (choice != 7);	
}

ifstream & operator >> (ifstream &input, List &rhs)
{
	char line[100] = "";
	string Dates[365];
	int Absences = 0;
	input.getline(line, 100); 

	while (!input.eof())
	{
		input.getline(line, 100, ',');
		int data = atoi(line); 

		input.getline(line, 100, ',');
		int ID = atoi(line);

		input.getline(line, 100, ',');
		char Name[100] = "";
		strcpy(Name, line);
		input.getline(line, 100, ',');
		strcat(Name, ",");
		strcat(Name, line);

		input.getline(line, 100, ',');
		char Email[100] = "";
		strcpy(Email, line);

		input.getline(line, 100, ',');
		char Units[100] = "";
		strcpy(Units, line);

		input.getline(line, 100, ',');
		char Program[100] = "";
		strcpy(Program, line);

		input.getline(line, 100);
		char Level[100] = "";
		strcpy(Level, line);

		rhs.insertAtFront(data, ID, Name, Email, Units, Program, Level, Absences, Dates);
	}

	return input;
}

ofstream & operator << (ofstream &output, List &rhs)
{
	Node *pMem = nullptr;
	pMem = rhs.getHeadPtr();

	output << "Record Number, ID, Name, Email, Units, Program, Level" << endl;

	while (pMem != nullptr)
	{
		output << pMem->getData() << ", " << pMem->getID() << "," << pMem->getName() << "," << pMem->getEmail() << "," << pMem->getUnits() << "," << pMem->getProgram() << "," << pMem->getLevel();
		if (pMem->getNextPtr() != nullptr)
			output << endl;

		pMem = pMem->getNextPtr();
	}

	return output;
}

string Menu::displayDate() 
{
	string date = "";
	string temp = "";
	time_t t = time(0);
	struct tm * now = localtime(&t);

	date = to_string(now->tm_mon + 1);
	temp = '/';
	date.append(temp);
	temp = to_string(now->tm_mday);
	date.append(temp);
	temp = '/';
	date.append(temp);
	temp = to_string(now->tm_year + 1900);
	date.append(temp);

	return date;
}

void Menu::markAbsences(List &master) 
{
	Node *pCur = master.getHeadPtr();
	string date[365];
	string temp = "";
	int choice = 0, check = 0;

	while (pCur != nullptr)
	{
		cout << "Is" << pCur->getName() << " here?" << endl;
		cout << "1. Yes (not absent)" << endl << "2. No (absent)" << endl;
		do
		{
			cout << "Enter in a valid choice" << endl;
			cin >> choice;
		} while (choice < 1 || choice > 2);

		if (choice == 2)
		{
			pCur->setAbsences(pCur->getAbsences() + 1);
			temp = displayDate();

			for (int i = 0; i < 365; i++)
			{
				date[i] = pCur->getDates(i);
			}
			
			for (int i = 0; i < 365; i++)
			{
				if (date[i] == "")
				{
					if (check == 0)
					{
						date[i] = temp;
						check = 1;
					}
				}
			}
			check = 0;

			pCur->setDates(date);
		}

		pCur = pCur->getNextPtr();
	}
}

int Menu::displayReport()
{
	int choice = 0;

	cout << "Generating report" << endl << "Enter in the number of your choice" << endl;
	cout << "1. Generate report for all students" << endl << "2. Generate report for students with absences that match or exceed X" << endl << "3. Generate date report" << endl;
	do
	{
		cout << "Enter in a valid choice" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 3);

	return choice;
}

void Menu::write_all(List &master)
{
	Node *pCur = master.getHeadPtr();
	int i = 0;

	while (pCur != nullptr)
	{
		mOutputStream1 << "Name:" << pCur->getName() << endl;
		mOutputStream1 << "Email:" << pCur->getEmail() << endl;
		mOutputStream1 << "Absent: " << pCur->getAbsences() << " time(s)"<< endl;
		mOutputStream1 << "Days: ";

		for (i = 0; i < 365; i++)
		{
			if (pCur->getDates(i) != "")
			{
				if (pCur->getDates(i + 1) == "")
					mOutputStream1 << pCur->getDates(i);
				
				else
					mOutputStream1 << pCur->getDates(i) << ", ";
			}
		}
		mOutputStream1 << endl << endl;

		pCur = pCur->getNextPtr();
	}
}

void Menu::write_x(List &master)
{
	Node *pCur = master.getHeadPtr();
	int i = 0, X = 0;

	cout << "Load students with absences greater than X" << endl << "Enter in a value for X" << endl;
	cin >> X;

	while (pCur != nullptr)
	{
		if (pCur->getAbsences() > X)
		{
			mOutputStream2 << "Name:" << pCur->getName() << endl;
			mOutputStream2 << "Email:" << pCur->getEmail() << endl;
			mOutputStream2 << "Absent: " << pCur->getAbsences() << " time(s)" << endl;
			mOutputStream2 << "Days: ";

			for (i = 0; i < 365; i++)
			{
				if (pCur->getDates(i) != "")
				{
					if (pCur->getDates(i + 1) == "")
						mOutputStream2 << pCur->getDates(i);

					else
						mOutputStream2 << pCur->getDates(i) << ", ";
				}
			}
			mOutputStream2 << endl << endl;
		}

		pCur = pCur->getNextPtr();
	}
}

void Menu::write_date(List &master)
{
	Node *pCur = master.getHeadPtr();
	int i = 0;
	string date = "";

	cout << "Load students with Date XX/YY/ZZZZ" << endl << "Enter in a Date with the format XX/YY/ZZZZ" << endl;
	cin >> date;

	while (pCur != nullptr)
	{
		for (int j = 0; j < 365; j++)
		{
			if (pCur->getDates(j) == date)
			{
				mOutputStream3 << "Name:" << pCur->getName() << endl;
				mOutputStream3 << "Email:" << pCur->getEmail() << endl;
				mOutputStream3 << "Absent: " << pCur->getAbsences() << " time(s)" << endl;
				mOutputStream3 << "Days: ";

				for (i = 0; i < 365; i++)
				{
					if (pCur->getDates(i) != "")
					{
						if (pCur->getDates(i + 1) == "")
							mOutputStream3 << pCur->getDates(i);

						else
							mOutputStream3 << pCur->getDates(i) << ", ";
					}
				}
				mOutputStream3 << endl << endl;
			}
		}

		pCur = pCur->getNextPtr();
	}
}

void Menu::editAbsences(List &master)
{
	Node *pCur = master.getHeadPtr();
	string date[365];
	string temp = "";
	int choice = 0, choice1, check = 0, check1 = 0, check2 = 0, i;

	master.printNameID();
	cout << "Enter in the ID of the student" << endl;
	cin >> choice;

	while (pCur != nullptr)
	{
		if (pCur->getID() == choice)
		{
			cout << "Student: " << pCur->getName() << endl;
			cout << "Absences: " << pCur->getAbsences() << endl;
			cout << "Days: ";
			for (i = 0; i < 365; i++)
			{
				if (pCur->getDates(i) != "")
				{
					if (pCur->getDates(i + 1) == "")
						cout << pCur->getDates(i);

					else
						cout << pCur->getDates(i) << ", ";
				}
			}
			cout << endl;

			cout << "Edit this student?" << endl << "1. Yes" << endl << "2. No" << endl;
			cin >> choice1;

			if (choice1 == 1)
			{
				cout << "Current Absences: " << pCur->getAbsences() << endl;
				cout << "Current Absent Dates: ";
				for (i = 0; i < 365; i++)
				{
					if (pCur->getDates(i) != "")
					{
						if (pCur->getDates(i + 1) == "")
							cout << pCur->getDates(i);

						else
							cout << pCur->getDates(i) << ", ";
					}
				}
				cout << endl;

				for (int i = 0; i < 365; i++)
				{
					date[i] = pCur->getDates(i);
				}

				cout << "Enter in a date. If it exists in the student's absences then it will be deleted. Otherwise, it will be added" << endl;
				cout << "Enter in a Date with the format XX/YY/ZZZZ" << endl;
				cin >> temp;

				for (int i = 0; i < 365; i++)
				{
					if (date[i] == temp)
					{
						date[i] = "";
						check1 = 1;
						pCur->setAbsences(pCur->getAbsences() - 1);
					}
				}

				if (check1 == 0)
				{
					for (int i = 0; i < 365; i++)
					{
						if (date[i] == "" && check2 == 0)
						{
							date[i] = temp;
							pCur->setAbsences(pCur->getAbsences() + 1);
							check2 = 1;
						}
					}
				}

				pCur->setDates(date);

				cout << "Updated Absences: " << pCur->getAbsences() << endl;
				cout << "Updated Absent Dates: ";
				for (i = 0; i < 365; i++)
				{
					if (pCur->getDates(i) != "")
					{
						if (pCur->getDates(i + 1) == "")
							cout << pCur->getDates(i);

						else
							cout << pCur->getDates(i) << ", ";
					}
				}
				cout << endl;
			}

			check = 1;
		}

		pCur = pCur->getNextPtr();
	}

	if (check == 0)
		cout << "Couldn't find student" << endl;
}