#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
// #include <string>

//Engine(sf::Vector2u size, std::string name);
class Engine{
    private:
        // Gunakan pointer agar properti ini bisa menyimpan alamat window utama
        sf::Vector2u m_size;
        std::string m_panelName;
        Scene* m_gameScene;
        sf::Font m_font;
        int m_frameRate;
        sf::RenderWindow m_window;
        sf::Clock m_interval;


    public:
        int m_skor, m_blockPlaced, m_interval_timeout;
        Engine(sf::Vector2u size, std::string name, Scene* gameScene);
        sf::RenderWindow* getWindow();

        void update(float dt);
        void draw(); // Tidak perlu oper window lagi saat draw, karena scene sudah tahu windownya
        void run();
        bool cekValidBaris(int baris, std::vector<std::vector<int>>* arena);
        void clearBaris(int baris);
};