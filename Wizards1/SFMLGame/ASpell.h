#pragma once

#include <SFML/Graphics.hpp>

#include "Spell.h"

class ASPELL : public SPELL
{
public:
	ASPELL();

	void checkSpellState();

private:
	char mKey[4];
};

ASPELL::ASPELL() : SPELL()
{
	//A,D,A,D

	mKey[0] = 'A';
	mKey[1] = 'D';
	mKey[2] = 'A';
	mKey[3] = 'D';
}

void ASPELL::checkSpellState()
{
	std::cout << "Count: " << getCount() << std::endl;
	std::cout << "Value: " << getValue() << std::endl;
	std::cout << "Key: " << mKey[getCount()] << std::endl;

	setSuccess(false);
	setFailure(false);

	if (getSpellState() == true)
	{
		if (mKey[getCount()] == getValue())
		{
			setCount(getCount() + 1);

			if (getCount() < 4)
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