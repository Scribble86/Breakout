#include "brick.h"


brick::~brick()
{

}

void brick::printBricks(sf::RectangleShape brickArr[], sf::RenderWindow &window)
{
	int i = 0, j = 0;
	for (j = 0; j < 5; j++)
	{
		for (i = 0; i < 20; i++)
		{
			brickArr[i] = brick(*(new sf::Vector2f(0, window.getSize().y)),
				sf::Color::Red,
				*(new sf::Vector2f(window.getSize().x*0.05, window.getSize().y*.025)));

			brickArr[i].setOutlineThickness(-1.5);
			brickArr[i].setOutlineColor(sf::Color::White);

			brickArr[i].setPosition(*(new sf::Vector2f(i * window.getSize().x*0.05, 
				window.getSize().y / 8 + j * window.getSize().y*.025)));

			window.draw(brickArr[i]);
		}
	}
}

