#include "container.h"
#include "ball.h"
#include "Drawing.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <list>
#include <iterator>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Brick Ball");
	//window.setFramerateLimit(1);
	sf::Vector2u windowSize = window.getSize();

	container room(*(new sf::Vector2f(3, 30)), sf::Color::Black, *(new sf::Vector2f(594, 394)), sf::Color::White, 2.0);

	sf::Vector2i mouseposition;
	sf::Vector2i windowPosition;
	uint32_t style = sf::Style::Close;

	Drawing drawList;
	
	ball b1(*(new sf::Vector2f(100, 130)), sf::Color::White, 6.0, 10);
	//ball b2(*(new sf::Vector2f(100, 500)), sf::Color::Red, 6.0, 10);

	drawList.insertCirc(b1);
	drawList.insertRect(room);

	float paddleWidth = windowSize.x / 10;
	float paddleHeight = windowSize.y / 30;
	sf::Vector2f paddleSize(paddleWidth, paddleHeight);
	float paddlePositionY = 9 * (windowSize.y / 10);
	float paddlePositionX = windowSize.x / 2;
	sf::Vector2f paddlePosition(paddlePositionX, paddlePositionY);
	sf::RectangleShape paddle = sf::RectangleShape(paddleSize);
	paddle.setPosition(paddlePosition);
	paddle.setFillColor(sf::Color::White);

	drawList.insertRect(paddle);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (b1.getPosition().y > 499)
				b1.setFillColor(sf::Color::Black);
			
			while (!window.hasFocus())
			{
				//std::cout << "Window does not have focus" << std::endl;
			}
			sf::Event event;
			mouseposition = sf::Mouse::getPosition();
			windowPosition = window.getPosition();
			paddleWidth = windowSize.x / 10;
			paddleHeight = windowSize.y / 30;
			paddleSize.x = paddleWidth;
			paddleSize.y = paddleHeight;
			paddle.setSize(paddleSize);
			paddlePositionX = mouseposition.x - windowPosition.x - (paddleSize.x / 2);
			if (paddlePositionX >= room.getPosition().x && paddlePositionX <= (room.getSize().x + room.getPosition().x - paddleSize.x ))
			{
				paddlePosition.x = paddlePositionX;
				paddle.setPosition(paddlePosition);
			}
		}
	
		if (b1.getPosition().y < 300)
			b1.move(.6, .6);

		window.clear();
//		window.draw(room);
//		window.draw(paddle);
//		window.draw(b1);
		drawList.letsDraw(window);
		window.display();
	}

	return 0;
}