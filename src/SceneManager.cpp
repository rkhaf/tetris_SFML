#include "../include/SceneManager.hpp"
#include "../include/TombolContainer.hpp"
#include "../include/TabContainer.hpp"
#include <iostream>

SceneManager::SceneManager()
// m_sceneDataStruct(this)
{
    
}

void SceneManager::init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr, std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* tabContainerPtr){
    registerScenes();
    m_window = window;
    m_font = font;
    windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);
    m_tombolContainer=tombolContainerPtr;
    m_tabContainer=tabContainerPtr;
    // m_sceneDataStruct.m_window = m_window;
    // changeScene(SceneName::startScene);
    addScene(SceneName::startScene);
    m_audioPlayer.playMusic(audioBoard::BGM_menuMusic);
}

void SceneManager::registerScenes(){
    m_sceneFactoryUMap[SceneName::startScene] = [this]() {
        StartScene scene(SceneName::startScene, this);
        scene.init();
        return scene.getSceneStruct();
    };

    m_sceneFactoryUMap[SceneName::exitConfScene] = [this]() {
        ExitConfirmationScene scene(SceneName::exitConfScene, this);
        scene.init();
        return scene.getSceneStruct();
    };

    m_sceneFactoryUMap[SceneName::SettingsUI] = [this]() {
        SettingsUI scene(SceneName::SettingsUI, this);
        scene.init();
        return scene.getSceneStruct();
    };
}

void SceneManager::sendSyncSignal(){
    std::cout << "SIGNAL FIRED" << std::endl;
    for(const auto& lambda : m_syncSceneSignal){
        lambda();
    }
}


//ngeclear seluruh scene, nambahin yg baru
void SceneManager::changeScene(SceneName targetScene){
    if (m_window == nullptr) return;
    auto it = m_sceneFactoryUMap.find(targetScene);
    
    if (it != m_sceneFactoryUMap.end()) {
        m_currentScene.clear();
        m_currentScene.push_back(it->second()); 
    }
    // std::cout << "TEST" << std::endl;
    sendSyncSignal();
}


//numpuk scene diatas
void SceneManager::addScene(SceneName targetScene){

    if (m_window == nullptr) return;
    auto it = m_sceneFactoryUMap.find(targetScene);
    
    if (it != m_sceneFactoryUMap.end()) {
        m_currentScene.push_back(it->second()); 
    }
    sendSyncSignal();
}

void SceneManager::popScene(){
    if(!m_currentScene.empty()){
        m_currentScene.pop_back();
    }
    sendSyncSignal();
}

//buat ngambil keybinds yang berlaku di scene yg lagi difokusin
sceneStruct* SceneManager::getCurrentKeybinds(){

    if(!m_currentScene.empty()){  
        return &m_currentScene.back();
    }
    return nullptr;
}

std::vector<sceneStruct>* SceneManager::getCurrentScene(){
    return &m_currentScene;
}

std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* SceneManager::getTombolContainerUMap(){
    return m_tombolContainer;
}

std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* SceneManager::getTabContainerUMap(){
    return m_tabContainer;
}

sf::Font* SceneManager::getFont(){
    return m_font;
}

AudioPlayer& SceneManager::getAudioPlayer(){
    return m_audioPlayer;
}

sf::RenderWindow* SceneManager::getRenderWindow(){
    return m_window;
}
