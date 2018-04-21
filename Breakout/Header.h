#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdio>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <cmath>
#include <list>
#include <iterator>
#include "Drawing.h"
#include "bricks.h"

bool collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball, bricks &brickList);
float getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball);