#pragma once
#include "bricks.h"
#include <list>

class Drawing : sf::RectangleShape, sf::CircleShape
{
public:
	Drawing();

	void insert(sf::RectangleShape &rect);
	void insert(sf::CircleShape &circ);
	void insert(bricks &newbrick);

	void letsDraw(sf::RenderWindow &window);

	std::list <sf::RectangleShape*> *getRectDrawingBegin();

private:
	std::list <sf::RectangleShape*> rectDrawings;
	std::list <sf::CircleShape*> circDrawings;
	std::list <sf::RectangleShape>::iterator rectList;
	std::list <sf::CircleShape > ::iterator circList;
};

inline Drawing::Drawing()
{

}

void Drawing::insert(sf::RectangleShape &rect)
{
	this->rectDrawings.push_front(&rect);

}

void Drawing::insert(sf::CircleShape &circ)
{
	this->circDrawings.push_front(&circ);
}

void Drawing::insert(bricks &newbrick)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
			this->rectDrawings.push_front(&newbrick.brickArr[j][i]);
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
