#include "Header.h"

int main()
{
	Drawing drawList;
	Drawing paddleD;

	sf::Vector2i mouseposition;
	sf::Vector2i windowPosition;
	uint32_t style = sf::Style::Close;

	sf::RenderWindow window(sf::VideoMode(600, 400, 8), "Breakout", style);
	sf::Vector2u windowSize = window.getSize();
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(160);
	//window.setMouseCursorGrabbed(true);

	sf::CircleShape ball = sf::CircleShape(7.0, 30);
	ball.setPosition(*new sf::Vector2f(windowSize.x / 2, windowSize.y / 2));
	ball.setFillColor(sf::Color::White);
	sf::Vector2f ballMovement = sf::Vector2f(1.5, -1.5);

	float paddleWidth = windowSize.x / 10;
	float paddleHeight = windowSize.y / 30;
	sf::Vector2f paddleSize(paddleWidth, paddleHeight);
	float paddlePositionY = 9 * (windowSize.y / 10);
	float paddlePositionX = windowSize.x / 2;
	sf::Vector2f paddlePosition(paddlePositionX, paddlePositionY);
	sf::RectangleShape paddle = sf::RectangleShape(paddleSize);
	paddle.setPosition(paddlePosition);
	paddle.setFillColor(sf::Color::White);

	// Brick information
	bricks brickL(*(new sf::Vector2f(0, window.getSize().y)), sf::Color::Red, *(new sf::Vector2f(window.getSize().x*0.05, window.getSize().y*.025)));
	brickL.setBrickArr(*(new sf::Vector2f(0, window.getSize().y)), sf::Color::Red, *(new sf::Vector2f((window.getSize().x)*0.05, window.getSize().y*.025)), window);

	int delay = 0;

	drawList.insertC(ball);
	paddleD.insertR(paddle);
	drawList.insertB(brickL);

	while (window.isOpen())
	{
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


		float speed = sqrtf(pow(ballMovement.x, 2) + powf(ballMovement.y, 2));

		//if (delay > 10 && ((ball.getPosition().y + (2*ball.getRadius())) >= paddle.getPosition().y) && (ball.getPosition().y + ball.getRadius()) <= (paddle.getPosition().y + paddle.getSize().y) && ball.getPosition().x >= paddle.getPosition().x && ball.getPosition().x <= (paddle.getPosition().x + paddle.getSize().x))
		if (delay > 10 && collisionDetect(paddle, ball))
		{
			//split into more lines with more variables. find out why left side of paddle is not correct

			float angle = getAngle(paddle, ball);
			ballMovement = bounceBall(ball, angle, speed);
			delay = 0;

		}
		int count = 0;
		for (std::vector<sf::RectangleShape*>::iterator li = drawList.getRectDrawingBegin()->begin();
			li != drawList.getRectDrawingBegin()->end(); li++)
		{
			if (collisionDetect(*drawList.getRectDrawingBegin()->at(count), ball))
			{
			//	drawList.getRectDrawingBegin()->erase(drawList.getRectDrawingBegin()->at(count));
				//float angle = getAngle(*drawList.getRectDrawingBegin()->at(count), ball);
				float angle;

				if ((ball.getPosition().y - ball.getRadius()) < drawList.getRectDrawingBegin()->at(count)->getPosition().y && 
					(ball.getPosition().y + ball.getRadius()) > (drawList.getRectDrawingBegin()->at(count)->getPosition().y) + drawList.getRectDrawingBegin()->at(count)->getSize().y)
					float angle = atan2f(ballMovement.y, -ballMovement.x);
				else
					float angle = atan2f(-ballMovement.y, ballMovement.x);

				drawList.getRectDrawingBegin()->erase(li);
				
				ballMovement = bounceBall(ball, angle, speed);
				delay = 0;
				std::cout << "brick detect" << std::endl;
				break;
			}

			if (li != drawList.getRectDrawingBegin()->end())
				count++;			
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
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		delay++;
		window.clear();

		drawList.letsDraw(window);
		paddleD.letsDraw(window);
		window.display();
	}

	return 0;
}