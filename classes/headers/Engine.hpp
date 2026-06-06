#pragma once
#include <SFML/Graphics.hpp>
// #include "scenes/startScene.hpp"
#include "SceneManager.hpp"
#include "structData.hpp"

class Render;

class Engine{
    private:
        sf::Vector2i m_windowSize;
        sf::Vector2i m_arenaSize;
        Render* m_render=nullptr;
        
        public:
        SceneManager* m_sceneManager=nullptr;
        sf::Font m_font;

        ~Engine();
        Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize);
        void run(); 
};