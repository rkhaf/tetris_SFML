#pragma once
#include <SFML/Graphics.hpp>
// #include <iostream>
// #include "Scene.hpp"
#include "structData.hpp"
// #include "Render.hpp"

class TombolContainer;

class SceneManager{
    private:
        SceneName m_defaultScene=SceneName::startScene;
        float m_margin=12.0f;
        sf::RenderWindow* m_window=nullptr;
        sf::Vector2f buttonStartSize = sf::Vector2f((256.0f * 2), (128.0f * 0.5));
        float buttonGap = 18.0f;
        sf::Vector2f windowCenter;
        std::unique_ptr<TombolContainer>* m_tombolContainer=nullptr;  

        // sceneStruct* 
        void generateStartScene();
        
    public:
        std::vector<sceneStruct*> m_currentScene;
        // Render* m_render=nullptr;
    
        SceneManager();

        void changeScene(SceneName targetScene);
        // void init(sf::RenderWindow* window, TombolContainer* tombolContainer);
        void init(sf::RenderWindow* window, std::unique_ptr<TombolContainer>* tombolContainerPtr);
        std::unordered_map<Kontrol, std::vector<std::function<void()>>>* getCurrentKeybinds();

};