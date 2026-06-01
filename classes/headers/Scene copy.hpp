#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Entity.hpp"
#include <set>

class Scene {
private:
    int m_skor, m_blockPlaced;
    // int m_interval_timeout;
    // std::vector<std::vector<int>> m_arenaSolid;
    std::vector<std::vector<int>> m_arena;
    // std::vector<std::vector<int>>* m_currentBlock;
    // std::vector<std::vector<int>>* m_normalizedCurrentBlock;
    // std::set<std::pair<int, int>> m_normalizedCurrentBlock;
    sf::Vector2f* m_pivotPreview;
    // sf::Vector2i pivot_currentBlock;
    // Entity m_currentBlock;
    
    public:
    sf::Clock* m_interval;
    std::string m_nama;
    // sf::Vector2i m_ukuranMatriks;
    // sf::RectangleShape m_boxVisual;
    // sf::Vector2f m_pivotMatriks;
    sf::RenderWindow* m_window=nullptr;
    sf::RectangleShape panel;
    sf::RectangleShape panelPreview;
    sf::Font* m_font=nullptr;
    // sf::Vector2i pivotBlock;
    // std::unordered_map<std::string, sf::Text*> m_kumpulanTeks;
    // sf::Text* m_skorLabel;
    // float m_margin;
    // int m_ketinggianBlock, m_blok_kosong, m_blok_solid, m_blok_controlled, m_blok_debug;
    Scene(std::string nama,sf::Vector2i ukuran);

    void update();
    void start();
    // void spawn();
    // void jatuh();
    // void place();
    // std::pair<int, int> normalKeMatriks(std::pair<int, int> normalKordinat, sf::Vector2i* pivotMatriks);
    // std::pair<int, int> matriksKeNormal(std::pair<int, int> matriksKordinat, std::pair<int, int> pivotMatriks);
    void updatePosisiBlock();
    bool cekGeser(const char arah[5]);
    // void geser(const char arah[5]);
    bool cekValidBaris(int baris);
    void clearBaris(int baris);
};