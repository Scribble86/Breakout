#include "Header.h"

int main()
{
	uint32_t style = sf::Style::Close;

	sf::RenderWindow window(sf::VideoMode(600, 400,8), "Breakout", style);

	Drawing drawList;

	sf::Vector2i mouseposition;
	sf::Vector2i windowPosition;

	sf::Vector2u windowSize = window.getSize();
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(160);
	//window.setMouseCursorGrabbed(true);

	sf::CircleShape ball = sf::CircleShape(7.0, 30);
	sf::Vector2f ballStart = sf::Vector2f((windowSize.x / 2) - ball.getRadius(), (windowSize.y / 2) - ball.getRadius());
	ball.setPosition(ballStart);
	ball.setFillColor(sf::Color::White);
	sf::Vector2f ballMoving = sf::Vector2f(1.5, -1.5);
	sf::Vector2f ballStopped = sf::Vector2f(0, 0);
	sf::Vector2f ballMovement = ballMoving;
	
	float paddleWidth = windowSize.x / 10;
	float paddleHeight = windowSize.y / 30;
	sf::Vector2f paddleSize(paddleWidth,paddleHeight);
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

	drawList.insert(ball);
	drawList.insert(paddle);
	drawList.insert(brickL);
	
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

		if (ball.getPosition().x <= 0 || ball.getPosition().x >= (windowSize.x - 2*ball.getRadius()))
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
		if(delay > 10 && collisionDetect(paddle,ball))
		{
			//split into more lines with more variables. find out why left side of paddle is not correct
			
			float angle = getAngle(paddle, ball);
			ballMovement = bounceBall(ball, angle, speed);
			delay = 0;

		}
		if (collisionDetect(brickL, ball, drawList))
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
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		delay++;
		window.clear();

		//window.draw(paddle);
		//window.draw(ball);
		//displayScore(score); // ***FIX*** function deleting bricks needs to return score
		drawList.letsDraw(window);
		window.display();
	}

	return 0;
}

bool collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball)
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

bool collisionDetect(bricks &bricks, sf::CircleShape &ball, Drawing &DrawList)
{
	std::list<sf::RectangleShape*>::iterator li = DrawList.getRectDrawingBegin()->begin();
	for (int i = 0; i < 80; i++)
		li++;

	bool collide = false;
	float ballLeftSide = ball.getPosition().x;
	float ballTopSide = ball.getPosition().y;
	float ballRightSide = ball.getPosition().x + (ball.getRadius() * 2);
	float ballBottomSide = ball.getPosition().y + (ball.getRadius() * 2);
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			
			if (ball.getPosition().y <= bricks.brickArr[j][i].getPosition().y+10)
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
	}
	
	return collide;
}

float getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball)
{
	float relativePositionY = (ball.getPosition().y + ball.getRadius()) - (paddle.getPosition().y + (paddle.getSize().y /2 ));
	float relativePositionX = ball.getPosition().x + ball.getRadius() - paddle.getPosition().x - (paddle.getSize().x / 2);
	float BallPositionX = ball.getPosition().x + ball.getRadius();
	float ballPositionY = ball.getPosition().y + ball.getRadius();
	float paddlePositionX = paddle.getPosition().x + (paddle.getSize().x / 2);
	float paddlePositionY = paddle.getPosition().y + (paddle.getSize().y / 2);

	float angle = std::atan2f(relativePositionY,relativePositionX);

	std::cout << "Relative Position: " << relativePositionX << " angle: " << angle << std::endl;

	return angle;
}

sf::Vector2f bounceBall(sf::CircleShape ball, float angle, float speed)
{
	sf::Vector2f ballMovement = sf::Vector2f(0,0);
	ballMovement.y = (speed * std::sin(angle));
	ballMovement.x = speed * std::cos(angle);
	return ballMovement;
}

int incScore() // needs to be called when brick is deleted
{
	int score = 0;
	score += 5;
	return score;
}

std::string displayScore(int score, sf::RenderWindow &window)
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	sf::Text text;

	std::string str_score = std::to_string(score);

	text.setFont(font);
	text.setString(str_score);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Green);
	text.setStyle(sf::Text::Underlined);

	window.draw(text);

	return str_score;
}