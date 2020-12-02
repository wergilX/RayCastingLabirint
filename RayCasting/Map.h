#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <SFML/Graphics.hpp>

#include "vector"
#include "Player.h"
#include "constants.h"

//ray casting constant
const float FOV = M_PI / 3;
const float HALF_FOV = FOV / 2;
const float NUM_RAYS = 200;
const float MAX_DEPTH = 800;
const float DELTA_ANGLE = FOV / NUM_RAYS;
const float DIST = NUM_RAYS / (2 * tan(HALF_FOV));
const float PROJ_COEF = 2 * DIST * SIZE_TILE;
const int	SCALE = 800 / NUM_RAYS;

class Map
{
public:
	Map();
	void Draw(sf::RenderWindow* window, Player* player);

private:
	sf::RectangleShape wall;
	sf::RectangleShape tile;
	std::vector<int> simpleMap;
	std::vector<sf::Vector2f> worldMap;
};

