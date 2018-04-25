//#include "Header.h"
#include <SFML\Graphics.hpp>

class bricks : public sf::RectangleShape
{
public:
	bricks(sf::Vector2f &pos, const sf::Color &c, sf::Vector2f &size);

	~bricks();

	void setBrickArr(sf::Vector2f &pos, const sf::Color &c, sf::Vector2f &size, sf::RenderWindow &window);

	//	void printBricks(sf::RectangleShape brickArr[], sf::RenderWindow &window);

	RectangleShape brickArr[5][20];
};