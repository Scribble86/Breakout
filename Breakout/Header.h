/*////////////////////////////////////////////////////////////////////////////////////
*																					*
*	PA 9: BreakOut!																	*
*	Class: CPT_S 122, Spring 2018													*
*	Team Members: Aaron Hanson														*
*				  Nikita Chrysephan													*
*				  Mariana Rodriguez													*
*				  Connor															*
*																					*
*																					*
*																					*
////////////////////////////////////////////////////////////////////////////////////*/


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
#include "ball.h"
#include <iterator>
#include <map>// To store textures and fonts
#include <memory> 
#include <stack> //states will be depending on the stack in the game
#include <algorithm>
#include <memory>
#include <string>

//bool collisionDetect(sf::RectangleShape &paddle, sf::CircleShape &ball);
//float getAngle(sf::RectangleShape &paddle, sf::CircleShape &ball);
//sf::Vector2f bounceBall(sf::CircleShape ball, float angle, float speed)