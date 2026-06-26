#include "../../include/scenes/SettingsUI.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/TombolContainer.hpp"

// StartScene::StartScene(SceneName sceneName, SceneManager* sceneManager){

// }

void SettingsUI::init(){
            // m_sceneDataStruct = sceneDataStruct;
            SceneManager* localManager = this->m_sceneManagerReference;

            //create panel
            createRect("mainPanel", rectStruct(
                sf::Vector2f(m_sceneManagerReference->getRenderWindow()->getSize().x - (UISettings::getMargin() * 2), m_sceneManagerReference->getRenderWindow()->getSize().y - (UISettings::getMargin() * 2)), 
                sf::Vector2f(UISettings::getMargin(), UISettings::getMargin()), 
                1.0f,
                globalColors::panelFill, 
                globalColors::panelOutline
            ));

            //create teks
            // createText("title", {
            //     sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x / 3.5f, 0.0f}, 
            //     "Tetris", 
            //     sf::Color::White,
            //     150
            // });

            sf::Vector2f setengahBtnSmall = UISettings::getButtonSizeSmall() / 2.0f;

            //create tombol
            createBtn("return", tombolStruct(
                sf::Vector2f(UISettings::getMargin() + setengahBtnSmall.x, UISettings::getMargin() + setengahBtnSmall.y), 
                sf::Vector2f(UISettings::getButtonSizeSmall()),
                "Kembali",
                // [this]() { std::cout<<"keluar"<<std::endl; }
                // [this]() { addScene(SceneName::exitConfScene);}
                [localManager]() { localManager->changeScene(SceneName::startScene);}
                // [this]() {std::cout << "ke exit confScene" << std::endl;;}
                // [this]() {m_sceneDataStruct->m_sceneManagerReference->addScene(SceneName::exitConfScene);}
            ));

            createBtn("Audio", {
                sf::Vector2f(UISettings::getMargin() + setengahBtnSmall.x + (UISettings::getButtonSizeSmall().x * 1.0f), UISettings::getMargin() + setengahBtnSmall.y ),  
                sf::Vector2f{UISettings::getButtonSizeSmall()},
                "Audio",
                [localManager]() { std::cout<<"masuk ke menu audio"<<std::endl; }
            });

            createBtn("tetromino", {
                sf::Vector2f{UISettings::getMargin() + setengahBtnSmall.x + (UISettings::getButtonSizeSmall().x * 2.0f), UISettings::getMargin() + setengahBtnSmall.y}, 
                sf::Vector2f{UISettings::getButtonSizeSmall()},
                "tetromino"
                ,
                [localManager]() { std::cout<<"masuk ke menu tetromino"<<std::endl;}
            });

            // if (m_tombolContainer->find(SceneName::startScene) == m_tombolContainer->end()) {
            if (m_sceneManagerReference->getTombolContainerUMap()->find(SceneName::SettingsUI) == m_sceneManagerReference->getTombolContainerUMap()->end()) {
                (*m_sceneManagerReference->getTombolContainerUMap())[SceneName::SettingsUI] = std::make_unique<TombolContainer>(*m_sceneManagerReference->getFont());
            }

            // m_sceneManagerReference->getAudioPlayer()
            //setting keybinds
            
            createBinds({
                {Kontrol::kanan, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kiri);}},
                // {Kontrol::kiri, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},
                {Kontrol::kanan, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::kiri, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kanan);}},
                {Kontrol::kiri, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::drop, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::SettingsUI)->second->click();}},
                {Kontrol::drop, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_confirm);}},
                
                {Kontrol::exit, [localManager](){localManager->changeScene(SceneName::startScene);}},
                {Kontrol::exit, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_back);}},
                // {Kontrol::exit, [this](){m_sceneManagerReference->addScene(SceneName::exitConfScene);}},

                // {Kontrol::exit, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_back);}},
                // {Kontrol::exit, [localManager](){std::cout << "TEST" << std::endl;}},
                // {Kontrol::exit, [localManager](){test();}},
                // {Kontrol::exit, [localManager](){localManager->test();}},
                // {Kontrol::exit, [this](){m_audioPlayer.playMusic(audioBoard::BGM_mainMusic);}},

            });
}

