#include "../include/InputHandler.hpp"
#include "../include/TombolContainer.hpp"
#include <iostream>

InputHandler::InputHandler(){
}

// InputHandler::~InputHandler(){

// }
void InputHandler::init(std::vector<sceneStruct>* currentScene){
    m_currentScenes = currentScene;
}

void InputHandler::handle(const sf::Keyboard::Key kunci){
    if(m_currentScenes!=nullptr){ ///ngecek apkh ptrnya valid
        if(!m_currentScenes->empty()){ //ngecek apkh ada isinya
            m_signaling = &(m_currentScenes->back()).m_keybinds;
            // m_currentScenes->back().m_keybinds
        }
    }

    
    // std::vector<std::function<void ()>> std::pair<const Kontrol, std::vector<std::function<void ()>>>* safecopyLambda = m_signaling->find(static_cast<Kontrol>(kunci))->second;

    if(m_signaling!=nullptr){//cek validasi m_signaling
        if(m_signaling->find(static_cast<Kontrol>(kunci)) != m_signaling->end()){ //ngecek apkh Kontrol::kunci udh kedaftar
            if(m_signaling->find(static_cast<Kontrol>(kunci))->second.size()>0){ //ngecek apkh size dri vektor tsb lebih dri 1
                auto safecopyy = m_signaling->find(static_cast<Kontrol>(kunci))->second;
                for(const std::function<void()>& lambda : safecopyy){ //iterasi vektor
                // for(const std::function<void()>& lambda : m_signaling->find(static_cast<Kontrol>(kunci))->second){ //iterasi vektor
                    if(lambda!=NULL){ //validasi lambda
                        // std::cout << "TEST" << std::endl;
                        lambda(); //manggil lambda
                        // return;
                    }
                }
            }
        }
    }
}