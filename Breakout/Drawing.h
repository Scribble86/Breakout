#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <iterator>
#include <algorithm>
#include "bricks.h"

#include <iostream>

class Drawing : public sf::RectangleShape, public sf::CircleShape
{
public:
	Drawing()
	{
		this->rectDrawings;
		this->circDrawings;
		this->rectList = this->rectDrawings.begin();
	}

	void insertR(RectangleShape &rect);
	void insertC(CircleShape &circ);
	void insertB(bricks &newbrick);

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
	std::vector <RectangleShape*> rectDrawings;
	std::vector <CircleShape*> circDrawings;
	std::vector <RectangleShape*>::iterator rectList;
	std::vector <CircleShape*>::iterator circList;
};

void Drawing::insertR(RectangleShape &rect)
{
	this->rectList = this->rectDrawings.begin();

	this->rectDrawings.insert(this->rectList, &rect);
}

void Drawing::insertC(CircleShape &circ)
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