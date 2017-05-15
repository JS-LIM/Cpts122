#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class SPELL
{
public:
	SPELL();

	void setSpellState(bool state);
	void setValue(char data);
	void setCount(int data);
	void setSuccess(bool state);
	void setFailure(bool state);
	
	bool getSpellState();
	char getValue();
	int getCount();
	bool getSuccess();
	bool getFailure();

	virtual void checkSpellState() = 0;

private:
	char mValue;
	int mCount;
	bool mSpellState;
	bool mSuccess;
	bool mFailure;
};

SPELL::SPELL()
{
	mValue = '\0';
	mCount = 0;
	mSpellState = false;
}

void SPELL::setSpellState(bool state)
{
	this->mSpellState = state;
}

void SPELL::setValue(char data)
{
	this->mValue = data;
}

void SPELL::setCount(int data)
{
	this->mCount = data;
}

void SPELL::setSuccess(bool state)
{
	this->mSuccess = state;
}

void SPELL::setFailure(bool state)
{
	this->mFailure = state;
}

bool SPELL::getSpellState()
{
	return this->mSpellState;
}

char SPELL::getValue()
{
	return this->mValue;
}

int SPELL::getCount()
{
	return this->mCount;
}

bool SPELL::getSuccess()
{
	return this->mSuccess;
}

bool SPELL::getFailure()
{
	return this->mFailure;
}

void SPELL::checkSpellState()
{
	//overridden anyways
}