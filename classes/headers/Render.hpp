#pragma once
#include <SFML/Graphics.hpp>
// #include "Scene.hpp"
#include "SceneManager.hpp"
// #include <iostream>
#include "Engine.hpp"

class Engine;

class Render{
    private:
    // Engine* m_engine=nullptr;
    // SceneManager* m_sceneManager=nullptr;
    Engine* m_engine=nullptr;
    std::vector<std::unique_ptr<sf::Drawable>> m_komponenScene;
    
    public:
        sf::RenderWindow m_window;
        ~Render();
        // std::vector<Scene*> m_currentScene;
        // Render(sf::Vector2u windowSize, int limitFramerate, Engine* engine);
        Render(sf::Vector2u windowSize, int limitFramerate, SceneManager* sceneManager, Engine* engine);
        void visualize(std::vector<sf::Drawable> komponenDrawable);
        void start();
        void init();
};