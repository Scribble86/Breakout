#include "Drawing.h"


Drawing::Drawing()
{
	this->rectDrawings;
	this->circDrawings;
	this->rectList = this->rectDrawings.begin();

}

void Drawing::insertShape(sf::RectangleShape &rect)
{
	this->rectList = this->rectDrawings.begin();

	this->rectDrawings.insert(this->rectList, &rect);
}

void Drawing::insertShape(sf::CircleShape &circ)
{
	this->circDrawings.insert(this->circList, &circ);
}

void Drawing::insertShape(bricks &newbrick)
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
	for (std::vector<sf::RectangleShape*>::iterator li = this->rectDrawings.begin(); li != this->rectDrawings.end(); li++)
		window.draw(**li);

	for (std::vector<sf::CircleShape*>::iterator li = this->circDrawings.begin(); li != this->circDrawings.end(); li++)
		window.draw(**li);
}

std::vector<sf::RectangleShape*>* Drawing::getRectDrawingBegin()
{
	return &this->rectDrawings;
}
