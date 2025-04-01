#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({520u, 520u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}
