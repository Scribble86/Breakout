#include "game.h"

namespace Breakout {
	Game::Game(int width, int height, std::string title)
	{
		Gdata->window.create(sf::VideoMode(width, height), title, sf::Style::Close || sf::Style::Titlebar);
		//Gdata->machine.addState(StateRef(new Splashstat))

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		float curentTime = this->Gclock.getElapsedTime().
			asSeconds();
		float accumulator = 0.0f;

		while (this->Gdata->window.isOpen())
		{
			this->Gdata->machine.changeState();
			newTime = this->Gclock.getElapsedTime().asSeconds();
			frameTime = newTime - curentTime;

			if (frameTime > 0.25f)
			{
				frameTime = newTime;
				accumulator += frameTime;

				while (accumulator >= delta) {
					this->Gdata->machine.GetActiveState()->HandleImput();
					this->Gdata->machine.GetActiveState()->Update(delta);

					accumulator -= delta;
				}
				interpolation = accumulator / delta;
				this->Gdata->machine.GetActiveState()->Draw(interpolation);
			}
		}
	}

	breakout::breakout()
	{
		style = sf::Style::Close;

		// Window
		window = new sf::RenderWindow(sf::VideoMode(600, 400, 8), "Breakout", style);
		sf::Vector2u windowSize = window->getSize();
		window->setMouseCursorVisible(false);
		window->setFramerateLimit(160);
		//window.setMouseCursorGrabbed(true);
		
		// Brick
		brickL = bricks(*(new sf::Vector2f(0, window->getSize().y)), sf::Color::Red, *(new sf::Vector2f(window->getSize().x*0.05, window->getSize().y*.025)));
		brickL.setBrickArr(*(new sf::Vector2f(0, window->getSize().y)), sf::Color::Red, *(new sf::Vector2f((window->getSize().x)*0.05, window->getSize().y*.025)), *window);

		Drawing drawList;
		
		sf::CircleShape ball = sf::CircleShape(7.0, 30);
		sf::Vector2f ballStart = sf::Vector2f((windowSize.x / 2) - ball.getRadius(), (windowSize.y / 2) - ball.getRadius());
		ball.setPosition(ballStart);
		ball.setFillColor(sf::Color::White);
		sf::Vector2f ballMoving = sf::Vector2f(1.5, -1.5);
		sf::Vector2f ballStopped = sf::Vector2f(0, 0);
		sf::Vector2f ballMovement = ballMoving;

		float paddleWidth = windowSize.x / 10;
		float paddleHeight = windowSize.y / 30;
		sf::Vector2f paddleSize(paddleWidth, paddleHeight);
		float paddlePositionY = 9 * (windowSize.y / 10);
		float paddlePositionX = windowSize.x / 2;
		sf::Vector2f paddlePosition(paddlePositionX, paddlePositionY);
		sf::RectangleShape paddle = sf::RectangleShape(paddleSize);
		paddle.setPosition(paddlePosition);
		paddle.setFillColor(sf::Color::White);

		int delay = 0;

		drawList.insert(ball);
		drawList.insert(paddle);
		drawList.insert(brickL);
	}
}
