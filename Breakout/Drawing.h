#include "bricks.h"
#include <list>
#include <SFML\Graphics.hpp>
#include <vector>
#include <iterator>

class Drawing : sf::RectangleShape, sf::CircleShape
{
public:
	Drawing();

	void insertShape(sf::RectangleShape &rect);
	void insertShape(sf::CircleShape &circ);
	void insertShape(bricks &newbrick);
	void letsDraw(sf::RenderWindow &window);
	std::vector <sf::RectangleShape*> *getRectDrawingBegin();

	std::vector <RectangleShape*> getRectDrawings()
	{
		return this->rectDrawings;
	}


private:
	std::vector <sf::RectangleShape*> rectDrawings;
	std::vector <sf::CircleShape*> circDrawings;
	std::vector <sf::RectangleShape*>::iterator rectList;
	std::vector <sf::CircleShape*> ::iterator circList;
};