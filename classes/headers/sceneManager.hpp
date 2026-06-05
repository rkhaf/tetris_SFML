#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

class SceneManager{
    private:
        std::vector<Scene> m_kumpulanScene;

    public:
        enum class SceneName{
            startScene
        };
        void changeScene();
        SceneManager();
};