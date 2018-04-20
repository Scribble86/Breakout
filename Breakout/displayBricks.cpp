
#include "brick.h"

int main()
{
	////SFML Test
	//sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	//sf::RectangleShape shape(sf::Vector2f(50, 25));
	//shape.setFillColor(sf::Color::Red);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//	}

	//	window.clear();
	//	window.draw(shape);
	//	window.display();
	//}

	sf::RenderWindow window(sf::VideoMode(600, 400), "Bricks");

	sf::RectangleShape brickArr[20];

	brick brick(*(new sf::Vector2f(0, window.getSize().y)),
		sf::Color::Red,
		*(new sf::Vector2f(window.getSize().x*0.05, window.getSize().y*.025)));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				window.close();
			}

			window.clear();
			brick.printBricks(brickArr, window);
			window.display();
	}

	return 0;
}