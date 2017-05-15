#pragma once

#include <SFML/Graphics.hpp>

#include "Spell.h"

class WSPELL : public SPELL 
{
public:
	WSPELL();

	void checkSpellState();

private:
	char mKey[6];
};

WSPELL::WSPELL() : SPELL()
{
	//W,A,D,D,A,S

	mKey[0] = 'W';
	mKey[1] = 'A';
	mKey[2] = 'D';
	mKey[3] = 'D';
	mKey[4] = 'A';
	mKey[5] = 'S';
}

void WSPELL::checkSpellState()
{
	std::cout << "Count: " << getCount() << std::endl;
	std::cout << "Value: " << getValue() << std::endl;
	std::cout << "Key: " << mKey[getCount()] << std::endl;

	if (getSpellState() == true)
	{
		if (mKey[getCount()] == getValue())
		{
			setCount(getCount() + 1);

			if (getCount() < 6)
			{
				std::cout << "yup" << std::endl;
			}

			else
			{
				std::cout << "yay" << std::endl;
				setSuccess(true);
				setCount(0);
			}
		}

		else
		{
			std::cout << "nope" << std::endl;
			setFailure(true);
			setCount(0);
			setSpellState(false);
		}
	}
}