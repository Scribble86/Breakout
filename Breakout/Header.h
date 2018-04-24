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
#include "ball.h"
#include "bricks.h"
#include "Drawing.h"
#include <list>

bool collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball);
bool collisionDetect(sf::CircleShape &ball, sf::RectangleShape &brick);
float getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball);
sf::Vector2f bounceBall(sf::CircleShape ball, float angle, float speed);