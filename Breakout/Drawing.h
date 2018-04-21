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
	}

	void insert(RectangleShape &rect);
	void insert(CircleShape &circ);
	void insert(brick &newbrick);

	void letsDraw(sf::RenderWindow &window);

private:
	std::list <RectangleShape*> rectDrawings;
	std::list <CircleShape*> circDrawings;
	std::list <RectangleShape>::iterator rectList;
	std::list <CircleShape>::iterator circList;
};

void Drawing::insert(RectangleShape &rect)
{
	this->rectDrawings.push_front(&rect);
}

void Drawing::insert(CircleShape &circ)
{
	this->circDrawings.push_front(&circ);
}

void Drawing::insert(brick &newbrick)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 20; i++)
			this->rectDrawings.push_front(&newbrick.brickArr[j][i]);
	}
}

void Drawing::letsDraw(sf::RenderWindow &window)
{
	for (std::list<RectangleShape*>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
		window.draw(**li);

	for (std::list<CircleShape*>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
		window.draw(**li);
}

//class Drawing : public sf::RectangleShape, public sf::CircleShape
//{
//public:
//	Drawing()
//	{
//		this->rectDrawings;
//		this->circDrawings;
//	}
//
//	void insert(RectangleShape &rect);
//	void insert(CircleShape &circ);
//	void insert(brick &newbrick);
//
//	void letsDraw(sf::RenderWindow &window);
//
//private:
//	std::list <RectangleShape> rectDrawings;
//	std::list <CircleShape> circDrawings;
//};
//
//void Drawing::insert(RectangleShape &rect)
//{
//	this->rectDrawings.push_front(&rect);
//}
//
//void Drawing::insert(CircleShape &circ)
//{
//	this->circDrawings.push_front(&circ);
//}
//
//void Drawing::insert(brick &newbrick)
//{
//	for (int j = 0; j < 5; j++)
//	{
//		for (int i = 0; i < 20; i++)
//			this->rectDrawings.push_front(&newbrick.brickArr[j][i]);
//	}
//}
//
//void Drawing::letsDraw(sf::RenderWindow &window)
//{
//		for (std::list<RectangleShape*>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
//			window.draw(**li);
//
//		for (std::list<CircleShape*>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
//			window.draw(**li);
//
//}