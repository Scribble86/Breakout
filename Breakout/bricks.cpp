#include "bricks.h"
bricks::bricks(sf::Vector2f & pos, const sf::Color & c, sf::Vector2f & size)
{
	this->setFillColor(c);
	this->setSize(size);
	this->setPosition(pos);
}

bricks::~bricks()
{

}

void bricks::setBrickArr(sf::Vector2f & pos, const sf::Color & c, sf::Vector2f & size, sf::RenderWindow & window)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			this->brickArr[j][i] = bricks(pos, c, size);

			brickArr[j][i].setOutlineThickness(-.6);
			brickArr[j][i].setOutlineColor(sf::Color::White);
			brickArr[j][i].setPosition(*(new sf::Vector2f(i * window.getSize().x*0.05, (window.getSize().y / 8) + j * window.getSize().y*.025)));
		}
	}
}
