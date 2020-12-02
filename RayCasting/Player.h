#pragma once
#include "constants.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(int idxPosX, int idxPosY);

	sf::Vector2f GetPos() const;
	void SetPos(float idxPosX, float idxPosY);

	float GetCamAngle() const;
	void SetCamAngle(float angle);

	void KeyEvent();

	
private:
	
	sf::Vector2f playerPos;
	float camAngle;
};

