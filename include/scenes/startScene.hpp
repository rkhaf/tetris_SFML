#pragma once
#include "../SceneParent.hpp"

class startScene : public SceneParent{
    public:
        startScene(){
            //create panel
            createRect("mainPanel", rectStruct(
                sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, 
                sf::Vector2f{m_margin, m_margin}, 
                1.0f,
                globalColors::panelFill, 
                globalColors::panelOutline
            ));

            //create teks
            createText("title", textStruct(
                sf::Vector2f{static_cast<float>(m_window->getSize().x / 3.5), 0.0f}, 
                "Tetris", 
                sf::Color::White,
                150
            ));

            //create tombol
            // tombolStruct BTN_exit(sf::Vector2f{2.0f, 2.0f}, sf::Vector2f{2.0f, 2.0f}, "Keluar", [](){});

            createBtn("exit", tombolStruct(
                sf::Vector2f(static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 2))), 
                sf::Vector2f(buttonStartSize),
                "Keluar",
                // [this]() { std::cout<<"keluar"<<std::endl; }
                // [this]() { addScene(SceneName::exitConfScene);}
                [](){}
            ));

            createBtn("settings", tombolStruct(
                sf::Vector2f(static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 1))), 
                sf::Vector2f(buttonStartSize),
                "Pengaturan",
                [this]() { std::cout<<"\nmasuk ke setings"<<std::endl; }
            ));

            createBtn("play", tombolStruct(
                sf::Vector2f(static_cast<float>(m_window->getSize().x / 2), static_cast<float>(m_window->getSize().y / 2)), 
                sf::Vector2f(buttonStartSize),
                "Main"
                ,
                [this]() { std::cout<<"\nmasuk ke gameplay"<<std::endl;}
            ));

            if (m_tombolContainer->find(SceneName::startScene) == m_tombolContainer->end()) {
                (*m_tombolContainer)[SceneName::startScene] = std::make_unique<TombolContainer>(*m_font);
            }

            //setting keybinds
            createBinds({
                {Kontrol::kiri, [this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kiri);}},
                {Kontrol::kiri, [this](){m_audioPlayer->playSound(audioBoard::SFX_clickSound);}},
                

                {Kontrol::kanan, [this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kanan);}},
                {Kontrol::kanan, [this](){m_audioPlayer->playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::drop, [this](){m_tombolContainer->find(SceneName::startScene)->second->click();}},
                {Kontrol::drop, [this](){m_audioPlayer->playSound(audioBoard::SFX_confirm);}},

                {Kontrol::exit, [this](){this->addScene(SceneName::exitConfScene);}},
                {Kontrol::exit, [this](){m_audioPlayer->playSound(audioBoard::SFX_back);}},

            });
        }
};