#pragma once
#include <SFML/Graphics.hpp>
#include <set>
#include "Scene.hpp"
#include "Render.hpp"
// #include <string>

//Engine(sf::Vector2u size, std::string name);
class Engine{
    private:
        // Gunakan pointer agar properti ini bisa menyimpan alamat window utama
        sf::Vector2u m_size;
        std::string m_panelName;
        Scene* m_gameScene;
        Render* m_renderEngine;
        int m_frameRate;
        
        public:
        sf::Clock m_interval;
        sf::Font m_font;
        sf::RenderWindow m_window;
        int m_skor, m_blockPlaced, m_ketinggianBlock, m_blok_kosong, m_blok_solid, m_blok_controlled, m_blok_debug, m_interval_timeout;
        std::vector<std::vector<int>> m_arenaSolid;
        sf::Vector2i m_ukuranMatriks;
        std::set<std::pair<int, int>> m_normalizedCurrentBlock;
        sf::Vector2i pivotBlock;
        std::vector<std::vector<int>>* m_currentBlock;
        sf::Vector2i pivot_currentBlock;

        
        Engine(sf::Vector2u size, Scene* gameScene, Render* renderEngine, sf::Vector2i arenaSize);
        sf::RenderWindow* getWindow();

        void update(float dt);
        void draw(); // Tidak perlu oper window lagi saat draw, karena scene sudah tahu windownya
        void run();
        bool cekValidBaris(int baris);
        void clearBaris(int baris);
        bool cekGeser(const char arah[5]);
        void geser(const char arah[5]);
        void spawn();
        void jatuh();
        void place();
        void updatePosisiBlock();
        void start();
        std::pair<int, int> normalKeMatriks(std::pair<int, int> normalKordinat, sf::Vector2i* pivotMatriks);
        std::pair<int, int> matriksKeNormal(std::pair<int, int> matriksKordinat, std::pair<int, int> pivotMatriks);
};