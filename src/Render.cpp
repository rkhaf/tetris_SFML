#include "../include/Render.hpp"
#include <iostream>
// #include "../include/Engine.hpp"
#include "../include/komponent/TombolContainer.hpp"

Render::Render(sf::Font* font)
: m_font(font)
{
    // m_tombolContainer = std::make_unique<TombolContainer>(*m_font);

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
    m_currentSceneSize = m_currentScenePointer->size();
    for(sceneStruct* scene : *m_currentScenePointer){
        if (scene != nullptr) {
            // m_komponenScene.find(scene->m_namaScene)
            if(m_komponenScene.find(scene->m_namaScene)==m_komponenScene.end()){
                m_komponenScene[scene->m_namaScene].reserve(scene->m_kumpulanRect.size() + scene->m_kumpulanTeks.size());
            }

            //ngeiterasi komponen rect

            if(scene->m_kumpulanRect.size()>0){
                for(const auto& komponen : scene->m_kumpulanRect){

                    auto temp = std::make_unique<sf::RectangleShape>(sf::Vector2f(komponen.second.m_size));

                    temp->setFillColor(komponen.second.m_warnaFill);
                    temp->setOutlineColor(komponen.second.m_warnaOutline);
                    temp->setOutlineThickness(komponen.second.m_outlineThickness);
                    temp->setPosition(komponen.second.m_posisi);
                    
                    // m_komponenScene.push_back(std::move(temp));
                    m_komponenScene.find(scene->m_namaScene)->second.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen teks
            if(scene->m_kumpulanTeks.size()>0){
                for(const auto& komponen : scene->m_kumpulanTeks){
                    auto temp = std::make_unique<sf::Text>(*m_font, komponen.second.m_teks, komponen.second.m_sizeKarakter);

                    temp->setPosition(komponen.second.m_posisi);
                    
                    // m_komponenScene.push_back(std::move(temp));
                    m_komponenScene.find(scene->m_namaScene)->second.push_back(std::move(temp));
                }
            }

            //ngeiterasi komponen tombol
            if(scene->m_kumpulanTombol.size()>0){
                
                for(const auto& komponen : scene->m_kumpulanTombol){
                    // std::cout<<komponen.second.m_teks<<std::endl;
                    
                    if(m_tombolContainer[scene->m_namaScene]==nullptr){
                        m_tombolContainer[scene->m_namaScene]=std::make_unique<TombolContainer>(*m_font);
                    }
                    m_tombolContainer.find(scene->m_namaScene)->second->generate(komponen.second.m_posisiTombol, komponen.second.m_sizeBg, komponen.second.m_teks, komponen.second.m_action);
                    // m_tombolContainer.push_back(std::make_unique<TombolContainer>(*m_font));
                    // m_tombolContainer->generate(komponen.second.m_posisiTombol, komponen.second.m_sizeBg, komponen.second.m_teks, komponen.second.m_action); 
                    // if(m_TEST_inputHandler!=nullptr){
                    //     m_TEST_inputHandler->assign()
                    // }
                }
            }
            // else{
            //     m_tombolContainer->resetContainer();
            // }

            // if(scene->m_keybinds.size()>0){
            //     if(m_TEST_inputHandler!=nullptr){
            //         m_TEST_inputHandler->assign(scene->m_keybinds);
            //     }else{throw;}

            // }
        }else{
            std::cout<<"scenenya null"<<std::endl;
        }

    }
    // std::cout << "tset" << std::endl;
}

//ngdraw komponen komponen Drawable
void Render::visualize(){
    if(m_currentScenePointer->size()!=m_currentSceneSize){
        setup();
    }

    // auto test = m_tombolContainer.find(SceneName::startScene)->second.get();
    // std::cout << "asd" << std::endl;
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
            // for(const auto& uniqptr : m_komponenScene.find(nama))[

            // ]
        }
    }

    // if(m_komponenScene.size()>0){
    //     for(const auto& komponen : m_komponenScene){
    //         m_window->draw(*komponen);
    //     }
    // }
    // if(m_tombolContainer.size()>0){
    //     for(const auto& [nama, uniqptr] : m_tombolContainer){
    //         for(const auto& komponen : uniqptr->getKumpulanBg()){
    //             m_window->draw(*komponen);
    //         }
    //         for(const auto& komponen : uniqptr->getKumpulanTeks()){
    //             m_window->draw(*komponen);
    //         }
    //     }
    // }

    // std::cout << "asd" << std::endl;
}

std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* Render::getTombolContainerPointer(){
    // if(m_tombolContainer.)
    return &m_tombolContainer;


    // if(!m_tombolContainer.empty()){
    //     if(m_tombolContainer.find(namaScene)!=m_tombolContainer.end()){
    //         if(m_tombolContainer.find(namaScene)->second!=nullptr){
    //             return &m_tombolContainer.find(namaScene)->second;
    //         }
    //     }
    // }
    // return nullptr;
    // if(m_tombolContainer!=nullptr){
    //     return &m_tombolContainer;
    // }else{
    //     throw;
    // }
}