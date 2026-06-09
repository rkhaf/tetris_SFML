#pragma once
#include <SFML/Graphics.hpp>
// #include <iostream>
// #include "Scene.hpp"
#include "structData.hpp"
// #include "Render.hpp"

// class Render;

class SceneManager{
    private:
        SceneName m_defaultScene=SceneName::startScene;
        float m_margin=12.0f;
        sf::RenderWindow* m_window=nullptr;
        sf::Vector2f buttonStartSize = sf::Vector2f((256.0f * 2), (128.0f * 0.5));
        float buttonGap = 18.0f;
        sf::Vector2f windowCenter;

        // sceneStruct* 
        
    public:
        std::vector<sceneStruct*> m_currentScene;
        // Render* m_render=nullptr;
    
        SceneManager(sf::RenderWindow* window);

        void changeScene(SceneName targetScene);
        void generateStartScene();
        void start();

};