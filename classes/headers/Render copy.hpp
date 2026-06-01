#pragma once
#include <SFML/Graphics.hpp>
// #include "Engine.hpp"

class Engine;

class Render{
    private:
        std::vector<std::vector<int>>* m_arenaSolid;
        sf::RectangleShape m_boxVisual;
        sf::Vector2f m_pivotMatriksArena;
        float m_margin;
        Engine* engine;
        std::unordered_map<std::string, sf::Text*> m_kumpulanTeks;
        std::unordered_map<std::string, sf::RectangleShape*> m_kumpulanPanel;
        sf::Vector2f* m_pivotPreview;
    
    public:
        void updateVisual();
        Render();
};