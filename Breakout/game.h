#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include <string>
#include "stateMachine.h"
#include "AssetManager.h"
#include "imputManager.h"
#include "bricks.h"
#include "Drawing.h"

namespace Breakout
{
	struct Gamed {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		imputManager input;
	};

	typedef std::shared_ptr<Gamed> GamedRef;

	class Game
	{
	public:
		Game(int width, int height, std::string tittle);

	private:
		const float delta = 1.0f / 60.0f;
		sf::Clock Gclock;

		GamedRef Gdata = std::make_shared<Gamed>();
		void Run();

	};

	class breakout
	{
	private:
		
		uint32_t style;
		sf::RenderWindow *window;
		sf::CircleShape ball;
		sf::RectangleShape paddle;
		bricks brickL;
		Drawing drawList;
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
		breakout();
	};

}
