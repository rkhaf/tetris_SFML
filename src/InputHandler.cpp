#include "../include/InputHandler.hpp"
#include "../include/komponent/TombolContainer.hpp"
#include <iostream>

InputHandler::InputHandler(){
    // m_signaling[Kontrol::a] = nullptr;
    // m_signaling[Kontrol::s] = nullptr;
    // m_signaling[Kontrol::d] = nullptr;
    // m_signaling[Kontrol::space] = nullptr;
    // m_signaling[Kontrol::esc] = nullptr;

    // m_signaling = new std::unordered_map<Kontrol, std::vector<std::function<void()>>>;

    // (*m_signaling)[Kontrol::kiri].push_back([this](){std::cout<<"a1"<<"\n";});
    // (*m_signaling)[Kontrol::kiri].push_back([this](){std::cout<<"a2"<<"\n";});
    // (*m_signaling)[Kontrol::kiri].push_back([this](){std::cout<<"a3"<<"\n";});

    // (*m_signaling)[Kontrol::bawah].push_back([this](){std::cout<<"s1"<<"\n";});

    // (*m_signaling)[Kontrol::kanan].push_back([this](){std::cout<<"d1"<<"\n";});
    // (*m_signaling)[Kontrol::kanan].push_back([this](){std::cout<<"d2"<<"\n";});
}

InputHandler::~InputHandler(){

}

// void InputHandler::setTombolPointer(TombolContainer& tombolContainer){
//     m_tombolContainerPointer = &tombolContainer;


//     // std::cout<<tombolContainer<<std::endl;
// }

void InputHandler::init(std::unordered_map<Kontrol, std::vector<std::function<void()>>>* keybinds){
    // for(auto& [nama, lambda] : keybinds){
    //     std::cout<<"[INPUTHANDLER] : "<<static_cast<int>(nama)<<std::endl;
    //     m_signaling[nama] = lambda;
    // }
    m_signaling = keybinds;
    // std::cout<<"asd"<<std::endl;
}

void InputHandler::handle(const sf::Keyboard::Key kunci){
    if(m_signaling!=nullptr){//cek validasi m_signaling
        if(m_signaling->find(static_cast<Kontrol>(kunci)) != m_signaling->end()){ //ngecek apkh Kontrol::kunci udh kedaftar
            if(m_signaling->find(static_cast<Kontrol>(kunci))->second.size()>0){ //ngecek apkh size dri vektor tsb lebih dri 1
                for(const std::function<void()>& lambda : m_signaling->find(static_cast<Kontrol>(kunci))->second){ //iterasi vektor
                    if(lambda!=nullptr){ //validasi lambda
                        lambda(); //manggil lambda
                    }
                }
            }
        }
    }
}