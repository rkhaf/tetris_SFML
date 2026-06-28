#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
// #include <iostream>
// #include "Scene.hpp"
#include "structData.hpp"
#include "AudioPlayer.hpp"

#include "scenes/StartScene.hpp"
#include "scenes/ExitConfirmationScene.hpp"
#include "scenes/SettingsUI.hpp"
// #include "Render.hpp"

class TombolContainer;
class TabContainer;

class SceneManager{
    private:
        AudioPlayer m_audioPlayer;
        sf::Font* m_font = nullptr;
        SceneName m_defaultScene=SceneName::startScene;

        sf::RenderWindow* m_window=nullptr;
        sf::Vector2f windowCenter;

        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* m_tombolContainer=nullptr;
        std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* m_tabContainer=nullptr;
        std::unordered_map<Kontrol, std::vector<std::function<void()>>>* m_currentKeybinds = nullptr;
        std::unordered_map<SceneName, std::function<sceneStruct()>> m_sceneFactoryUMap;

        
        // sceneDataStruct m_sceneDataStruct;
        
        public:
        std::vector<std::function<void()>> m_syncSceneSignal;
        std::vector<sceneStruct> m_currentScene;
    
        SceneManager();

        void changeScene(SceneName targetScene);
        void addScene(SceneName targetScene);
        void popScene();
        void registerScenes();
        void sendSyncSignal();
        sf::Font* getFont();
        AudioPlayer& getAudioPlayer();
        sf::RenderWindow* getRenderWindow();
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* getTombolContainerUMap();
        std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* getTabContainerUMap();

        void init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr, std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* tabContainerPtr);
        sceneStruct* getCurrentKeybinds();
        std::vector<sceneStruct>* getCurrentScene();

};