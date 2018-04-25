#pragma once
#include "Drawing.h"
	class Break_Out
	{
	private:

		uint32_t style;
		//sf::RenderWindow window;
		sf::CircleShape ball;
		sf::RectangleShape paddle;
		bricks * brickL;
		Drawing drawList;
		Drawing paddleD;
		sf::Vector2f ballStart;
		sf::Vector2f ballMoving;
		sf::Vector2f ballStopped;
		sf::Vector2f ballMovement;
		sf::Vector2f paddleSize;
		sf::Vector2f paddlePosition;
		sf::Vector2i mouseposition;
		sf::Vector2i windowPosition;
		sf::Vector2u windowSize;
		float paddleWidth;
		float paddleHeight;
		float paddlePositionY;
		float paddlePositionX;
		int delay;
	public:
		Break_Out();
		int run();
		bool collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball);
		//bool collisionDetect(bricks &b, sf::CircleShape &ball, Drawing &d);
		float getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball);
		sf::Vector2f bounceBall(sf::CircleShape ball, float angle, float speed);
	};
