#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "menu.h"
#include "game.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
	Menu menu(window.getSize().x, window.getSize().y);
	/*//AUDIO
	sf::Music music;
	if (!music.openFromFile("floating_also.mp3")) {
		std::cout << "ERROR" << std::endl;
	}
	music.play();*/


	

	//BACKGROUND OF THE GAME MENU
	sf::Texture background;
	if (!background.loadFromFile("pp2.png"))
	{
	std::cout << "ERROR" << std::endl;
	}
	sf::Sprite sprite(background);

	bool inst = false;

	//start the game loop
	while (window.isOpen())
	{
		sf::Event event;
		Break_Out br;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.Moveup();
					break;

				case sf::Keyboard::Down:
					menu.Movedown();
					break;
				case sf::Keyboard::Return:
					
					switch (menu.GetItem())
					{
					case 0:
						std::cout << "Play botton has been pressed" << std::endl;
						br.run();
						break;
					case 1:
						window.clear();
						if (!background.loadFromFile("ins.png"))
						{
							std::cout << "ERROR" << std::endl;
						}

						break;
					case 2:
						window.close();
						break;

					}
					break;
				}
				break; //ends Key Released case
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
	if (!inst) {
		window.draw(sprite);
		
	}
	menu.draw(window);
	//window.draw(sprite);
	//menu.draw(window);
	window.display();

	}

	return 0;
}