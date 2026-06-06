#include "../include/Render.hpp"
#include <iostream>
#include "../include/Engine.hpp"

Render::Render(Engine* engine)
    :
    m_engine(engine)
    // m_sceneManager(sceneManager)
    {
}

void Render::start(){
    
    for(const auto& scene : m_engine->m_sceneManager->m_currentScene){
        std::cout<<"test"<<std::endl;
        if (scene != nullptr) {
            // std::cout<<"kumpulanRectSize: "<<scene->m_kumpulanRect.size()<<std::endl;

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
            if(scene->m_kumpulanTeks.size()>0){
                for(const auto& komponen : scene->m_kumpulanTeks){

                    // auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));
                    auto temp = std::make_unique<sf::Text>(m_engine->m_font, komponen.second.m_teks, komponen.second.m_sizeKarakter);

                    // temp->setFillColor(komponen.second.m_warnaFill);
                    // temp->setOutlineColor(komponen.second.m_warnaOutline);
                    // temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    m_komponenScene.push_back(std::move(temp));
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
            m_window.draw(*komponen);
            // std::cout<<"found"<<std::endl;
        }
    }else{
        std::cout<<"komponenScene kosong"<<std::endl;
    }

}