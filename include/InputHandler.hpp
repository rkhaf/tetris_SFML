#pragma once
#include <SFML/Graphics.hpp>
// #include "komponent/TombolContainer.hpp"
#include "structData.hpp"
#include <map>

class TombolContainer;

class InputHandler{
    private:
        TombolContainer* m_tombolContainerPointer = nullptr;

        std::unordered_map<Kontrol, std::vector<std::function<void()>>>* m_signaling;
        

    public:
        // InputHandler(std::unique_ptr<TombolContainer>& tombolContainer);
        InputHandler();
        ~InputHandler();

        void handle(sf::Keyboard::Key kunci);
        // void setTombolPointer(TombolContainer& m_tombolContainer);
        void init(std::unordered_map<Kontrol, std::vector<std::function<void()>>>* keybinds);
};