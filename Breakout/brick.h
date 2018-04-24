#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class brick : public sf::RectangleShape
{
public:
	brick(sf::Vector2f &pos, const sf::Color &c, sf::Vector2f &size)
	{
		this->setFillColor(c);
		this->setSize(size);
		this->setPosition(pos);
	}

	~brick();

	void printBricks(sf::RectangleShape brickArr[], sf::RenderWindow &window);
	
};

class invincibleBrick : public brick
{
public:
	invincibleBrick(sf::Vector2f &pos, const sf::Color &c, sf::Vector2f &size) : brick(pos, c, size)
	{
		this->setFillColor(c);
		this->setSize(size);
		this->setPosition(pos);
	}


};