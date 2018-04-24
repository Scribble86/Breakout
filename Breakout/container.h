#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class container : public sf::RectangleShape
{
public:
	container(sf::Vector2f &pos, const sf::Color &c, sf::Vector2f &size, const sf::Color &line, float thickness)
	{
		this->setFillColor(c);
		this->setSize(size);
		this->setPosition(pos);
		this->setOutlineColor(line);
		this->setOutlineThickness(thickness);
	}

};