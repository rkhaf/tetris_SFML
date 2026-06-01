#pragma once
#include <SFML/Graphics.hpp>

class Scene{
    private:
        std::vector<sf::Drawable*> m_allKomponen;
    public:
        Scene();
        virtual ~Scene();
        
        virtual void createKomponen();
        virtual void getKomponen();

};