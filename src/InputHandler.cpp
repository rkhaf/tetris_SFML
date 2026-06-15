#include "../include/InputHandler.hpp"
#include <iostream>

InputHandler::InputHandler(){
    m_signaling[Kontrol::a] = nullptr;
    m_signaling[Kontrol::s] = nullptr;
    m_signaling[Kontrol::d] = nullptr;
    m_signaling[Kontrol::space] = nullptr;
    m_signaling[Kontrol::esc] = nullptr;
}

InputHandler::~InputHandler(){

}

void InputHandler::setTombolPointer(TombolContainer& tombolContainer){
    m_tombolContainerPointer = &tombolContainer;


    // std::cout<<tombolContainer<<std::endl;
}

void InputHandler::assign(std::unordered_map<Kontrol, std::function<void()>>& keybinds){
    // for(auto& [nama, lambda] : keybinds){
    //     std::cout<<"[INPUTHANDLER] : "<<static_cast<int>(nama)<<std::endl;
    //     m_signaling[nama] = lambda;
    // }
    m_signaling = keybinds;
    // std::cout<<"asd"<<std::endl;
}

void InputHandler::handle(const sf::Keyboard::Key kunci){
    switch(kunci){
        case sf::Keyboard::Key::A:
            // m_tombolContainerPointer->geser('a');
            if(m_signaling[Kontrol::a]!=nullptr){
                m_signaling[Kontrol::a]();
            }

            // std::cout<<"kiri"<<std::endl;
            break;

        case sf::Keyboard::Key::S:
            // std::cout<<"bawah"<<std::endl;
            if(m_signaling[Kontrol::s]!=nullptr){
                m_signaling[Kontrol::s]();
            }
            break;

        case sf::Keyboard::Key::D:
            // m_tombolContainerPointer->geser('d');
            if(m_signaling[Kontrol::d]!=nullptr){
                m_signaling[Kontrol::d]();
            }
            break;

        case sf::Keyboard::Key::Space:
            // m_tombolContainerPointer->click();
            if(m_signaling[Kontrol::space]!=nullptr){
                m_signaling[Kontrol::space]();
            }
            // std::cout<<"spasi"<<std::endl;
            break;

        case sf::Keyboard::Key::Escape:
            if(m_signaling[Kontrol::esc]!=nullptr){
                m_signaling[Kontrol::esc]();
            }
            // std::cout<<"kabur"<<std::endl;
            // m_window.close();
            break;
    }
}