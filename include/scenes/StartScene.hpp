#pragma once
#include "../SceneParent.hpp"
#include <iostream>

class StartScene : public SceneParent{
    public:
        StartScene(SceneName sceneName, SceneManager* sceneManager) : SceneParent(sceneName, sceneManager){}
        ~StartScene() = default;
        void init() override;
};