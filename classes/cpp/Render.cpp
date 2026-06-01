#include "../headers/Render.hpp"
#include <iostream>

Render::Render(sf::Vector2u windowSize, int limitFramerate){
    m_window.create(sf::VideoMode(windowSize),"mainPanel");
    m_window.clear(sf::Color::Black);
    m_window.setFramerateLimit(limitFramerate);
}

void Render::start(){
    while (m_window.isOpen()) {
        

        //nnti masuk ke modul input
        // while (const std::optional event = m_window.pollEvent()) {
        //     if (event->is<sf::Event::Closed>()) {
        //         m_window.close();
        //     }

        //     if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        //         if (keyPressed->code == sf::Keyboard::Key::Space) {
        //         }
        //         if (keyPressed->code == sf::Keyboard::Key::Escape) {
        //             m_window.close();
        //         }
        //     }
        // }
        m_window.display();
    }
}

void Render::visualize(std::vector<sf::Drawable> komponenDrawable){
    m_window.display();
    std::cout<<"jalan"<<std::endl;
}