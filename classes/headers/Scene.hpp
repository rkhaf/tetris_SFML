#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Scene{
    protected:
        std::vector<sf::Drawable*> m_allKomponen;
    
    public:
        Scene(){};
        virtual ~Scene(){};
        
        virtual void createKomponen();
        virtual std::vector<sf::Drawable*> getKomponen();

};