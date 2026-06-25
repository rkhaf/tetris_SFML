#pragma once
#include <SFML/Graphics.hpp>
// #include <iostream>
// #include "Scene.hpp"
#include "structData.hpp"
#include "AudioPlayer.hpp"

#include "scenes/StartScene.hpp"
#include "scenes/ExitConfirmationScene.hpp"
// #include "Render.hpp"

class TombolContainer;

class SceneManager{
    private:
        AudioPlayer m_audioPlayer;
        SceneName m_defaultScene=SceneName::startScene;
        // float m_margin=12.0f;
        sf::RenderWindow* m_window=nullptr;
        // sf::Vector2f buttonStartSize = sf::Vector2f((256.0f * 2), (128.0f * 0.5));
        // float buttonGap = 18.0f;
        sf::Vector2f windowCenter;
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* m_tombolContainer=nullptr;
        sf::Font* m_font = nullptr;
        std::unordered_map<Kontrol, std::vector<std::function<void()>>>* m_currentKeybinds = nullptr;

        // StartScene* test = nullptr;

        // sceneStruct* generateStartScene();
        // sceneStruct* generateExitConfirmationPanel();
        sceneDataStruct m_sceneDataStruct;

        // void createRect(sceneStruct* const sceneStruct,std::string nama, const rectStruct& config);
        // void createText(sceneStruct* const sceneStruct,std::string nama, const textStruct& config);
        // void createBtn(sceneStruct* const sceneStruct,std::string nama, const tombolStruct& config);
        // void createBinds(sceneStruct* const sceneStruct, std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan);

        
    public:
        std::vector<sceneStruct> m_currentScene;
    
        SceneManager();

        void test();
        void changeScene(SceneName targetScene);
        void addScene(SceneName targetScene);
        void popScene();
        sf::Font* getFont();
        AudioPlayer& getAudioPlayer();
        sf::RenderWindow* getRenderWindow();
        std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* getTombolContainerUMap();
        void init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr);
        sceneStruct* getCurrentKeybinds();
        std::vector<sceneStruct>* getCurrentScene();

};