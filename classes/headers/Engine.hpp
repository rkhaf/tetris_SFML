#pragma once
#include <SFML/Graphics.hpp>
// #include "Render.hpp"
#include "scenes/startScene.hpp"

class Render;

class Engine{
    private:
        sf::Vector2i m_windowSize, m_arenaSize;
        Render* render;
        
        public:
        std::vector<Scene*> m_kumpulanScene;
        // std::vector<Scene> m_kumpulanScene
        ~Engine();
        Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize);
        void run(); 
};