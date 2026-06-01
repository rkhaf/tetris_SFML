#pragma once
#include <SFML/Graphics.hpp>
#include "Render.hpp"

class Engine{
    private:
        sf::Vector2i m_windowSize, m_arenaSize;
        std::vector<Scene*> m_kumpulanScene;
        Render* render;

    public:
        ~Engine();
        Engine(sf::Vector2i windowSize, sf::Vector2i arenaSize);
        void run(); 
};