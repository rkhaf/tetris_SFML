#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <algorithm>
#include "structData.hpp"
#include "Settings.hpp"


class TabContainer{
    private:
        // int m_currentHovered = 0;
        tabContainerStruct* m_tabContainerReference = nullptr;

        //opsi - subopsi
        sf::Vector2i m_currentHovered = sf::Vector2i(0, 0);
        std::vector<std::unique_ptr<sf::Text>> m_opsiTeks;
        std::vector<std::unique_ptr<sf::RectangleShape>> m_opsiBg;
        std::unordered_map<std::string, std::vector<std::unique_ptr<sf::Text>>> m_subOpsiTeks;
        // std::vector<std::unique_ptr<sf::Text>> m_subOpsiTeks;
        sf::Font* m_font;

        //nama_opsi, vektor subopsi
        std::unordered_map<std::string, std::vector<std::function<void()>>> m_lambdaSubopsi;

        int m_characterSize = 64;
        float m_bgOutlineThickness = 2.0f;
        sf::Color m_buttonBg = sf::Color::Black;
        sf::Color m_textColor = sf::Color::White;


    public:
        sf::Vector2f m_pivot = sf::Vector2f(0.0f, 0.0f);
        TabContainer(sf::Font& font, tabContainerStruct* tabContainerStruct, sf::Vector2f pivot);
        // ~TombolContainer();

        void click();
        void geser(Kontrol key);
        void generate();
        int getSize();
        void updateVisual();
        void resetContainer();
        sf::Vector2i& getCurrentHovered();
        std::vector<std::unique_ptr<sf::Text>>& getKumpulanTeks();
        std::vector<std::unique_ptr<sf::RectangleShape>>& getKumpulanBg();
        std::unordered_map<std::string, std::vector<std::unique_ptr<sf::Text>>>& getKumpulanSubOpsiTeks();
};