#pragma once
#include <SFML/Graphics.hpp>
// #include "Scene.hpp"
// #include "SceneManager.hpp"
// #include <iostream>
#include "Engine.hpp"
#include "komponent/TombolContainer.hpp"

class Engine;

class Render{
    private:
        std::vector<sceneStruct*>& m_currentScenePointer;
        std::vector<std::unique_ptr<sf::Drawable>> m_komponenScene;
    
        sf::Font* m_font;
        std::unique_ptr<TombolContainer> m_tombolContainer = nullptr;

        sf::RenderWindow* m_window = nullptr;
    
    public:
        ~Render();
        Render(sf::Font* font, std::vector<sceneStruct*>& currentScenePointer, sf::RenderWindow* window);
        void visualize();
        void start();
        TombolContainer& getTombolContainerPointer();
        // void init();
};