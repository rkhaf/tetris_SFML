#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include "Engine.hpp"

float delta=0.0f;


int main() {
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Plane");
    window.setFramerateLimit(60);

    //bikin objek lantai
    sf::RectangleShape lantai({ static_cast<float>(window.getSize().x), 3.0f });
    lantai.setFillColor(sf::Color::White);
    lantai.setPosition({0.0f, static_cast<float>(window.getSize().y-20.0f)});

    //bikin player
    Entity player;

    //gameloop
    while (window.isOpen()) {
        delta=clock.restart().asSeconds();
        player.update(delta);

        while (const std::optional event = window.pollEvent()) {

            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                }
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
            }
        }

        //RENDERING
        window.clear(sf::Color::Black); // ngeclear layar
        
        player.draw(window);

        window.draw(lantai);
        
        window.display(); // ngedisplay ke monitor
    }

    return 0;
}