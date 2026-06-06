#include "../headers/Engine.hpp"
#include "../headers/Render.hpp"
#include <iostream>

class Render;

Engine::Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize)
    : 
    m_windowSize(windowSize),
    m_arenaSize(arenaSize),
    m_sceneManager(new SceneManager()),
    m_render(new Render({static_cast<uint16_t>(windowSize.x), static_cast<uint16_t>(windowSize.y)}, 60, m_sceneManager, this))
{
    if(!m_font.openFromFile("assets/ds_digital/DS-DIGI.TTF")){
        std::cout<<"gagal"<<std::endl;
    }
}

Engine::~Engine(){

}

void Engine::run(){
    // render->visualize();
    // std::cout<<"engine, memory sceneManager: "<<&m_sceneManager<<std::endl;
    m_sceneManager->m_render=m_render;
    m_sceneManager->changeScene(SceneName::startScene);
    m_render->init();
    m_render->start();
    // render->m_currentScene.push_back();
    // render->visualize();
}