#include "Map.h"

Map::Map()
{
    simpleMap =
    {
        1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,1,1,
        1,1,1,1,1,1,0,1,0,1,
        1,0,1,0,0,0,0,1,0,1,
        1,1,1,1,0,1,1,1,0,1,
        1,1,0,0,0,0,0,0,0,1,
        1,0,0,1,1,1,1,0,0,1,
        1,0,1,1,0,0,1,0,0,1,
        1,0,0,1,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1
    };

    for (size_t i = 0; i < HEIGHT_MAP; i++)
    {
        for (size_t j = 0; j < WIDTH_MAP; j++)
        {
            if (simpleMap[WIDTH_MAP * i + j] == 1)
            {
                worldMap.push_back(sf::Vector2f(i * SIZE_TILE, j * SIZE_TILE));
            }
        }
    }

    tile.setSize(sf::Vector2f(SIZE_TILE, SIZE_TILE));//
    wall.setFillColor(sf::Color::White);
}


void Map::Draw(sf::RenderWindow* window, Player* player)
{
       
    for (size_t i = 0; i < HEIGHT_MAP; i++)
    {
        for (size_t j = 0; j < WIDTH_MAP; j++)
        {
            if (simpleMap[WIDTH_MAP * i + j] == 1) 
            {
                tile.setPosition(j * tile.getSize().x, i * tile.getSize().y);
            }
        }
    }

    //ray casting
    bool valid_line;
    float cur_angle = player->GetCamAngle() - HALF_FOV;

    for (size_t i = 0; i <= NUM_RAYS; i++)
    {
        valid_line = false;
        float sin_a2 = sin(cur_angle);
        float cos_a2 = cos(cur_angle);

        for (size_t depth = 0; depth <= MAX_DEPTH; depth++)
        {
            int x = player->GetPos().x + depth * cos_a2;
            int y = player->GetPos().y + depth * sin_a2;

            for (sf::Vector2f vec : worldMap)
            {
                if ((int(y / SIZE_TILE * SIZE_TILE) == vec.x && int(x / SIZE_TILE * SIZE_TILE) == vec.y)) {
                    // this is 3d transform
                    float c = 255 / (1 + depth * depth * 0.0001);// Shadow 
                    float proj_height = PROJ_COEF / depth;

                    wall.setPosition(i * SCALE, int(POS_FROM_FLOOR - proj_height / 2));
                    wall.setSize(sf::Vector2f(SCALE, proj_height));
                    wall.setFillColor(sf::Color(c, c, c, 255));
                    window->draw(wall);
                    valid_line = true;
                    break;
                }
            }
            if (valid_line == true)
                break;
        }
        cur_angle += DELTA_ANGLE;
    }
}

