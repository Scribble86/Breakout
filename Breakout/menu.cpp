#include "menu.h"
#include <iostream>


Menu::Menu(float width, float height)
{
	
	if (((texture.loadFromFile("play.png ")) && (texture2.loadFromFile("instructions.png ")))&& (texture3.loadFromFile("exit.png ")))
	{
		//handle error
	}
		text[0].setTexture(texture);
		text[0].setColor(sf::Color::Magenta);
		text[0].move(sf::Vector2f(120, 210));

		text[1].setTexture(texture2);
		text[1].setColor(sf::Color::White);
		text[1].move(sf::Vector2f(120,260));
	
		text[2].setTexture(texture3);
		text[2].setColor(sf::Color::White);
		text[2].move(sf::Vector2f(120, 310));
	
	itemSelected = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {

	for(int i = 0; i < MAX_NUMBER_ITEMS; i++) {

		window.draw(text[i]);
	}
}
	
void Menu::Moveup() {
	if (itemSelected - 1 >= 0)
	{
		text[itemSelected].setColor(sf::Color::White);
		itemSelected--;
		text[itemSelected].setColor(sf::Color::Magenta);
	}
}
void Menu::Movedown() {
	if (itemSelected + 1 <MAX_NUMBER_ITEMS)
	{
		text[itemSelected].setColor(sf::Color::White);
		itemSelected++;
		text[itemSelected].setColor(sf::Color::Magenta);
	}
}
void Menu::Option(sf::RenderWindow &window) {

		if (intructions.loadFromFile("rules.png")) {

			window.draw(instructions);
		}
}
