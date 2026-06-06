#include <SFML/Graphics.hpp>
#include "../include/Engine.hpp"

int main() {
    Engine engine(sf::Vector2i(800, 600), {13, 21});
    engine.run();
    return 0;
}