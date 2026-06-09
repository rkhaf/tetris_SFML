#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>


class TombolContainer{
    private:
        int m_currentHovered = 0;
        std::vector<sf::Text*> m_kumpulanTeks;
        std::vector<sf::RectangleShape*> m_kumpulanBg;
        sf::Font* m_font;
        std::vector<std::function<void()>> m_kumpulanLambda;

        int m_characterSize = 64;
        float m_bgOutlineThickness = 2.0f;
        sf::Color m_buttonBg = sf::Color::Black;
        sf::Color m_textColor = sf::Color::White;


    public:
        TombolContainer(sf::Font& font);
        ~TombolContainer();

        void click();
        void geser(char key);
        void generate(sf::Vector2f posisiTombol, sf::Vector2f sizeTombol, const std::string& teks, std::function<void()> action);
        int getSize();
        void updateVisual();
        std::vector<sf::Text*>& getKumpulanTeks();
        std::vector<sf::RectangleShape*>& getKumpulanBg();
};