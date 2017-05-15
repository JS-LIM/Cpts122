// parts of code are from: http://www.sfml-dev.org/documentation/2.4.1/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");
	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("coug.jpg"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);
	sprite.setScale(.22, .3);

	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("trebuc.ttf"))
		return EXIT_FAILURE;
	sf::Text text("Hello CptS 122!", font, 50);
	
	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("TheRise.wav"))
		return EXIT_FAILURE;
	// Play the music
	music.play();
	// Start the game loop

	Paddle p1;
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite);
		p1.move(0, 1);
		window.draw(p1);
		// Draw the string
		window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}