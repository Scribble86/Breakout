#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>

int main()
{
	//VNKNVKLDNV VF 
	sf::Vector2i mouseposition;
	sf::Vector2i windowPosition;
	uint32_t style = sf::Style::Close;

	sf::RenderWindow window(sf::VideoMode(600, 400,8), "Breakout", style);
	sf::Vector2u windowSize = window.getSize();
	window.setMouseCursorVisible(false);
	//window.setMouseCursorGrabbed(true);

	sf::CircleShape ball = sf::CircleShape(7.0, 30);
	ball.setPosition(*new sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
	ball.setFillColor(sf::Color::White);
	sf::Vector2f ballMovement = sf::Vector2f(0.1, -0.1);
	
	float paddleWidth = windowSize.x / 10;
	float paddleHeight = windowSize.y / 30;
	sf::Vector2f paddleSize(paddleWidth,paddleHeight);
	float paddlePositionY = 9 * (windowSize.y / 10);
	float paddlePositionX = windowSize.x / 2;
	sf::Vector2f paddlePosition(paddlePositionX, paddlePositionY);
	sf::RectangleShape paddle = sf::RectangleShape(paddleSize);
	paddle.setPosition(paddlePosition);
	paddle.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		while(!window.hasFocus())
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
		paddlePosition.x = mouseposition.x - windowPosition.x - (paddleSize.x/2);
		paddle.setPosition(paddlePosition);
		if (ball.getPosition().x <= 0 || ball.getPosition().x >= 600)
		{
			ballMovement.x = -ballMovement.x;
			ball.move(ballMovement);
		}
		if (ball.getPosition().y <= 0)
		{
			ballMovement.y = -ballMovement.y;
		}
		ball.move(ballMovement);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(paddle);
		window.draw(ball);
		window.display();
	}

	return 0;
}