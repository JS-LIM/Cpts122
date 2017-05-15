#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Node : public sf::Sprite
{
public:
	Node(sf::Texture &Texture, sf::Texture &Texture1, sf::Texture &KeyTexture, bool player);

	void setWizKilled(bool state);
	void setQueueTexture(sf::Texture texture);
	void setNextPtr(Node * pNewNext);

	bool getWizKilled(); 
	sf::Texture & getQueueTexture();
	Node * getNextPtr();

	void moveBall();

	sf::Sprite mSpellBall;
	

private:
	bool mPlayer1;
	bool mWizKilled;
	bool mballState;
	sf::Texture mBallTexture;
	sf::Texture mBallTexture1;
	sf::Texture mQueueTexture;
	Node *mpNext;
};

Node::Node(sf::Texture &Texture, sf::Texture &Texture1, sf::Texture &KeyTexture, bool player) : Sprite(Texture)
{
	mSpellBall.setTexture(Texture);
	

	mQueueTexture = KeyTexture;

	mBallTexture = Texture;
	mBallTexture1 = Texture1;

	mWizKilled = false;
	mballState = false;

	if (player)
	{
		mPlayer1 = true;
		mSpellBall.setPosition(70, 325);
	}
		
	else
	{
		mPlayer1 = false;
		mSpellBall.setPosition(970, 325);
	}
		
}

void Node::moveBall()
{
	if (mPlayer1)
	{
		mSpellBall.move(.25, 0);

		if (mSpellBall.getPosition().x > 890)
		{
			mSpellBall.setPosition(2000, 325);
			setWizKilled(true);
		}
	}
	
	else
	{
		mSpellBall.move(-.25, 0);

		if (mSpellBall.getPosition().x < 100)
		{
			mSpellBall.setPosition(-2000, 325);
			setWizKilled(true);
		}
	}

	if (!mballState)
	{
		mSpellBall.setTexture(mBallTexture);
		mballState = true;
	}

	else
	{
		mSpellBall.setTexture(mBallTexture1);
		mballState = false;
	}
}

void Node::setWizKilled(bool state)
{
	this->mWizKilled = state;
}

void Node::setQueueTexture(sf::Texture texture)
{
	this->mQueueTexture = texture;
}

void Node::setNextPtr(Node * pNewNext)
{
	this->mpNext = pNewNext;
}

bool Node::getWizKilled()
{
	return this->mWizKilled;
}

sf::Texture & Node::getQueueTexture()
{
	return this->mQueueTexture;
}

Node * Node::getNextPtr()
{
	return this->mpNext;
}