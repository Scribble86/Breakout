#pragma once
#include <SFML\Graphics.hpp>
#include "state.h"
#include "game.h"

namespace Breakout {

	class SplashState : public State
	{
	public:
		SplashState(GamedRef data);
		void Init();

		void HandleInput();
		void Update(float delta);
		void Draw(float delta);

	private:
		GamedRef Gdata;
		sf::Clock Gclock;
		sf::Texture Gbackground;
	};
}