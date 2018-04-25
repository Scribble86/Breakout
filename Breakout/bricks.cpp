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

			if (j == 0)
			{
				brickArr[j][i].setFillColor(sf::Color::Red);
			}
			if (j == 1)
			{
				brickArr[j][i].setFillColor(sf::Color::Yellow);
			}
			if (j == 2)
			{
				brickArr[j][i].setFillColor(sf::Color::Green);
			}
			if (j == 3)
			{
				brickArr[j][i].setFillColor(sf::Color::Blue);
			}
			if (j == 4)
			{
				brickArr[j][i].setFillColor(sf::Color::Magenta);
			}

			brickArr[j][i].setOutlineThickness(-.6);
			brickArr[j][i].setOutlineColor(sf::Color::White);
			brickArr[j][i].setPosition(*(new sf::Vector2f(i * window.getSize().x*0.05, (window.getSize().y / 8) + j * window.getSize().y*.025)));
		}
	}
}
