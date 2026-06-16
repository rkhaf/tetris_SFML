#include "../include/Render.hpp"
#include <iostream>
// #include "../include/Engine.hpp"
#include "../include/komponent/TombolContainer.hpp"

Render::Render(sf::Font* font)
: m_font(font)
{
    m_tombolContainer = std::make_unique<TombolContainer>(*m_font);

}

Render::~Render() = default;

// void Render::TESTKEYBINDS(){
//     if(m_currentScenePointer->size()>0){

//         for(sceneStruct* scene : *m_currentScenePointer){
//             if (scene != nullptr) {
//                 if(scene->m_keybinds.size()>0){
//                     if(m_TEST_inputHandler!=nullptr){
//                         // m_TEST_inputHandler->assign(scene->m_keybinds);
//                     }
    
//                 }
//             }
//         }
//     }
// }

void Render::init(std::vector<sceneStruct*>& currentScenePointer, sf::RenderWindow* window){
    // m_currentScenePointer(currentScenePointer),
    // m_font(font),
    // m_tombolContainer(std::make_unique<TombolContainer>(*m_font)),
    // m_window(window)

    m_currentScenePointer = &currentScenePointer;
    // m_tombolContainer = std::make_unique<TombolContainer>(*m_font);
    m_window = window;
    setup();
}


void Render::setup(){
    for(sceneStruct* scene : *m_currentScenePointer){
        if (scene != nullptr) {

            //ngeiterasi komponen rect
            if(scene->m_kumpulanRect.size()>0){
                for(const auto& komponen : scene->m_kumpulanRect){

                    auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));

                    temp->setFillColor(komponen.second.m_warnaFill);
                    temp->setOutlineColor(komponen.second.m_warnaOutline);
                    temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    m_komponenScene.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen teks
            if(scene->m_kumpulanTeks.size()>0){
                for(const auto& komponen : scene->m_kumpulanTeks){
                    auto temp = std::make_unique<sf::Text>(*m_font, komponen.second.m_teks, komponen.second.m_sizeKarakter);

                    temp->setPosition(komponen.second.m_posisi);
                    
                    m_komponenScene.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen tombol
            if(scene->m_kumpulanTombol.size()>0){

                for(const auto& komponen : scene->m_kumpulanTombol){
                    // std::cout<<komponen.second.m_teks<<std::endl;
                    m_tombolContainer->generate(komponen.second.m_posisiTombol, komponen.second.m_sizeBg, komponen.second.m_teks, komponen.second.m_action); 
                    // if(m_TEST_inputHandler!=nullptr){
                    //     m_TEST_inputHandler->assign()
                    // }
                }
            }

            // if(scene->m_keybinds.size()>0){
            //     if(m_TEST_inputHandler!=nullptr){
            //         m_TEST_inputHandler->assign(scene->m_keybinds);
            //     }else{throw;}

            // }
        }else{
            std::cout<<"scenenya null"<<std::endl;
        }

    }
}

//ngdraw komponen komponen Drawable
void Render::visualize(){
    if(m_komponenScene.size()>0){
        for(const auto& komponen : m_komponenScene){
            m_window->draw(*komponen);
            // std::cout<<"found"<<std::endl;
        }
    }
    if(m_tombolContainer->getSize()>0){
        for(const auto& komponen : m_tombolContainer->getKumpulanBg()){
            m_window->draw(*komponen);
            // std::cout<<komponen->getSize().x<<", "<<komponen->getSize().y<<std::endl;
        }
        for(const auto& komponen : m_tombolContainer->getKumpulanTeks()){
            m_window->draw(*komponen);
        }
    }
    // TESTKEYBINDS();
}

std::unique_ptr<TombolContainer>* Render::getTombolContainerPointer(){
    if(m_tombolContainer!=nullptr){
        return &m_tombolContainer;
    }else{
        throw;
    }
}