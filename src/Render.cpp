#include "../include/Render.hpp"
#include <iostream>
// #include "../include/Engine.hpp"
#include "../include/TombolContainer.hpp"
#include "../include/TabContainer.hpp"

Render::Render(sf::Font* font)
: m_font(font)
{
}

// Render::~Render() = default;

void Render::init(std::vector<sceneStruct>& currentScenePointer, sf::RenderWindow* window){
    m_currentScenePointer = &currentScenePointer;
    m_window = window;
    setup();
}


void Render::setup(){
    m_currentSceneSize = m_currentScenePointer->size();
    if(!m_komponenScene.empty()){

        m_komponenScene.clear();
        m_tombolContainer.clear();
        m_tabContainer.clear();

    }
    for(sceneStruct& scene : *m_currentScenePointer){
        // if (scene != nullptr) {
        
            if(m_komponenScene.find(scene.m_namaScene)==m_komponenScene.end()){
                m_komponenScene[scene.m_namaScene].reserve(scene.m_kumpulanRect.size() + scene.m_kumpulanTeks.size());
            }

            //ngeiterasi komponen rect
            if(scene.m_kumpulanRect.size()>0){
                for(const auto& komponen : scene.m_kumpulanRect){

                    auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));

                    temp->setFillColor(komponen.second.m_warnaFill);
                    temp->setOutlineColor(komponen.second.m_warnaOutline);
                    temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    // m_komponenScene.push_back(std::move(temp));
                    m_komponenScene.find(scene.m_namaScene)->second.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen teks
            if(scene.m_kumpulanTeks.size()>0){
                for(const auto& komponen : scene.m_kumpulanTeks){
                    auto temp = std::make_unique<sf::Text>(*m_font, komponen.second.m_teks, komponen.second.m_sizeKarakter);

                    temp->setPosition(komponen.second.m_posisi);
                    
                    // m_komponenScene.push_back(std::move(temp));
                    m_komponenScene.find(scene.m_namaScene)->second.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen tombol
            if(scene.m_kumpulanTombol.size()>0){
                if(m_tombolContainer[scene.m_namaScene]==nullptr){
                    m_tombolContainer[scene.m_namaScene]=std::make_unique<TombolContainer>(*m_font);
                }
                for(const auto& komponen : scene.m_kumpulanTombol){
                    
                    m_tombolContainer.find(scene.m_namaScene)->second->generate(komponen.second.m_posisiTombol, komponen.second.m_sizeBg, komponen.second.m_teks, komponen.second.m_action);
                }
            }

            //ngeiterasi tabContainer
            if(scene.m_tabContainer.size()>0){
                if(m_tabContainer.find(scene.m_namaScene)==m_tabContainer.end()){
                    m_tabContainer[scene.m_namaScene] = std::make_unique<TabContainer>(*m_font, &scene.m_tabContainer.back(), sf::Vector2(UISettings::getMargin(), UISettings::getMargin()));
                    // std::cout << "tru" << std::endl;
                }else{
                    m_tabContainer.find(scene.m_namaScene)->second = std::make_unique<TabContainer>(*m_font, &scene.m_tabContainer.back(), sf::Vector2(UISettings::getMargin(), UISettings::getMargin()));
                    // std::cout << "fals" << std::endl;
                }
                
                // m_tabContainer.find(scene.m_namaScene)->second->m_pivot = sf::Vector2(UISettings::getMargin(), UISettings::getMargin());
                // auto temp = std::make_unique<TabContainer>(*m_font, scene.m_tabContainer.back());

            }

// std::cout << "TEST" << std::endl;
    }
}

//ngdraw komponen komponen Drawable
void Render::visualize(){
    // if(m_currentScenePointer->size()!=m_currentSceneSize){
    //     setup();
    // }

    if(m_komponenScene.size()>0){ //ngecek apkh komponen udh dimapping
        for(const auto& [nama, vektor] : m_komponenScene){
            for(const auto& uniqptr : vektor){
                m_window->draw(*uniqptr);
            }

            if(m_tombolContainer.find(nama)!=m_tombolContainer.end()){
                for(const auto& uniqptr : m_tombolContainer.find(nama)->second->getKumpulanBg()){
                    m_window->draw(*uniqptr);
                }
                for(const auto& uniqptr : m_tombolContainer.find(nama)->second->getKumpulanTeks()){
                    m_window->draw(*uniqptr);
                }
            }

            if(m_tabContainer.find(nama) != m_tabContainer.end()){

                auto& kumpulanTeksOpsiTabCont = m_tabContainer.find(nama)->second->getKumpulanTeks();
                auto& kumpulanTeksSubOpsiTabCont = m_tabContainer.find(nama)->second->getKumpulanSubOpsiTeks();
                auto& currHoveredTabCont = m_tabContainer.find(nama)->second->getCurrentHovered();
                
                // kumpulanTeksSubOpsiTabCont.find(kumpulanTeksOpsiTabCont[currHoveredTabCont.x]->getString());
                
                // m_tabContainer.find(nama)->second->getKumpulanSubOpsiTeks().find(m_tabContainer.find(nama)->second->getKumpulanTeks()[m_tabContainer.find(nama)->second->getCurrentHovered().x])
                // if(m_tabContainer.find(nama)->second->getKumpulanSubOpsiTeks().find(m_tabContainer->get)){
                    for(const auto& uniqptr : m_tabContainer.find(nama)->second->getKumpulanBg()){
                        m_window->draw(*uniqptr.get());
                    }
                    for(const auto& uniqptr : m_tabContainer.find(nama)->second->getKumpulanTeks()){
                        m_window->draw(*uniqptr.get());
                    }
                    if(kumpulanTeksSubOpsiTabCont.find(kumpulanTeksOpsiTabCont[currHoveredTabCont.x].get()->getString().toAnsiString()) != kumpulanTeksSubOpsiTabCont.end()){
                        for(const auto& [str, vector] : kumpulanTeksSubOpsiTabCont){
                            for(const auto& uniqptr : vector){
                                // std::cout << uniqptr.get()->getString().toAnsiString() << std::endl;
                                // std::cout << kumpulanTeksOpsiTabCont[currHoveredTabCont.x].get()->getString().toAnsiString() << std::endl;
                                m_window->draw(*uniqptr.get());
                            }
                        }
                    }
        }
        }
    }

}

std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* Render::getTombolContainerPointer(){
    return &m_tombolContainer;
}

std::unordered_map<SceneName, std::unique_ptr<TabContainer>>* Render::getTabContainerPointer(){
    return &m_tabContainer;
}