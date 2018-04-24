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
}