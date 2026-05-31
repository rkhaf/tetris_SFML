#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    std::vector<std::vector<int>> m_block;
    int m_x, m_y;
    Entity(int x, int y);
    Entity();
    void update();
    void spawn();
};