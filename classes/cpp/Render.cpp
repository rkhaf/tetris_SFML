#include "../headers/Render.hpp"
#include <iostream>
#include "../headers/Engine.hpp"

Render::Render(sf::Vector2u windowSize, int limitFramerate, Engine* engine){
    m_window.create(sf::VideoMode(windowSize),"mainPanel");
    m_window.clear(sf::Color::Black);
    m_window.setFramerateLimit(limitFramerate);
    m_engine=engine;
}

void Render::start(){
    std::cout<<"size array scene: "<<m_engine->m_kumpulanScene.size()<<std::endl;
    while (m_window.isOpen()) {
        m_window.clear(sf::Color::Black);
        // m_engine->m_kumpulanScene[0]->getKomponen
        for(const auto& scene : m_engine->m_kumpulanScene){
            if (scene != nullptr) {
                    // std::cout << "Waduh Bree, ada pointer scene yang kosong melompong nih!" << std::endl;
                    for(const auto& komponen : scene->getKomponen()){
                        if (komponen != nullptr) {
                                m_window.draw(*komponen);
                            }
                            // else {
                            //     std::cout << "Waduh Bree, ada pointer komponen yang kosong melompong nih!" << std::endl;
                            // }
                        // std::cout<<"ngerender komponen1"<<std::endl;
                        // m_window.draw(*komponen);
                        // std::cout<<"ngerender komponen2"<<std::endl;
                    }
                }
        }
        //nnti masuk ke modul input
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                }
                if (keyPressed->code == sf::Keyboard::Key::Escape) {
                    m_window.close();
                }
            }
        }
        m_window.display();
    }
}

void Render::visualize(std::vector<sf::Drawable> komponenDrawable){

}