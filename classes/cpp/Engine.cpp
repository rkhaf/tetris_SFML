#include "../headers/Engine.hpp"

Engine::Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize){
    m_windowSize=windowSize;
    m_arenaSize=arenaSize;
    render = new Render({static_cast<uint16_t>(windowSize.x),static_cast<uint16_t>(windowSize.y)}, 60);
}

void Engine::run(){
    // render->visualize();
    render->start();
    // render->m_currentScene.push_back();
    // render->visualize();
}