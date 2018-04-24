#include "imputManager.h"

namespace Breakout {
	bool imputManager::spriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button)) 
		{
			sf::IntRect Rect(object.getPosition().x,object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (Rect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}
	sf::Vector2i GetMousePosition(sf::RenderWindow &window) 
	{
		return sf::Mouse::getPosition(window);
	}
}