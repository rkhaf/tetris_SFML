#pragma once
#include <SFML/Graphics.hpp>
#include "komponent/TombolContainer.hpp"

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
        TombolContainer* m_tombolContainerPointer = nullptr;

    public:
        // InputHandler(std::unique_ptr<TombolContainer>& tombolContainer);
        InputHandler();
        ~InputHandler();

        void handle(sf::Keyboard::Key kunci);
        void setTombolPointer(TombolContainer& m_tombolContainer);
};