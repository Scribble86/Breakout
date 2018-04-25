#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_ITEMS 3 //keep in track how many items in the menu can be selected

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void Moveup();
	void Movedown();
	void Option(sf::RenderWindow &window);
	int GetItem() { return itemSelected; }
	
	
	
	//void Option(sf::RenderWindow &window);
	//void showInstructions(sf::RenderWindow &window);
	//void exitGame();

private:
	int itemSelected;
	
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture intructions;

	sf::Sprite instructions;
	sf::Sprite text[MAX_NUMBER_ITEMS];

};

