#pragma once
#include <SFML\Graphics.hpp>

namespace Breakout {
	class imputManager
	{
	public:
		imputManager() {}
		~imputManager() {}

		bool spriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);//events
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	
	};

}

