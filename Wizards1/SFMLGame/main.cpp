#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

#include "KeyStates.h"
#include "Spell.h"
#include "WSpell.h"
#include "SSpell.h"
#include "ASpell.h"
#include "Node.h"

int main()
{
	std::cout << sf::IpAddress::getLocalAddress() << std::endl;

	sf::IpAddress ip = "192.168.1.9";

	sf::TcpSocket socket;
	char buffer[2000] = "";
	std::size_t received;

	socket.connect(ip, 2000);

	std::cout << socket.getLocalPort() << std::endl;

	sf::RenderWindow window(sf::VideoMode(1120, 630), "Wizards");

	sf::RectangleShape floor(sf::Vector2f(1120, 2));
	floor.setFillColor(sf::Color::Black);

	sf::Texture Wiz1, Wiz2, Key, BKey, RKey, Book1, Container, wSpell, sSpell, aSpell, dSpell, mFreeman, eWatson,
		SpellBallW, SpellBallW1, SpellBallW2, SpellBallW3, SpellBallS, SpellBallS1, SpellBallS2, SpellBallS3, 
		SpellBallA, SpellBallA1, SpellBallA2, SpellBallA3, WhiteSquare;
	if (!Wiz1.loadFromFile("wiz1.png"))
		return 1;
	if (!Wiz2.loadFromFile("wiz2.png"))
		return 1;
	if (!Key.loadFromFile("key.png"))
		return 1;
	if (!BKey.loadFromFile("bkey.png"))
		return 1;
	if (!RKey.loadFromFile("rkey.png"))
		return 1;
	if (!Book1.loadFromFile("book1.png"))
		return 1;
	if (!Container.loadFromFile("container.png"))
		return 1;
	if (!wSpell.loadFromFile("wSpell.png"))
		return 1;
	if (!sSpell.loadFromFile("sSpell.png"))
		return 1;
	if (!aSpell.loadFromFile("aSpell.png"))
		return 1;
	if (!dSpell.loadFromFile("dSpell.png"))
		return 1;
	if (!mFreeman.loadFromFile("MFreeman.png"))
		return 1;
	if (!eWatson.loadFromFile("EWatson.png"))
		return 1;
	if (!SpellBallW.loadFromFile("SpellBallW.png"))
		return 1;
	if (!SpellBallW1.loadFromFile("SpellBallW1.png"))
		return 1;
	if (!SpellBallW2.loadFromFile("SpellBallW2.png"))
		return 1;
	if (!SpellBallW3.loadFromFile("SpellBallW3.png"))
		return 1;
	if (!SpellBallS.loadFromFile("SpellBallS.png"))
		return 1;
	if (!SpellBallS1.loadFromFile("SpellBallS2.png"))
		return 1;
	if (!SpellBallS2.loadFromFile("SpellBallS1.png"))
		return 1;
	if (!SpellBallS3.loadFromFile("SpellBallS3.png"))
		return 1;
	if (!SpellBallA.loadFromFile("SpellBallA.png"))
		return 1;
	if (!SpellBallA1.loadFromFile("SpellBallA1.png"))
		return 1;
	if (!SpellBallA2.loadFromFile("SpellBallA2.png"))
		return 1;
	if (!SpellBallA3.loadFromFile("SpellBallA3.png"))
		return 1;
	if (!WhiteSquare.loadFromFile("WhiteSquare.png"))
		return 1;

	sf::Music FreemanYayW, FreemanYayS, FreemanYayA, FreemanYayD, FreemanNope,
		WatsonYayW, WatsonYayS, WatsonYayA, WatsonYayD, WatsonNope,
		OffenseW, OffenseS, OffenseA, OffenseD;
	if (!FreemanYayW.openFromFile("FreemanYayW.wav"))
		return EXIT_FAILURE;
	if (!FreemanYayS.openFromFile("FreemanYayS.wav"))
		return EXIT_FAILURE;
	if (!FreemanYayA.openFromFile("FreemanYayA.wav"))
		return EXIT_FAILURE;
	if (!FreemanYayD.openFromFile("FreemanYayD.wav"))
		return EXIT_FAILURE;
	if (!FreemanNope.openFromFile("FreemanNope.wav"))
		return EXIT_FAILURE;
	if (!WatsonYayW.openFromFile("WatsonYayW.wav"))
		return EXIT_FAILURE;
	if (!WatsonYayS.openFromFile("WatsonYayS.wav"))
		return EXIT_FAILURE;
	if (!WatsonYayA.openFromFile("WatsonYayA.wav"))
		return EXIT_FAILURE;
	if (!WatsonYayD.openFromFile("WatsonYayD.wav"))
		return EXIT_FAILURE;
	if (!WatsonNope.openFromFile("WatsonNope.wav"))
		return EXIT_FAILURE;
	if (!OffenseW.openFromFile("DefenseW.wav"))
		return EXIT_FAILURE;
	if (!OffenseS.openFromFile("DefenseS.wav"))
		return EXIT_FAILURE;
	if (!OffenseA.openFromFile("DefenseA.wav"))
		return EXIT_FAILURE;
	if (!OffenseD.openFromFile("DefenseD.wav"))
		return EXIT_FAILURE;
	
	KEYSTATES keyState;
	WSPELL w;
	SSPELL s;
	ASPELL a;
	Node *pNode;

	sf::Sprite wiz1(Wiz1), wiz2(Wiz2), Wiz1Head, Wiz2Head;
	sf::Sprite key(Key), key1(Key), key2(Key), key3(Key), key4(Key), key5(Key), key6(Key), key7(Key);
	sf::Sprite book1(Book1), container1(Container), container2(Container);
	sf::Sprite Queue1(WhiteSquare), Queue2(WhiteSquare);
	sf::Sprite CselectW(mFreeman), CselectS(eWatson);

	sf::Font font;
	if (!font.loadFromFile("trebuc.ttf"))
		return EXIT_FAILURE;
	sf::Text text("temp", font), text1("temp", font);

	text.setColor(sf::Color::Black);
	text1.setColor(sf::Color::Black);

	floor.setPosition(0, 500);
	wiz1.setPosition(50, 325);
	Wiz1Head.setPosition(50, 275);
	wiz2.setPosition(975, 290);
	Wiz2Head.setPosition(995, 265);

	key.setPosition(100, 100);
	key1.setPosition(100, 60);
	key2.setPosition(60, 100);
	key3.setPosition(140, 100);

	key4.setPosition(1000, 100);
	key5.setPosition(1000, 60);
	key6.setPosition(960, 100);
	key7.setPosition(1040, 100);

	book1.setPosition(450, 50);
	container1.setPosition(200, 50);
	container2.setPosition(700, 50);

	Queue1.setPosition(720, 160);
	Queue2.setPosition(220, 160);

	window.setKeyRepeatEnabled(false);

	bool instructions = true, player1;
	int slide = 0, character = 0;
	int wins = 0, losses = 0, ties = 0;

	bool playGame = true;
	bool spellLocked = false;
	bool wrongKey = false;
	char keyPressed = '\0';

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::KeyPressed && instructions == true && playGame == true)
			{
				OffenseS.play();

				if (instructions)
				{
					if (slide == 4)
					{
						if (event.key.code == sf::Keyboard::A)
							player1 = true;
						else
							player1 = false;
					}

					if (slide == 5)
					{
						if (event.key.code == sf::Keyboard::W)
						{
							if (player1)
								Wiz1Head.setTexture(mFreeman);
							else
								Wiz2Head.setTexture(mFreeman);

							character = 1;
						}

						if (event.key.code == sf::Keyboard::S)
						{
							if (player1)
								Wiz1Head.setTexture(eWatson);
							else
								Wiz2Head.setTexture(eWatson);

							character = 3;
						}
					}

					slide++;
				}
			}

			if (event.type == sf::Event::KeyPressed && instructions == false && playGame == true)
			{
				if (w.getSpellState() == false && s.getSpellState() == false && a.getSpellState() == false)
				{
					spellLocked = false;
				}

				if (event.key.code == sf::Keyboard::W)
				{
					//W,A,D,D,A,S

					keyPressed = 'W';

					OffenseW.play();

					if (player1)
					{
						wiz1.move(-2, 0);
						Wiz1Head.move(-2, 0);

						keyState.Wiz1AttackW(key, key1, key2, key3, Key, RKey);
					}

					else
					{
						wiz2.move(-2, 0);
						Wiz2Head.move(-2, 0);

						keyState.Wiz2AttackW(key4, key5, key6, key7, Key, RKey);
					}


					if (spellLocked == false)
					{
						w.setSpellState(true);
						spellLocked = true;
					}
				}
				if (event.key.code == sf::Keyboard::S)
				{
					//S,S,W,A,A

					keyPressed = 'S';

					OffenseS.play();

					if (player1)
					{
						wiz1.move(2, 0);
						Wiz1Head.move(2, 0);

						keyState.Wiz1AttackS(key, key1, key2, key3, Key, RKey);
					}

					else
					{
						wiz2.move(2, 0);
						Wiz2Head.move(2, 0);

						keyState.Wiz2AttackS(key4, key5, key6, key7, Key, RKey);
					}

					if (spellLocked == false)
					{
						s.setSpellState(true);
						spellLocked = true;
					}
				}
				if (event.key.code == sf::Keyboard::A)
				{
					//A,D,A,D

					keyPressed = 'A';

					OffenseA.play();

					if (player1)
					{
						wiz1.move(-2, 0);
						Wiz1Head.move(-2, 0);

						keyState.Wiz1AttackA(key, key1, key2, key3, Key, RKey);
					}

					else
					{
						wiz2.move(-2, 0);
						Wiz2Head.move(-2, 0);

						keyState.Wiz2AttackA(key4, key5, key6, key7, Key, RKey);
					}

					if (spellLocked == false)
					{
						a.setSpellState(true);
						spellLocked = true;
					}
				}
				if (event.key.code == sf::Keyboard::D)
				{
					//D,D,S

					keyPressed = 'D';

					OffenseD.play();

					if (player1)
					{
						wiz1.move(2, 0);
						Wiz1Head.move(2, 0);

						keyState.Wiz1AttackD(key, key1, key2, key3, Key, RKey);
					}

					else
					{
						wiz2.move(2, 0);
						Wiz2Head.move(2, 0);

						keyState.Wiz2AttackD(key4, key5, key6, key7, Key, RKey);
					}
				}

				if (w.getSpellState() == true)
				{
					w.setValue(keyPressed);
					w.checkSpellState();
					if (w.getSuccess() == true || w.getFailure() == true)
					{
						if (player1)
						{
							keyState.Wiz1DefendQ(key, key1, key2, key3, Key, BKey);
						}

						else
						{
							keyState.Wiz2DefendQ(key4, key5, key6, key7, Key, BKey);
						}

						if (w.getSuccess() == true)
						{
							if (player1)
								pNode = new Node(SpellBallW, SpellBallW1, wSpell, true);	
							else
								pNode = new Node(SpellBallW2, SpellBallW3, wSpell, false);

							std::string sendS = "W";
							socket.send(sendS.c_str(), sendS.length() + 1);

							switch (character)
							{
							case 1:
								FreemanYayW.play();
								break;
							case 2:
								break;
							case 3:
								WatsonYayW.play();
								break;
							case 4:
								break;
							}
						}

						if (w.getFailure() == true)
						{
							std::string sendS = "F";
							socket.send(sendS.c_str(), sendS.length() + 1);

							switch (character)
							{
							case 1:
								FreemanNope.play();
								break;
							case 2:
								break;
							case 3:
								WatsonNope.play();
								break;
							case 4:
								break;
							}
						}

						w.setSpellState(false);
					}
				}

				if (s.getSpellState() == true)
				{
					s.setValue(keyPressed);
					s.checkSpellState();
					if (s.getSuccess() == true || s.getFailure() == true)
					{
						if (player1)
						{
							keyState.Wiz1DefendQ(key, key1, key2, key3, Key, BKey);
						}

						else
						{
							keyState.Wiz2DefendQ(key4, key5, key6, key7, Key, BKey);
						}

						if (s.getSuccess() == true)
						{
							if (player1)
								pNode = new Node(SpellBallS, SpellBallS1, sSpell, true);
							else
								pNode = new Node(SpellBallS2, SpellBallS3, sSpell, false);
							
							std::string sendS = "S";
							socket.send(sendS.c_str(), sendS.length() + 1);

							switch (character)
							{
							case 1:
								FreemanYayS.play();
								break;
							case 3:
								WatsonYayS.play();
								break;
							}
						}


						if (s.getFailure() == true)
						{
							std::string sendS = "F";
							socket.send(sendS.c_str(), sendS.length() + 1);

							switch (character)
							{
							case 1:
								FreemanNope.play();
								break;
							case 3:
								WatsonNope.play();
								break;
							}
						}

						s.setSpellState(false);
					}
				}

				if (a.getSpellState() == true)
				{
					a.setValue(keyPressed);
					a.checkSpellState();
					if (a.getSuccess() == true || a.getFailure() == true)
					{
						if (player1)
						{
							keyState.Wiz1DefendQ(key, key1, key2, key3, Key, BKey);
						}

						else
						{
							keyState.Wiz2DefendQ(key4, key5, key6, key7, Key, BKey);
						}

						if (a.getSuccess() == true)
						{
							if (player1)
								pNode = new Node(SpellBallA, SpellBallA3, aSpell, true);
							else
								pNode = new Node(SpellBallA1, SpellBallA2, aSpell, false);
							
							std::string sendA = "A";
							socket.send(sendA.c_str(), sendA.length() + 1);

							switch (character)
							{
							case 1:
								FreemanYayA.play();
								break;
							case 3:
								WatsonYayA.play();
								break;
							}
						}

						if (a.getFailure() == true)
						{
							std::string sendS = "F";
							socket.send(sendS.c_str(), sendS.length() + 1);

							switch (character)
							{
							case 1:
								FreemanNope.play();
								break;
							case 3:
								WatsonNope.play();
								break;
							}
						}

						a.setSpellState(false);
					}
				}
			}
		}

		if (playGame == false)
		{
			if (pNode->getWizKilled() == true)
			{
				pNode->setWizKilled(false);
				playGame = true;
			}
		}
		
		if (w.getSuccess() == true || w.getFailure() == true || 
			s.getSuccess() == true || s.getFailure() == true ||
			a.getSuccess() == true || a.getFailure() == true)
		{
			socket.receive(buffer, sizeof(buffer), received);
			std::cout << "buffer: " << buffer << std::endl;

			if (strcmp(buffer, "W") == 0 || strcmp(buffer, "A") == 0 || strcmp(buffer, "S") == 0 || strcmp(buffer, "F") == 0)
			{
				text.setPosition(500, 300);

				if (w.getSuccess() == true || s.getSuccess() == true || a.getSuccess() == true)
				{
					if (strcmp(buffer, "F") == 0)
					{
						wins++;
						std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
						text.setString("You Win!\n");
					}
				}

				if (w.getFailure() == true || s.getFailure() == true || a.getFailure() == true)
				{
					if (strcmp(buffer, "F") == 0)
					{
						ties++;
						std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
						text.setString("Tie Game!");
					}

					else
					{
						losses++;
						std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
						text.setString("You Lose!");
					}

					pNode = new Node(WhiteSquare, WhiteSquare, WhiteSquare, true);
				}
				
				if (strcmp(buffer, "W") == 0 && w.getSuccess() == true)
				{
					ties++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("Tie Game!");
				}
			
				if (strcmp(buffer, "S") == 0 && s.getSuccess() == true)
				{
					ties++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("Tie Game!");
				}

				if (strcmp(buffer, "A") == 0 && a.getSuccess() == true)
				{
					ties++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("Tie Game!");
				}

				if (strcmp(buffer, "W") == 0 && a.getSuccess() == true)
				{
					losses++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Lose!");
				}

				if (strcmp(buffer, "W") == 0 && s.getSuccess() == true)
				{
					wins++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Win!");
				}

				if (strcmp(buffer, "A") == 0 && w.getSuccess() == true)
				{
					wins++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Win!");
				}

				if (strcmp(buffer, "A") == 0 && s.getSuccess() == true)
				{
					losses++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Lose!");
				}

				if (strcmp(buffer, "S") == 0 && a.getSuccess() == true)
				{
					wins++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Win!");
				}

				if (strcmp(buffer, "S") == 0 && w.getSuccess() == true)
				{
					losses++;
					std::cout << "Wins: " << wins << " Losses: " << losses << " Ties: " << ties << std::endl;
					text.setString("You Lose!");
				}

				playGame = false;
			}

			w.setSuccess(false);
			w.setFailure(false);
			s.setSuccess(false);
			s.setFailure(false);
			a.setSuccess(false);
			a.setFailure(false);
		}

		if (wiz1.getPosition() == sf::Vector2f(30, 325) || wiz1.getPosition() == sf::Vector2f(70, 325))
		{
			wiz1.setPosition(50, 325);
			Wiz1Head.setPosition(50, 275);
		}
		if (wiz2.getPosition() == sf::Vector2f(955, 290) || wiz2.getPosition() == sf::Vector2f(995, 290))
		{
			wiz2.setPosition(975, 290);
			Wiz2Head.setPosition(995, 265);
		}

		window.clear(sf::Color(255, 255, 255));

		if (!instructions)
		{
			if (pNode != nullptr)
			{
				if (player1)
					Queue1.setTexture(pNode->getQueueTexture());
				else
					Queue2.setTexture(pNode->getQueueTexture());
				
				pNode->moveBall();
				window.draw(pNode->mSpellBall);
			}

			if (playGame == false)
				window.draw(text);
			
			window.draw(floor);
			window.draw(wiz1);
			window.draw(Wiz1Head);
			window.draw(wiz2);
			window.draw(Wiz2Head);
			window.draw(key);
			window.draw(key1);
			window.draw(key2);
			window.draw(key3);
			window.draw(key4);
			window.draw(key5);
			window.draw(key6);
			window.draw(key7);
			window.draw(book1);
			window.draw(container1);
			window.draw(container2);
			window.draw(Queue1);
			window.draw(Queue2);
		}

		else
		{
			switch (slide)
			{
			case 0:
				text.setPosition(100, 100);
				text1.setPosition(100, 500);
				text.setString("Hello and welcome to Wizards!");
				text1.setString("press any key to continue...");
				window.draw(text);
				window.draw(text1);
				break;
			case 1:
				text.setPosition(100, 100);
				text1.setPosition(100, 500);
				text.setString("The object of the game is to use the WASD keys on your\nkeyboard to cast spells and destroy the enemy.");
				text1.setString("press any key to continue...");
				window.draw(text);
				window.draw(text1);
				break;
			case 2:
				text.setPosition(100, 300);
				text1.setPosition(100, 500);
				text.setString("Match the correct combination in your spell book to\nsend a spell to the other wizard");
				text1.setString("press any key to continue...");
				window.draw(text);
				window.draw(text1);
				window.draw(book1);
				window.draw(container2);
				break;
			case 3:
				text.setPosition(100, 300);
				text1.setPosition(100, 500);
				text.setString("The enemy can also send his/her spells to you.\nIncorrect spells will result in a loss\nFunctions like Rock, Paper, Scissors\nUP spell beats DOWN spell, DOWN beats LEFT, LEFT beats UP");
				text1.setString("press any key to continue...");
				window.draw(text);
				window.draw(text1);
				window.draw(book1);
				window.draw(container1);
				break;
			case 4:
				text.setPosition(100, 100);
				text1.setPosition(100, 500);
				text.setString("Pick a Player\nA. Player 1\nD. Player 2");
				text1.setString("press A or D to continue...");
				window.draw(text);
				window.draw(text1);
				break;
			case 5:
				text.setPosition(100, 100);
				text1.setPosition(100, 500);
				CselectW.setPosition(500, 150);
				CselectS.setPosition(500, 275);
				text.setString("Choose your character");
				text1.setString("press WASD to continue...");
				window.draw(text);
				window.draw(text1);
				window.draw(CselectW);
				window.draw(CselectS);
				break;
			case 6:
				instructions = false;
				break;
			}
		}

		window.display();
	}

	return 0;
}