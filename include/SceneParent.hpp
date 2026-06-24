#pragma once
#include <SFML/Graphics.hpp>
#include "structData.hpp"

class AudioPlayer;
class TombolContainer;

class SceneParent{
    protected:
        sceneStruct m_scene;
        sceneDataStruct* m_dataScene;

    public:
        SceneParent();
        virtual ~SceneParent();
        virtual void init(sceneDataStruct* dataScene);
        virtual sceneStruct& getStruct();

        virtual void createRect(std::string nama, const rectStruct& config);
        virtual void createText(std::string nama, const textStruct& config);
        virtual void createBtn(std::string nama, const tombolStruct& config);
        virtual void createBinds( std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan);
};