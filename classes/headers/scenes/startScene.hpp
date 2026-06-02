#pragma once
#include "../Scene.hpp"
#include <iostream>

class startScene : public Scene{
    private:
    public:
        ~startScene();
        startScene();
        void createKomponen() override;
        std::vector<sf::Drawable*> getKomponen() override;
};