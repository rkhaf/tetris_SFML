// #include "../headers/Engine.hpp"
#include "../include/Engine.hpp"
#include "../include/Render.hpp"
#include <iostream>

class Render;

Engine::Engine(sf::Vector2u windowSize, sf::Vector2u arenaSize)
    : 
    m_windowSize(std::move(windowSize)),
    m_arenaSize(std::move(arenaSize)),
    m_inputHandler(new InputHandler()),
    m_sceneManager(new SceneManager(&m_window)),
    m_render(new Render(&m_font, m_sceneManager->m_currentScene, &m_window))
{
    m_window.create(sf::VideoMode(m_windowSize),"mainPanel");
    m_window.clear(sf::Color::Black);
    m_window.setFramerateLimit(limitFramerate);


    if(!m_font.openFromFile("assets/ds_digital/DS-DIGI.TTF")){
        std::cout<<"gagal"<<std::endl;
    }
}

Engine::~Engine(){

}

void Engine::start(){
    // std::cout<<"ready"<<std::endl;

    

    m_sceneManager->changeScene(SceneName::startScene);
    
    m_render->start();
    m_inputHandler->setTombolPointer(m_render->getTombolContainerPointer());
    gameloop();
}

void Engine::gameloop(){
    while (m_window.isOpen()) {
        m_window.clear(sf::Color::Black);

        //ngedraw komponen

        m_render->visualize();

        //nnti masuk ke modul input
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                m_inputHandler->handle(keyPressed->code);

                // if (keyPressed->code == sf::Keyboard::Key::Space) {
                // }
                // if (keyPressed->code == sf::Keyboard::Key::Escape) {
                //     m_window.close();
                // }
            }
        }
        m_window.display();
    }

}