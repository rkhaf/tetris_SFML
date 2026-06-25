#include "../include/SceneManager.hpp"
#include "../include/TombolContainer.hpp"
#include <iostream>

SceneManager::SceneManager()
// m_sceneDataStruct(this)
{
    
}

void SceneManager::init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr){
    registerScenes();
    m_window = window;
    m_font = font;
    windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);
    m_tombolContainer=tombolContainerPtr;
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
}


//ngeclear seluruh scene, nambahin yg baru
void SceneManager::changeScene(SceneName targetScene){
    //CEK POINTER
    if(m_window!=nullptr){
        m_currentScene.clear();
        switch (targetScene){
            case SceneName::startScene:
                // generateStartScene();
                break;
        }
    }
}


//numpuk scene diatas
void SceneManager::addScene(SceneName targetScene){
if (m_window == nullptr) return;

    auto it = m_sceneFactoryUMap.find(targetScene);
    
    if (it != m_sceneFactoryUMap.end()) {
        m_currentScene.push_back(it->second()); 
    }



    // if(m_window!=nullptr){
    //     switch (targetScene){
    //         case SceneName::startScene:{
    //             StartScene newStartScene(SceneName::startScene, this);
    //             newStartScene.init();
    //             m_currentScene.push_back(newStartScene.getSceneStruct());
    //             break;
    //         }

    //         case SceneName::exitConfScene:{
    //             ExitConfirmationScene newExitConfScene(SceneName::exitConfScene, this);
    //             newExitConfScene.init();
    //             m_currentScene.push_back(newExitConfScene.getSceneStruct());
    //             break;
    //         }
    //     }
    // }
}

void SceneManager::popScene(){
    if(!m_currentScene.empty()){
        m_currentScene.pop_back();
    }
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

sf::Font* SceneManager::getFont(){
    return m_font;
}

AudioPlayer& SceneManager::getAudioPlayer(){
    return m_audioPlayer;
}

sf::RenderWindow* SceneManager::getRenderWindow(){
    return m_window;
}
