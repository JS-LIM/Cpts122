#pragma once

#include <SFML/Graphics.hpp>

class KEYSTATES
{
public:
	void Wiz1AttackW(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey);
	void Wiz1DefendW(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey);
	void Wiz1AttackS(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey);
	void Wiz1DefendS(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey);
	void Wiz1AttackA(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey);
	void Wiz1DefendA(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey);
	void Wiz1AttackD(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey);
	void Wiz1DefendD(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey);
	void Wiz1AttackQ(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey);
	void Wiz1DefendQ(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey);

	void Wiz2AttackW(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey);
	void Wiz2DefendW(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey);
	void Wiz2AttackS(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey);
	void Wiz2DefendS(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey);
	void Wiz2AttackA(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey);
	void Wiz2DefendA(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey);
	void Wiz2AttackD(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey);
	void Wiz2DefendD(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey);
	void Wiz2AttackQ(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey);
	void Wiz2DefendQ(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey);
};

void KEYSTATES::Wiz1AttackW(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey)
{
	key1.setTexture(RKey);
	key.setTexture(Key);
	key2.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1DefendW(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey)
{
	key1.setTexture(BKey);
	key.setTexture(Key);
	key2.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1AttackS(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey)
{
	key.setTexture(RKey);
	key1.setTexture(Key);
	key2.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1DefendS(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey)
{
	key.setTexture(BKey);
	key1.setTexture(Key);
	key2.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1AttackA(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey)
{
	key2.setTexture(RKey);
	key.setTexture(Key);
	key1.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1DefendA(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey)
{
	key2.setTexture(BKey);
	key.setTexture(Key);
	key1.setTexture(Key);
	key3.setTexture(Key);
}

void KEYSTATES::Wiz1AttackD(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey)
{
	key3.setTexture(RKey);
	key.setTexture(Key);
	key2.setTexture(Key);
	key1.setTexture(Key);
}

void KEYSTATES::Wiz1DefendD(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey)
{
	key3.setTexture(BKey);
	key.setTexture(Key);
	key2.setTexture(Key);
	key1.setTexture(Key);
}

void KEYSTATES::Wiz1AttackQ(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &RKey)
{
	key3.setTexture(RKey);
	key.setTexture(RKey);
	key2.setTexture(RKey);
	key1.setTexture(RKey);
}

void KEYSTATES::Wiz1DefendQ(sf::Sprite &key, sf::Sprite &key1, sf::Sprite &key2, sf::Sprite &key3, sf::Texture &Key, sf::Texture &BKey)
{
	key3.setTexture(BKey);
	key.setTexture(BKey);
	key2.setTexture(BKey);
	key1.setTexture(BKey);
}

void KEYSTATES::Wiz2AttackW(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey)
{
	key5.setTexture(RKey);
	key4.setTexture(Key);
	key6.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2DefendW(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey)
{
	key5.setTexture(BKey);
	key4.setTexture(Key);
	key6.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2AttackS(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey)
{
	key4.setTexture(RKey);
	key5.setTexture(Key);
	key6.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2DefendS(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey)
{
	key4.setTexture(BKey);
	key5.setTexture(Key);
	key6.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2AttackA(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey)
{
	key6.setTexture(RKey);
	key4.setTexture(Key);
	key5.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2DefendA(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey)
{
	key6.setTexture(BKey);
	key4.setTexture(Key);
	key5.setTexture(Key);
	key7.setTexture(Key);
}

void KEYSTATES::Wiz2AttackD(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey)
{
	key7.setTexture(RKey);
	key4.setTexture(Key);
	key6.setTexture(Key);
	key5.setTexture(Key);
}

void KEYSTATES::Wiz2DefendD(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey)
{
	key7.setTexture(BKey);
	key4.setTexture(Key);
	key6.setTexture(Key);
	key5.setTexture(Key);
}

void KEYSTATES::Wiz2AttackQ(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &RKey)
{
	key7.setTexture(RKey);
	key4.setTexture(RKey);
	key6.setTexture(RKey);
	key5.setTexture(RKey);
}

void KEYSTATES::Wiz2DefendQ(sf::Sprite &key4, sf::Sprite &key5, sf::Sprite &key6, sf::Sprite &key7, sf::Texture &Key, sf::Texture &BKey)
{
	key7.setTexture(BKey);
	key4.setTexture(BKey);
	key6.setTexture(BKey);
	key5.setTexture(BKey);
}