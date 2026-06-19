// #include "../headers/Engine.hpp"
#include "../include/Engine.hpp"
#include "../include/Render.hpp"
#include "../include/InputHandler.hpp"
#include "../include/SceneManager.hpp"
#include <iostream>

// class Render;
// class SceneManager;
// class InputHandler;

// class Render;

Engine::Engine(sf::Vector2u windowSize)
    : 
    m_windowSize(std::move(windowSize)),
    // m_arenaSize(std::move(arenaSize)),
    m_inputHandler(new InputHandler()),
    m_sceneManager(new SceneManager()),
    m_render(new Render(&m_font))
{
    m_window.create(sf::VideoMode(m_windowSize),"mainPanel");
    m_window.clear(sf::Color::Black);
    m_window.setFramerateLimit(limitFramerate);

    if(!m_font.openFromFile("assets/ds_digital/DS-DIGI.TTF")){
        std::cout<<"gagal"<<std::endl;
    }
    init();
}

// Engine::~Engine(){
// }

void Engine::init(){
    // std::cout<<"ready"<<std::endl;

    m_sceneManager->init(&m_font,&m_window, m_render->getTombolContainerPointer());
    m_render->init(m_sceneManager->m_currentScene, &m_window);
    m_inputHandler->init((m_sceneManager->getCurrentScene()));

    // std::cout << "TEST" << std::endl;
    gameloop();
    // std::cout<<"ENDED"<<std::endl;
}

void Engine::gameloop(){
    while (m_window.isOpen()) {
        m_window.clear(sf::Color::Black);

        //ngedraw komponen
        m_render->visualize();

        //deteksi event
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }

            //lempar input ke modul inpurHandler
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                m_inputHandler->handle(keyPressed->code);
                // if(keyPressed->code==sf::Keyboard::Key::L){
                //     std::cout << "asd" << std::endl;
                // }
            }
        }

        //nampilin window
        m_window.display();
    }
}