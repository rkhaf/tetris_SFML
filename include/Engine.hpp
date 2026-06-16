#pragma once
#include <SFML/Graphics.hpp>
// #include "scenes/startScene.hpp"
// #include "SceneManager.hpp"
#include "structData.hpp"
// #include "InputHandler.hpp"

class Render;
class SceneManager;
class InputHandler;

class Engine{
    public:
    SceneManager* m_sceneManager=nullptr;
    sf::RenderWindow m_window;
    sf::Font m_font;
    
    ~Engine();
    Engine(sf::Vector2u windowSize, sf::Vector2u arenaSize);
    void init();
    void gameloop();

    private:
        sf::Vector2u m_windowSize;
        sf::Vector2i m_arenaSize;
        Render* m_render=nullptr;
        InputHandler* m_inputHandler=nullptr;
        uint8_t limitFramerate=60;
};