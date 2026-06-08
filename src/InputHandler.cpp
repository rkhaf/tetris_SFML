#include "../include/InputHandler.hpp"
#include <iostream>

InputHandler::InputHandler(){

}

InputHandler::~InputHandler(){

}

void InputHandler::setTombolPointer(TombolContainer& tombolContainer){
    m_tombolContainerPointer = &tombolContainer;


    // std::cout<<tombolContainer<<std::endl;
}

void InputHandler::handle(const sf::Keyboard::Key kunci){
    switch(kunci){
        case sf::Keyboard::Key::A:
            m_tombolContainerPointer->geser('a');
            // std::cout<<"kiri"<<std::endl;
            break;

        case sf::Keyboard::Key::S:
            // std::cout<<"bawah"<<std::endl;
            break;

        case sf::Keyboard::Key::D:
            m_tombolContainerPointer->geser('d');
            // std::cout<<"kanan"<<std::endl;
            break;

        case sf::Keyboard::Key::Space:
            m_tombolContainerPointer->click();
            // std::cout<<"spasi"<<std::endl;
            break;

        case sf::Keyboard::Key::Escape:
            // std::cout<<"kabur"<<std::endl;
            // m_window.close();
            break;
    }
}