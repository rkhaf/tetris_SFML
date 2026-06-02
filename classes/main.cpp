#include <SFML/Graphics.hpp>
#include "headers/Engine.hpp"

int main() {
    Engine engine(sf::Vector2i(800, 600), {13, 21});
    std::cout<<"test1"<<std::endl;
    engine.run();
    return 0;
}