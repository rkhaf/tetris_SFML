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
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* m_tombolContainer=nullptr;  
        sf::Font* m_font;
        std::unordered_map<Kontrol, std::vector<std::function<void()>>>* m_currentKeybinds = nullptr;


        // sceneStruct* 
        void updateCurrentBindings();
        void generateStartScene();
        void generateExitConfirmationPanel();

        
    public:
        std::vector<sceneStruct*> m_currentScene;
        // Render* m_render=nullptr;
    
        SceneManager();

        void changeScene(SceneName targetScene);
        void addScene(SceneName targetScene);
        // void updateBindings();
        // void init(sf::RenderWindow* window, TombolContainer* tombolContainer);
        void init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr);
        // std::unordered_map<Kontrol, std::vector<std::function<void()>>>* getCurrentKeybinds();
        sceneStruct* getCurrentKeybinds();

};