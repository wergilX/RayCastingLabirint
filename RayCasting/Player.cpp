#include "Player.h"

Player::Player(int idxPosX, int idxPosY)
{
	playerPos.x = (idxPosX * SIZE_TILE) - (SIZE_TILE / 2);
	playerPos.y = (idxPosY * SIZE_TILE) - (SIZE_TILE / 2);
	camAngle = 0.0;
}

sf::Vector2f Player::GetPos() const
{
	return playerPos;
}

void Player::SetPos(float posX, float posY) 
{
	playerPos.x = posX;
	playerPos.y = posY;
}

float Player :: GetCamAngle() const
{
	return camAngle;
}

void Player::SetCamAngle(float angle)
{
	camAngle = angle;
}


void Player::KeyEvent()
{
    float sin_a = sin(camAngle);
    float cos_a = cos(camAngle);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        playerPos.x += PLAYER_SPEED * cos_a;
        playerPos.y += PLAYER_SPEED * sin_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        playerPos.x += -PLAYER_SPEED * cos_a;
        playerPos.y += -PLAYER_SPEED * sin_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        playerPos.x += PLAYER_SPEED * sin_a;
        playerPos.y += -PLAYER_SPEED * cos_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        playerPos.x += -PLAYER_SPEED * sin_a;
        playerPos.y += PLAYER_SPEED * cos_a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        camAngle -= 0.02f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        camAngle += 0.02f;
    }
}