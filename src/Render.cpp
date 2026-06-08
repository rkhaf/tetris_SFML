#include "../include/Render.hpp"
#include <iostream>
#include "../include/Engine.hpp"

Render::Render(sf::Font* font, std::vector<sceneStruct*>& currentScenePointer, sf::RenderWindow* window)
    :
    m_currentScenePointer(currentScenePointer),
    m_font(font),
    m_tombolContainer(std::make_unique<TombolContainer>(*m_font)),
    m_window(window)
    // m_sceneManager(sceneManager)

{
    // std::cout<<&m_currentScenePointer<<std::endl;
}

void Render::start(){
    // std::cout<<m_currentScenePointer<<std::endl;

    for(sceneStruct* scene : m_currentScenePointer){
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

                // if(m_tombolContainer==nullptr){
                //     m_tombolContainer = std::make_unique<TombolContainer>(m_font);
                // }

                for(const auto& komponen : scene->m_kumpulanTombol){
                    // std::cout<<komponen.second.m_teks<<std::endl;
                    m_tombolContainer->generate(komponen.second.m_posisiTombol, komponen.second.m_sizeBg, komponen.second.m_teks);
                }
            }
        }else{
            std::cout<<"scenenya null"<<std::endl;
        }

    }
}

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
}

TombolContainer& Render::getTombolContainerPointer(){
    if(m_tombolContainer!=nullptr){
        return *m_tombolContainer;
    }else{
        throw;
    }
}