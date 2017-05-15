/*******************************************************************************************
* Programmer: Dillon Ching                                                                 *
* Collaborated With: Derrick Le                                                            *
* Class: CptS 122, Fall 2016; Lab Section 5                                                *
* Programming Assignment: PA4                                                              *
* Date: 10/7/16                                                                            *
* Description: This program stores data about diet and exercise plans. It can read in data,*
* write out data, edit data, and display data using C++.                                   *
*******************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ios;

class FitnessAppWrapper
{
public:
	class DietPlan
	{
	public:
		DietPlan();
		DietPlan(DietPlan &copy);
		~DietPlan();

		void setGoal(int newGoal);
		void setName(string newName);
		void setDate(string newDate);

		int getGoal();
		string getName();
		string getDate();

		void loadDailyPlan(fstream &fileStream, DietPlan &plan);
		void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
		void displayDailyPlan(DietPlan &plan);
		void displayWeeklyPlan(DietPlan weeklyPlan[]);
		void storeDailyPlan(fstream &fileStream, DietPlan &plan);
		void storeWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
		void editDailyPlan(DietPlan &plan);
		void editWeeklyPlan(DietPlan plan[]);
		void writeDailyPlan(fstream &fileStream, DietPlan &plan);
		void writeWeeklyPlan(fstream &fileStream, DietPlan plan[]);
	private:
		int goal;
		string name;
		string date;
	};

	class ExercisePlan
	{
	public:
		ExercisePlan();
		ExercisePlan(ExercisePlan &copy);
		~ExercisePlan();

		void setGoal(int newGoal);
		void setName(string newName);
		void setDate(string newDate);

		int getGoal();
		string getName();
		string getDate();

		void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
		void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
		void displayDailyPlan(ExercisePlan &plan);
		void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
		void storeDailyPlan(fstream &fileStream, ExercisePlan &plan);
		void storeWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
		void editDailyPlan(ExercisePlan &plan);
		void editWeeklyPlan(ExercisePlan plan[]);
		void writeDailyPlan(fstream &fileStream, ExercisePlan &plan);
		void writeWeeklyPlan(fstream &fileStream, ExercisePlan plan[]);
	private:
		int goal;
		string name;
		string date;
	};

private:

};

void displayMenu();
ostream & operator << (ostream &lhs, FitnessAppWrapper::DietPlan rhs[]);
ostream & operator << (ostream &lhs, FitnessAppWrapper::ExercisePlan rhs[]);
fstream & operator >> (fstream &lhs, FitnessAppWrapper::DietPlan rhs[]);
fstream & operator >> (fstream &lhs, FitnessAppWrapper::ExercisePlan rhs[]);
fstream & operator << (fstream &lhs, FitnessAppWrapper::DietPlan rhs[]);
fstream & operator << (fstream &lhs, FitnessAppWrapper::ExercisePlan rhs[]);
