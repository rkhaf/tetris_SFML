#pragma once
#include <SFML/Graphics.hpp>

enum class Kontrol : uint8_t{
    kiri = 0,
    kanan = 1,
    bawah = 2,
    rotateKiri = 3,
    rotateKanan = 4,
    keluar = 5
};

class InputHandler{
    private:
    public:
        InputHandler();
        ~InputHandler();
        void handle(sf::Keyboard::Key kunci);

};