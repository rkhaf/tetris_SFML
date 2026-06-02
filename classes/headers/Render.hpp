#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
// #include "Engine.hpp"

class Engine;

class Render{
    private:
        sf::RenderWindow m_window;
        Engine* m_engine=nullptr;
        
    public:
        ~Render();
        std::vector<Scene*> m_currentScene;
        Render(sf::Vector2u windowSize, int limitFramerate, Engine* engine);
        void visualize(std::vector<sf::Drawable> komponenDrawable);
        void start();
};