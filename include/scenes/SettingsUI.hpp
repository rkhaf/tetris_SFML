#pragma once
#include "../SceneParent.hpp"
#include <iostream>

class TabContainer;

class SettingsUI : public SceneParent{
    public:
        SettingsUI(SceneName sceneName, SceneManager* sceneManager) : SceneParent(sceneName, sceneManager){}
        ~SettingsUI() = default;
        void init() override;
};