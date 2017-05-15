#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{

public:
	
	Paddle() : RectangleShape(sf::Vector2f(10, 50))
	{
		setFillColor(sf::Color::Green);
	}


private:

	
};