#pragma once
#include <SFML\Graphics.hpp>
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

}