#include "Map.h"
#include "Player.h"
#include <SFML/Graphics.hpp>


sf::Clock Clock;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ray Casting");

    Map map;
    Player player(2, 2);

    while (window.isOpen())
    {
        window.setFramerateLimit(60);
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Keyboard
        player.KeyEvent();

        //Draw
         window.clear();
         map.Draw(&window,&player);
         window.display();
    }

    return 0;
}