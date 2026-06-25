#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include "structData.hpp"
#include "Settings.hpp"

class SceneManager;
class TombolContainer;

class SceneParent{
    protected:
        // sceneDataStruct* m_sceneDataStruct = nullptr;
        sceneStruct m_sceneStruct;
        SceneManager* m_sceneManagerReference = nullptr;

        // sf::RenderWindow* m_window = nullptr;
        // sf::Vector2f m_windowCenter;
    public:
        SceneParent(SceneName sceneName, SceneManager* sceneManager);
        virtual ~SceneParent();
        virtual void init();
        virtual sceneStruct getSceneStruct();
        virtual void createRect(std::string nama, const rectStruct& config);
        virtual void createText(std::string nama, const textStruct& config);
        virtual void createBtn(std::string nama, const tombolStruct& config);
        virtual void createBinds(std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan);
};