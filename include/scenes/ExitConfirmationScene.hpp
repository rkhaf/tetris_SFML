#pragma once
#include "../SceneParent.hpp"
#include <iostream>

class ExitConfirmationScene : public SceneParent{
    public:
        ExitConfirmationScene(SceneName sceneName, SceneManager* sceneManager) : SceneParent(sceneName, sceneManager){}
        ~ExitConfirmationScene() = default;
        void init() override;
};