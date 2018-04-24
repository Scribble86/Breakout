#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.h"


int main()
{
	Breakout::Game(600, 400, "Breakout!");


	/*sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		window.clear();
		window.display();

	}*/
 

	/*(45.0, window.getSize().x /window.getSize().y,1.0,500.0);

	Menu menu(window.getSize().x, window.getSize().y);


	//BACKGROUND OF THE GAME MENU
	sf::Texture background;

	if (!background.loadFromFile("pp2.png"))
	{
		std::cout << "ERROR" << std::endl;
	}
	sf::Sprite sprite(background);


	sf::Event event;*

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch (event.type) 
			{
			case sf::Event::KeyReleased:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.Moveup();
					break;

				case sf::Keyboard::Down:
					menu.Movedown();
					break;

				case sf::Keyboard::Space:
					menu.showInstructions();
					{	
						sf::Texture rules;
						if (!background.loadFromFile("rules.png"))
						{
							std::cout << "ERROR" << std::endl;
						}

						sf::Sprite sprite(rules);
					}
					break;

			

				}
				break; //ends Key Released case
			}
			case sf::Event::Closed:
			{
				window.close();
				break;
			}
			default:
				break;
			}
		}
		

		window.clear();
		window.draw(sprite);
		menu.draw(window);
		window.display();

	}*/

	//return 0;

	return EXIT_SUCCESS;
}