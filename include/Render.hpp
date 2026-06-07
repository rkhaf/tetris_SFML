#pragma once
#include <SFML/Graphics.hpp>
// #include "Scene.hpp"
#include "SceneManager.hpp"
// #include <iostream>
#include "Engine.hpp"

class Engine;

class Render{
    private:
        std::vector<sceneStruct*>& m_currentScenePointer;
        Engine* m_engine=nullptr;
        std::vector<std::unique_ptr<sf::Drawable>> m_komponenScene;
        sf::RenderWindow* m_window = nullptr;
    
    public:
        ~Render();
        Render(Engine* engine, std::vector<sceneStruct*>& currentScenePointer, sf::RenderWindow* window);
        void visualize();
        void start();
        // void init();
};