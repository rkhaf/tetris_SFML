#include "../include/SceneManager.hpp"
#include <iostream>
// #include "../include/Render.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
    :
    m_window(window)
{
    // changeScene(m_defaultScene);
}

void SceneManager::changeScene(SceneName targetScene){
//CEK POINTER


if(m_window!=nullptr){
        switch (targetScene){
            case SceneName::startScene:
                sceneStruct* startScene = new sceneStruct(SceneName::startScene); 
                
    
                startScene->m_kumpulanRect.try_emplace("mainPanel", sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, sf::Vector2f{m_margin, m_margin}, 1.0f, sf::Color::Black, sf::Color::White);

                startScene->m_kumpulanTeks.try_emplace("title", sf::Vector2f{static_cast<float>(m_window->getSize().x / 3.5), 0.0f}, "Tetris", sf::Color::White, 128);
                startScene->m_kumpulanTeks.try_emplace("Main", sf::Vector2f{static_cast<float>(m_window->getSize().x / 2.3), static_cast<float>(startScene->m_kumpulanTeks.at("title").m_sizeKarakter)}, "Main", sf::Color::White, 64);

                // std::cout<<static_cast<float>(m_render->m_window.getSize().x) / 2<<std::endl;
    
                m_currentScene.clear();
                m_currentScene.push_back(startScene);
                // std::cout<<"pushed, sizenow: "<<m_currentScene.size()<<std::endl;
                break;
        }
        // std::cout<<"memory, size: "<<&m_currentScene<<", "<<m_currentScene.size()<<std::endl;
        // std::cout<<"sceneManager, sceneManager: "<<&this<<std::endl;
    }else{
        std::cout<<"windownya kosong"<<std::endl;
    }
}
