#pragma once
#include <SFML/Graphics.hpp>
#include <map>
// #include "Scene.hpp"
// #include "SceneManager.hpp"
// #include <iostream>
// #include "Engine.hpp"
// #include "komponent/TombolContainer.hpp"
// #include "InputHandler.hpp"
#include "structData.hpp"

// class Engine;
class TombolContainer;

class Render{
    private:
        std::vector<sceneStruct>* m_currentScenePointer = nullptr;
        // std::vector<std::unique_ptr<sf::Drawable>> m_komponenScene;
        std::map<SceneName, std::vector<std::unique_ptr<sf::Drawable>>> m_komponenScene;
        
    
        sf::Font* m_font = nullptr;
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>> m_tombolContainer;

        sf::RenderWindow* m_window = nullptr;
        int m_currentSceneSize = 0;
        
    public:
        // ~Render();
        Render(sf::Font* font);
        void visualize();
        void setup();
        void init(std::vector<sceneStruct>& currentScenePointer, sf::RenderWindow* window);

        // TombolContainer& getTombolContainerPointer();
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* getTombolContainerPointer();
        // void init();
};