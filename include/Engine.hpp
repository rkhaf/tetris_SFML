#pragma once
#include <SFML/Graphics.hpp>
// #include "scenes/startScene.hpp"
#include "SceneManager.hpp"
#include "structData.hpp"

class Render;

class Engine{
    
    public:
    SceneManager* m_sceneManager=nullptr;
    sf::RenderWindow m_window;
    sf::Font m_font;
    
    ~Engine();
    Engine(sf::Vector2u windowSize, sf::Vector2u arenaSize);
    void start();
    void gameloop();
    
    private:
        sf::Vector2u m_windowSize;
        sf::Vector2i m_arenaSize;
        Render* m_render=nullptr;
        uint8_t limitFramerate=60;
};