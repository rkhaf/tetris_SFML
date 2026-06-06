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

        // sceneStruct* 
        
    public:
        std::vector<sceneStruct*> m_currentScene;
        // Render* m_render=nullptr;
    
    void changeScene(SceneName targetScene);
    SceneManager(sf::RenderWindow* window);

};