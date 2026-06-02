#include "../headers/Engine.hpp"
#include "../headers/Render.hpp"

class Render;

Engine::Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize){
    
    m_windowSize=windowSize;
    m_arenaSize=arenaSize;
    render = new Render({static_cast<uint16_t>(windowSize.x),static_cast<uint16_t>(windowSize.y)}, 60, this);
    m_kumpulanScene.resize(2);
    Scene* m_startScene = new startScene();
    m_kumpulanScene[0] = m_startScene;
    // m_kumpulanScene.push_back(m_startScene);
    // m_kumpulanScene[0] = new startScene();
}

Engine::~Engine(){

}

void Engine::run(){
    // render->visualize();
    render->start();
    // render->m_currentScene.push_back();
    // render->visualize();
}