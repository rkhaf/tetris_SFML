#pragma once
#include <SFML/Graphics.hpp>

class Tombol{
    private:
        bool m_hovered;
    
    public:
        void click();
        Tombol();
        ~Tombol();
};