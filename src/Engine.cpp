// #include "../headers/Engine.hpp"
#include "../include/Engine.hpp"
#include "../include/Render.hpp"
#include <iostream>

class Render;

Engine::Engine(sf::Vector2u windowSize, sf::Vector2u arenaSize)
    : 
    m_windowSize(windowSize),
    m_arenaSize(arenaSize),
    m_sceneManager(new SceneManager(&m_window)),
    m_render(new Render(this))
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
    // m_sceneManager->m_window=&m_render->m_window;
    // m_sceneManager->m_render=m_render;

    gameloop();
    // render->visualize();
    // std::cout<<"engine, memory sceneManager: "<<&m_sceneManager<<std::endl;
    // m_render->init();
    // render->m_currentScene.push_back();
    // render->visualize();
}

void Engine::gameloop(){
    while (m_window.isOpen()) {
        m_window.clear(sf::Color::Black);

        //ngedraw komponen, hrusnya modul render
        // for(const auto& komponen : m_komponenScene){
        //     m_window.draw(*komponen);
        //     // std::cout<<"found"<<std::endl;
        // }
        m_render->visualize();

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