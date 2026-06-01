#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class Render{
    private:
        sf::RenderWindow m_window;
        
    public:
        ~Render();
        std::vector<Scene*> m_currentScene;
        Render(sf::Vector2u windowSize, int limitFramerate);
        void visualize(std::vector<sf::Drawable> komponenDrawable);
        void start();
};