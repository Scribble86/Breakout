#pragma once
#include "bricks.h"
#include <list>
#include <SFML\Graphics.hpp>
#include <vector>
#include <iterator>

class Drawing : sf::RectangleShape, sf::CircleShape
{
public:
	Drawing();

	void insertR(sf::RectangleShape &rect);
	void insertC(sf::CircleShape &circ);
	void insertB(bricks &newbrick);

	void letsDraw(sf::RenderWindow &window);

	std::list <sf::RectangleShape*> *getRectDrawingBegin();


private:
	std::list <sf::RectangleShape*> rectDrawings;
	std::list <sf::CircleShape*> circDrawings;
	std::list <sf::RectangleShape*>::iterator rectList;
	std::list <sf::CircleShape*> ::iterator circList;
};

inline Drawing::Drawing()
{
	this->rectDrawings;
	this->circDrawings;
	this->rectList = this->rectDrawings.begin();

}

void Drawing::insertR(sf::RectangleShape &rect)
{
	this->rectList = this->rectDrawings.begin();

	this->rectDrawings.insert(this->rectList, &rect);
}

 void Drawing::insertC(sf::CircleShape &circ)
{
	this->circDrawings.insert(this->circList, &circ);
}

void Drawing::insertB(bricks &newbrick)
{
	this->rectList = this->rectDrawings.begin();

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			this->rectList = this->rectDrawings.begin();
			this->rectDrawings.insert(this->rectList, &newbrick.brickArr[j][i]);
		}
	}
}

void Drawing::letsDraw(sf::RenderWindow &window)
{
	for (std::list<sf::RectangleShape*>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
		window.draw(**li);

	for (std::list<sf::CircleShape*>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
		window.draw(**li);
}

inline std::list<sf::RectangleShape*>* Drawing::getRectDrawingBegin()
{
	return &this->rectDrawings;
}
