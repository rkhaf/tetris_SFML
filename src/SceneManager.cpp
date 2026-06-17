#include "../include/SceneManager.hpp"
#include "../include/komponent/TombolContainer.hpp"
#include <iostream>

SceneManager::SceneManager()
    // :
    // m_window(window)
{
}

void SceneManager::init(sf::RenderWindow* window, std::unique_ptr<TombolContainer>* tombolContainerPtr){
    m_window = window;
    windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);
    m_tombolContainer=tombolContainerPtr;
    changeScene(SceneName::startScene);
}


//ngeclear seluruh scene, nambahin yg baru
void SceneManager::changeScene(SceneName targetScene){
    //CEK POINTER
    if(m_window!=nullptr){
        m_currentScene.clear();
        switch (targetScene){
            case SceneName::startScene:
                generateStartScene();
                break;
        }
    }else{
        std::cout<<"windownya kosong"<<std::endl;
    }
}

void SceneManager::addScene(SceneName targetScene){
    if(m_window!=nullptr){
        switch (targetScene){
            case SceneName::startScene:
                generateStartScene();
                break;

            case SceneName::exitConfScene:
                generateExitConfirmationPanel();
                break;
        }
    }else{
        std::cout<<"windownya kosong"<<std::endl;
    }
    
}

void SceneManager::generateStartScene(){
    sceneStruct* startScene = new sceneStruct(SceneName::startScene);

    //create panel
    startScene->m_kumpulanRect.try_emplace("mainPanel", 
        sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, 
        sf::Vector2f{m_margin, m_margin}, 
        1.0f, sf::Color::Black, 
        sf::Color::White
    );

    //create teks
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
        // [this]() { std::cout<<"keluar"<<std::endl; }
        [this]() { addScene(SceneName::exitConfScene);}
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
        "Main"
        ,
        [this]() { std::cout<<"ayo main yuk"<<std::endl;}
    );

    //setting keybinds
    startScene->m_keybinds[Kontrol::kiri].push_back([this](){m_tombolContainer->get()->geser(Kontrol::kiri);});
    startScene->m_keybinds[Kontrol::kanan].push_back([this](){m_tombolContainer->get()->geser(Kontrol::kanan);});
    startScene->m_keybinds[Kontrol::drop].push_back([this](){m_tombolContainer->get()->click();});

    m_currentScene.push_back(startScene);
    getCurrentKeybinds();
}

void SceneManager::generateExitConfirmationPanel(){
    sceneStruct* exitConfPanel = new sceneStruct(SceneName::exitConfScene);

    exitConfPanel->m_kumpulanRect.try_emplace("exitPanel", 
        // sf::Vector2f{(m_window->getSize().x + 12.0f) / 2.0f, m_window->getSize().y / 2.0f}, 
        sf::Vector2f{m_window->getSize().x - (m_margin * 8), m_window->getSize().y - (m_margin * 8)},
        sf::Vector2f{m_margin * 4, m_margin * 4}, 
        1.0f, sf::Color::Blue, 
        sf::Color::White
    );

    m_currentScene.push_back(exitConfPanel);
    std::cout << "yea" << m_currentScene.size() << std::endl;
}

//buat ngambil keybinds yang berlaku di scene yg lagi difokusin
std::unordered_map<Kontrol, std::vector<std::function<void()>>>* SceneManager::getCurrentKeybinds(){
    if(!m_currentScene.empty()){
        std::cout << "asd" << std::endl;
        return &(m_currentScene.back()->m_keybinds);
    }
    return nullptr;
}