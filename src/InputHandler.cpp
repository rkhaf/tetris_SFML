#include "../include/InputHandler.hpp"
#include <iostream>

InputHandler::InputHandler(){

}

InputHandler::~InputHandler(){

}

void InputHandler::handle(sf::Keyboard::Key kunci){
    switch(kunci){
        case sf::Keyboard::Key::A:
            std::cout<<"kiri"<<std::endl;
            break;

        case sf::Keyboard::Key::S:
            std::cout<<"bawah"<<std::endl;
            break;

        case sf::Keyboard::Key::D:
            std::cout<<"kanan"<<std::endl;
            break;

        case sf::Keyboard::Key::Space:
            std::cout<<"spasi"<<std::endl;
            break;

        case sf::Keyboard::Key::Escape:
            std::cout<<"kabur"<<std::endl;
            // m_window.close();
            break;
    }
}