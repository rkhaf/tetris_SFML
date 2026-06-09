#include "../include/SceneManager.hpp"
#include <iostream>
// #include "../include/Render.hpp"

SceneManager::SceneManager(sf::RenderWindow* window)
    :
    m_window(window)
{
}

void SceneManager::start(){
    windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);
}

void SceneManager::changeScene(SceneName targetScene){
//CEK POINTER

if(m_window!=nullptr){
        switch (targetScene){
            case SceneName::startScene:
                generateStartScene();
                break;
        }
    }else{
        std::cout<<"windownya kosong"<<std::endl;
    }
}

void SceneManager::generateStartScene(){
    sceneStruct* startScene = new sceneStruct(SceneName::startScene);

    //create komponen
    startScene->m_kumpulanRect.try_emplace("mainPanel", 
        sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, 
        sf::Vector2f{m_margin, m_margin}, 
        1.0f, sf::Color::Black, 
        sf::Color::White
    );

    startScene->m_kumpulanTeks.try_emplace("title", 
        sf::Vector2f{static_cast<float>(m_window->getSize().x / 3.5), 0.0f}, 
        "Tetris", 
        sf::Color::White,
        150
    );

    //create tombol
    startScene->m_kumpulanTombol.try_emplace("exit", 
        sf::Vector2f{static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 2))}, 
        sf::Vector2f{buttonStartSize},
        "Keluar",
        [this]() { std::cout<<"keluar"<<std::endl; }
    );

    startScene->m_kumpulanTombol.try_emplace("settings", 
        sf::Vector2f{static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 1))}, 
        sf::Vector2f{buttonStartSize},
        "Pengaturan",
        [this]() { std::cout<<"masuk ke setings"<<std::endl; }
    );

    startScene->m_kumpulanTombol.try_emplace("play", 
        sf::Vector2f{static_cast<float>(m_window->getSize().x / 2), static_cast<float>(m_window->getSize().y / 2)}, 
        sf::Vector2f{buttonStartSize},
        "Main",
        [this]() { std::cout<<"ayo main yuk"<<std::endl; }
    );

    //setting keybinds
    startScene->m_keybinds[Kontrol::a] = [this](){std::cout<<"woilah"<<std::endl;};


    m_currentScene.clear();
    m_currentScene.push_back(startScene);
}