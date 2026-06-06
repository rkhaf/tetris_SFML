#include <SFML/Graphics.hpp>
#include "../include/Engine.hpp"

int main() {
    // Engine engine(sf::Vector2u(800, 600), sf::Vector2i(13, 21));
    Engine engine(sf::Vector2u(800, 600), sf::Vector2u(13, 21));
    // engine.run();
    engine.start();
    return 0;
}