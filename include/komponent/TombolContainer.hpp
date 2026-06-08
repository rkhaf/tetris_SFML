#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class TombolContainer{
    private:
        int m_currentHovered = 0;
        std::vector<sf::Text*> m_kumpulanTeks;
        std::vector<sf::RectangleShape*> m_kumpulanBg;
        sf::Font* m_font;

        int m_characterSize = 64;
        sf::Color m_buttonBg = sf::Color::Blue;
        sf::Color m_textColor = sf::Color::White;


    public:
        TombolContainer(sf::Font& font);
        ~TombolContainer();

        void click();
        void geser(char key);
        void generate(sf::Vector2f posisiTombol, sf::Vector2f sizeTombol, const std::string& teks);
        int getSize();
        void updateVisual();
        std::vector<sf::Text*>& getKumpulanTeks();
        std::vector<sf::RectangleShape*>& getKumpulanBg();
};