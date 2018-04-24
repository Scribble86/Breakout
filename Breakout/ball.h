#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ball : public sf::CircleShape
{
public:
	ball(sf::Vector2f &pos, const sf::Color &fill, float rad, size_t sides)
	{
		this->setPosition(pos);
		this->setFillColor(fill);
		this->setRadius(rad);
		this->setPointCount(sides);
	}
};