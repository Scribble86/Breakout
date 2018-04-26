//#include "bricks.h"
#include "game.h"
#include"Header.h"
#include <time.h>

Break_Out::Break_Out()
{
	// Brick
	brickL = new bricks(sf::Vector2f(0, 400), sf::Color::Red, *(new sf::Vector2f(30, 10)));
	time_t time = std::time(0);
	srand(time);
	ball = sf::CircleShape(5, 30);
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

	ballStart.x = (paddle.getPosition().x + paddle.getSize().x);
	ballStart.y = ball.getRadius() + paddle.getPosition().y;

	drawList.insertShape(ball);
	paddleD.insertShape(paddle);
	//paddleD.insertShape(topBorder);
	drawList.insertShape(*brickL);
}

int Break_Out::run()
{

	style = sf::Style::Close;
	sf::RenderWindow window(sf::VideoMode(600, 400, 8), "Breakout", style);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(80);
	window.display();
	sf::Vector2u windowSize = window.getSize();

	int score = 0;

	// Top Border
	sf::RectangleShape topBorder;
	topBorder.setPosition(sf::Vector2f(0, 30));
	topBorder.setSize(sf::Vector2f(windowSize.x, 1));

	//Score text
	sf::Text displayScore;

	sf::Font scoreFont;
	if (!scoreFont.loadFromFile("arial.ttf"))
	{
		//std::cout << "ERROR FINDING FILE" << std::endl;
	}

	displayScore.setFont(scoreFont);
	displayScore.setString("Score ");
	displayScore.setCharacterSize(18);
	displayScore.setColor(sf::Color::Blue);
	//displayScore.setOutlineColor(sf::Color::White);
	//displayScore.setOutlineThickness(1);
	displayScore.setStyle(sf::Text::Bold);

	sf::Text displayPoints;
	displayPoints.setFont(scoreFont);
	displayPoints.setString(std::to_string(score));
	displayPoints.setCharacterSize(18);
	displayPoints.setColor(sf::Color::White);
	displayPoints.setStyle(sf::Text::Bold);
	displayPoints.setPosition(sf::Vector2f(55, 0));

	sf::Text gameOver;
	gameOver.setFont(scoreFont);
	gameOver.setString("GAME OVER");
	gameOver.setCharacterSize(30);
	gameOver.setColor(sf::Color::Red);
	gameOver.setOutlineColor(sf::Color::White);
	gameOver.setOutlineThickness(2);
	gameOver.setStyle(sf::Text::Bold);
	gameOver.setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / 2 - 15));

	sf::Text displayLife;
	displayLife.setFont(scoreFont);
	displayLife.setString("Lives");
	displayLife.setCharacterSize(18);
	displayLife.setColor(sf::Color::Blue);
	displayLife.setPosition(sf::Vector2f(window.getSize().x / 2, 0));
	displayLife.setStyle(sf::Text::Bold);

	ballStart = sf::Vector2f((windowSize.x / 2) - ball.getRadius(), (windowSize.y / 2) - ball.getRadius());
	ball.setPosition(ballStart);
	paddleWidth = windowSize.x / 10;
	paddleHeight = windowSize.y / 30;
	paddleSize = sf::Vector2f(paddleWidth, paddleHeight);
	paddlePositionY = 9 * (windowSize.y / 10);
	paddlePositionX = windowSize.x / 2;
	paddlePosition = sf::Vector2f(paddlePositionX, paddlePositionY);
	paddle = sf::RectangleShape(paddleSize);
	paddle.setPosition(paddlePosition);

	ballStart.x = (paddle.getPosition().x + paddle.getSize().x);
	ballStart.y = ball.getRadius() + paddle.getPosition().y;

	bool mBall = false;
	int lives = 3;

	sf::CircleShape ballLife, ballLife2, ballLife3;
	ballLife.setRadius(4.5);
	ballLife.setPointCount(30);
	ballLife.setPosition(sf::Vector2f(window.getSize().x / 2 + 55, 8));

	ballLife2.setRadius(4.5);
	ballLife2.setPointCount(30);
	ballLife2.setPosition(sf::Vector2f(window.getSize().x / 2 + 66, 8));

	ballLife3.setRadius(4.5);
	ballLife3.setPointCount(30);
	ballLife3.setPosition(sf::Vector2f(window.getSize().x / 2 + 77, 8));

	brickL->setBrickArr(*(new sf::Vector2f(0, window.getSize().y)), sf::Color::Red, *(new sf::Vector2f((window.getSize().x)*0.05, window.getSize().y * .025)), window);
	while (window.isOpen())
	{
		if (mBall && lives > 0)
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
			//std::cout << "paddlePosition: " << paddlePosition.x;

			if (paddlePosition.x > 600 - paddle.getSize().x)
			{
				//std::cout << "paddlePosition: " << paddlePosition.x;
				paddlePosition.x = 600 - paddle.getSize().x;
			}
			else if (paddlePosition.x < 0)
			{
				paddlePosition.x = 0;
			}

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
				//std::cout << "ball position:" << ball.getPosition().y;
				ball.setPosition(ballStart);
				ballMovement = ballStopped;
				mBall = false;
				lives--;
			}

			float speed = sqrtf(pow(ballMovement.x, 2) + powf(ballMovement.y, 2));

			//if (delay > 10 && ((ball.getPosition().y + (2*ball.getRadius())) >= paddle.getPosition().y) && (ball.getPosition().y + ball.getRadius()) <= (paddle.getPosition().y + paddle.getSize().y) && ball.getPosition().x >= paddle.getPosition().x && ball.getPosition().x <= (paddle.getPosition().x + paddle.getSize().x))
			if (collisionDetect(paddle, ball))
			{
				//split into more lines with more variables. find out why left side of paddle is not correct

				float angle = getAngle(paddle, ball);
				ballMovement = bounceBall(ball, angle, speed);
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

					if ((ball.getPosition().y + ball.getRadius()) > drawList.getRectDrawingBegin()->at(count)->getPosition().y &&
						(ball.getPosition().y + ball.getRadius()) < (drawList.getRectDrawingBegin()->at(count)->getPosition().y) + drawList.getRectDrawingBegin()->at(count)->getSize().y)
					{
						ballMovement.x = -ballMovement.x;
					}
					else
						ballMovement.y = -ballMovement.y;

					drawList.getRectDrawingBegin()->erase(li);

					//ballMovement = bounceBall(ball, angle, speed);
					score += 5;
					//std::cout << std::endl;
					//std::cout << "brick detect" << std::endl;
					//std::cout << "Score: " << score << std::endl;
					displayPoints.setString(std::to_string(score));
					break;
				}

				if (li != drawList.getRectDrawingBegin()->end())
					count++;
			}

			ball.move(ballMovement);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			drawList.letsDraw(window);
			paddleD.letsDraw(window);
			window.draw(displayScore);
			window.draw(displayLife);
			window.draw(displayPoints);
			window.draw(topBorder);

			if (lives == 3)
			{
				window.draw(ballLife);
				window.draw(ballLife2);
				window.draw(ballLife3);
			}
			else if (lives == 2)
			{
				window.draw(ballLife);
				window.draw(ballLife2);
			}
			else if (lives == 1)
				window.draw(ballLife);

			window.display();
		}
		else
		{
			sf::Event event;
			mouseposition = sf::Mouse::getPosition();
			windowPosition = window.getPosition();
			paddleWidth = windowSize.x / 10;
			paddleHeight = windowSize.y / 30;
			paddleSize.x = paddleWidth;
			paddleSize.y = paddleHeight;
			paddle.setSize(paddleSize);

			paddlePosition.x = mouseposition.x - windowPosition.x - (paddleSize.x / 2);

			if (paddlePosition.x > 600 - paddle.getSize().x)
			{
				//std::cout << "paddlePosition: " << paddlePosition.x;
				paddlePosition.x = 600 - paddle.getSize().x;
			}
			else if (paddlePosition.x < 0)
			{
				paddlePosition.x = 0;
			}

			paddle.setPosition(paddlePosition);
			ball.setPosition(paddlePosition.x + (paddle.getSize().x / 2) - ball.getRadius(), paddlePosition.y - (2 * ball.getRadius()) - 5);
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}



			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					mBall = true;

					if (lives < 0)
					{
						lives = 3;
						score = 0;
						displayPoints.setString(std::to_string(score));
						brickL->setBrickArr(*(new sf::Vector2f(0, window.getSize().y)), sf::Color::Red, *(new sf::Vector2f((window.getSize().x)*0.05, window.getSize().y * .025)), window);
						for (std::vector <sf::RectangleShape*>::iterator li = drawList.getRectDrawingBegin()->begin(); drawList.getRectDrawingBegin()->size() != 0;)
							drawList.getRectDrawingBegin()->erase(li);

						drawList.insertShape(*brickL);
					}

					float speed = 2.5;
					float random = 1.05 * rand();
					ballMovement.x = cos(random)*speed;

					ballMovement.y = sin(random)*speed;
					if (ballMovement.y < 0)
					{
						ballMovement.y = -ballMovement.y;
					}
					//std::cout << "ballmovement.x: " << ballMovement.x << " ballmovement.y: " << ballMovement.y << std::endl;
					//ball.move(ballMovement);
				}
			}


			window.clear();

			drawList.letsDraw(window);
			paddleD.letsDraw(window);
			window.draw(displayScore);
			window.draw(displayLife);
			window.draw(displayPoints);
			window.draw(topBorder);

			if (lives == 3)
			{
				window.draw(ballLife);
				window.draw(ballLife2);
				window.draw(ballLife3);
			}
			else if (lives == 2)
			{
				window.draw(ballLife);
				window.draw(ballLife2);
			}
			else if (lives == 1)
				window.draw(ballLife);
			else
			{
				window.draw(gameOver);
			}


			window.display();
		}
		if (lives == 0 || drawList.getRectDrawings().size() == 0)
		{
			lives--;
			//std::cout << std::endl;
			if (lives == -1)
			{
				//std::cout << "GAME OVER" << std::endl;

			}
		}
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

	//std::cout << "Relative Position: " << relativePositionX << " angle: " << angle << std::endl;

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

	if (ballBottomSide >= paddleTopSide && ballTopSide <= paddleBottomSide && ballRightSide >= paddleLeftSide && ballLeftSide <= paddleRightSide)
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