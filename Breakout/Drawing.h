#pragma once
#include "bricks.h"
#include <list>

class Drawing : sf::RectangleShape, sf::CircleShape
{
public:
	Drawing()
	{
		this->rectDrawings;
		this->circDrawings;
		this->rectList = this->rectDrawings.begin();
	}

	void insert(sf::RectangleShape &rect);
	void insert(sf::CircleShape &circ);
	void insert(bricks &newbrick);

	void letsDraw(sf::RenderWindow &window);

	std::vector <RectangleShape*> *getRectDrawingBegin()
	{
		return &this->rectDrawings;
	}

	std::vector <RectangleShape*> getRectDrawings()
	{
		return this->rectDrawings;
	}


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
	this->rectList = this->rectDrawings.begin();

	this->rectDrawings.insert(this->rectList, &rect);
}

void Drawing::insert(sf::CircleShape &circ)
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
	for (std::vector<RectangleShape*>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
		window.draw(**li);

	for (std::vector<CircleShape*>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
		window.draw(**li);
}

inline std::list<sf::RectangleShape*>* Drawing::getRectDrawingBegin()
{
	return &this->rectDrawings;
}
