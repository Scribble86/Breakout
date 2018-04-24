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

	Break_Out::Break_Out()
	{
		style = sf::Style::Close;

		// Window
		window = new sf::RenderWindow(sf::VideoMode(600, 400, 8), "Breakout", style);
		sf::Vector2u windowSize = window->getSize();
		window->setMouseCursorVisible(false);
		window->setFramerateLimit(160);
		//window.setMouseCursorGrabbed(true);

		// Brick
		brickL = new bricks(*(new sf::Vector2f(0, window->getSize().y)), sf::Color::Red, *(new sf::Vector2f(window->getSize().x*0.05, window->getSize().y*.025)));
		brickL->setBrickArr(*(new sf::Vector2f(0, window->getSize().y)), sf::Color::Red, *(new sf::Vector2f((window->getSize().x)*0.05, window->getSize().y*.025)), *window);

		ball = sf::CircleShape(7.0, 30);
		ballStart = sf::Vector2f((windowSize.x / 2) - ball.getRadius(), (windowSize.y / 2) - ball.getRadius());
		ball.setPosition(ballStart);
		ball.setFillColor(sf::Color::White);
		ballMoving = sf::Vector2f(1.5, -1.5);
		ballStopped = sf::Vector2f(0, 0);
		ballMovement = ballMoving;

		paddleWidth = windowSize.x / 10;
		paddleHeight = windowSize.y / 30;
		paddleSize = sf::Vector2f(paddleWidth, paddleHeight);
		paddlePositionY = 9 * (windowSize.y / 10);
		paddlePositionX = windowSize.x / 2;
		paddlePosition = sf::Vector2f(paddlePositionX, paddlePositionY);
		paddle = sf::RectangleShape(paddleSize);
		paddle.setPosition(paddlePosition);
		paddle.setFillColor(sf::Color::White);

		delay = 0;

		drawList.insertC(ball);
		drawList.insertR(paddle);
		drawList.insertB(*brickL);

	}

	int Break_Out::run()
	{
		while (window->isOpen())
		{
			while (!window->hasFocus())
			{
				//std::cout << "Window does not have focus" << std::endl;
			}
			sf::Event event;
			mouseposition = sf::Mouse::getPosition();
			windowPosition = window->getPosition();
			paddleWidth = windowSize.x / 10;
			paddleHeight = windowSize.y / 30;
			paddleSize.x = paddleWidth;
			paddleSize.y = paddleHeight;
			paddle.setSize(paddleSize);
			paddlePosition.x = mouseposition.x - windowPosition.x - (paddleSize.x / 2);
			paddle.setPosition(paddlePosition);

			if (ball.getPosition().x <= 0 || ball.getPosition().x >= (windowSize.x - 2 * ball.getRadius()))
			{
				ballMovement.x = -ballMovement.x;
			}

			if (ball.getPosition().y <= 30)
			{
				ballMovement.y = -ballMovement.y;
			}
			if (ball.getPosition().y >= 400)
			{
				ball.setPosition(ballStart);
				ballMovement = ballStopped;
			}


			float speed = sqrtf(pow(ballMovement.x, 2) + powf(ballMovement.y, 2));

			//if (delay > 10 && ((ball.getPosition().y + (2*ball.getRadius())) >= paddle.getPosition().y) && (ball.getPosition().y + ball.getRadius()) <= (paddle.getPosition().y + paddle.getSize().y) && ball.getPosition().x >= paddle.getPosition().x && ball.getPosition().x <= (paddle.getPosition().x + paddle.getSize().x))
			if (delay > 10 && collisionDetect(paddle, ball))
			{
				//split into more lines with more variables. find out why left side of paddle is not correct

				float angle = getAngle(paddle, ball);
				ballMovement = bounceBall(ball, angle, speed);
				delay = 0;

			}
			if (collisionDetect(*brickL, ball, drawList))
			{
				float angle = atan2f(-ballMovement.y, ballMovement.x);
				ballMovement = bounceBall(ball, angle, speed);
				delay = 0;
				std::cout << "brick detect" << std::endl;
			}
			//if (delay > 10 && collisionDetect(leftBound, ball))
			//{
			//	float angle = getAngle(leftBound, ball);
			//	ballMovement.y = (speed * std::sin(angle));
			//	ballMovement.x = speed * std::cos(angle);
			//	delay = 0;
			//}
			//if (delay > 10 && collisionDetect(topBound, ball))
			//{
			//	float angle = getAngle(topBound, ball);
			//	ballMovement.y = (speed * std::sin(angle));
			//	ballMovement.x = speed * std::cos(angle);
			//	delay = 0;
			//}
			//if (delay > 10 && collisionDetect(rightBound, ball))
			//{
			//	float angle = getAngle(rightBound, ball);
			//	ballMovement.y = (speed * std::sin(angle));
			//	ballMovement.x = speed * std::cos(angle);
			//	delay = 0;
			//}

			ball.move(ballMovement);
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
			}
			delay++;
			window->clear();

			drawList.letsDraw(*window);
			window->display();
		}

		return 0;
	}


	float Break_Out::getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball)
	{
		float relativePositionY = (ball.getPosition().y + ball.getRadius()) - (paddle.getPosition().y + (paddle.getSize().y / 2));
		float relativePositionX = ball.getPosition().x + ball.getRadius() - paddle.getPosition().x - (paddle.getSize().x / 2);
		float BallPositionX = ball.getPosition().x + ball.getRadius();
		float ballPositionY = ball.getPosition().y + ball.getRadius();
		float paddlePositionX = paddle.getPosition().x + (paddle.getSize().x / 2);
		float paddlePositionY = paddle.getPosition().y + (paddle.getSize().y / 2);

		float angle = std::atan2f(relativePositionY, relativePositionX);

		std::cout << "Relative Position: " << relativePositionX << " angle: " << angle << std::endl;

		return angle;
	}

	bool Break_Out::collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball)
	{
		bool collide = false;
		float ballLeftSide = ball.getPosition().x;
		float ballTopSide = ball.getPosition().y;
		float ballRightSide = ball.getPosition().x + (ball.getRadius() * 2);
		float ballBottomSide = ball.getPosition().y + (ball.getRadius() * 2);
		float paddleLeftSide = paddle.getPosition().x;
		float paddleRightSide = paddle.getPosition().x + paddle.getSize().x;
		float paddleTopSide = paddle.getPosition().y;
		float paddleBottomSide = paddle.getPosition().y + paddle.getSize().y;
		if (ballBottomSide >= paddleTopSide && ballTopSide < paddleBottomSide && ballRightSide >= paddleLeftSide && ballLeftSide <= paddleRightSide)
		{
			collide = true;
		}

		return collide;
	}

	sf::Vector2f Break_Out::bounceBall(sf::CircleShape ball, float angle, float speed)
	{
		sf::Vector2f ballMovement = sf::Vector2f(0, 0);
		ballMovement.y = (speed * std::sin(angle));
		ballMovement.x = speed * std::cos(angle);
		return ballMovement;
	}

	bool Break_Out::collisionDetect(bricks &bricks, sf::CircleShape &ball, Drawing &DrawList)
	{
		//DrawList.getRectDrawingBegin()->begin();
		//std::list<sf::RectangleShape*>::iterator li = &DrawList.getRectDrawings()->begin();
		//for (int i = 0; i < 80; i++)
		//	li++;

		bool collide = false;
		float ballLeftSide = ball.getPosition().x;
		float ballTopSide = ball.getPosition().y;
		float ballRightSide = ball.getPosition().x + (ball.getRadius() * 2);
		float ballBottomSide = ball.getPosition().y + (ball.getRadius() * 2);
		
		
		/*for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 20; i++)
			{

				if (ball.getPosition().y <= bricks.brickArr[j][i].getPosition().y + 10)
					collide = true;
				if (collide == true)
				{

					int remove = j + i;
					DrawList.getRectDrawingBegin()->erase(li);
					break;
				}
				li--;
			}
			if (collide == true)
				break;
		}*/

		return collide;
	}

}