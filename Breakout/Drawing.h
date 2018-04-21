#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <iterator>
#include <algorithm>

#include <iostream>

class Drawing : public sf::RectangleShape, public sf::CircleShape
{
public:
	Drawing()
	{
		this->rectDrawings;
		this->circDrawings;
	}

	void insertRect(RectangleShape &rect);
	void insertCirc(CircleShape &circ);

	void letsDraw(sf::RenderWindow &window);

private:
	std::list <RectangleShape> rectDrawings;
	std::list <CircleShape> circDrawings;
};

void Drawing::insertRect(RectangleShape &rect)
{
	this->rectDrawings.push_front(rect);
}

void Drawing::insertCirc(CircleShape &circ)
{
	this->circDrawings.push_front(circ);
}

void Drawing::letsDraw(sf::RenderWindow &window)
{
	for (std::list<RectangleShape>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
		window.draw(*li);

	for (std::list<CircleShape>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
		window.draw(*li);

	/*while (this->rectDrawings.size() != 0)
	{
		window.draw(rectDrawings.front());
		this->rectDrawings.pop_front();
	}*/
	//while (this->circDrawings.size() != 0)
	//{
	//	window.draw(circDrawings.front());
	//	this->circDrawings.pop_front();
	//}
}