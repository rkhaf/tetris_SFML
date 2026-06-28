#include "../../include/scenes/SettingsUI.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/TombolContainer.hpp"
#include "../../include/TabContainer.hpp"

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
            
            // createBtn("Audio", {
            //     sf::Vector2f(UISettings::getMargin() + setengahBtnSmall.x + (UISettings::getButtonSizeSmall().x * 1.0f), UISettings::getMargin() + setengahBtnSmall.y ),  
            //     sf::Vector2f{UISettings::getButtonSizeSmall()},
            //     "Audio",
            //     [localManager]() { std::cout<<"masuk ke menu audio"<<std::endl; }
            // });
            
            // createBtn("tetromino", {
            //     sf::Vector2f{UISettings::getMargin() + setengahBtnSmall.x + (UISettings::getButtonSizeSmall().x * 2.0f), UISettings::getMargin() + setengahBtnSmall.y}, 
            //     sf::Vector2f{UISettings::getButtonSizeSmall()},
            //     "tetromino"
            //     ,
            //     [localManager]() { std::cout<<"masuk ke menu tetromino"<<std::endl;}
            // });
            
            // createBtn("return", tombolStruct(
            //     sf::Vector2f(UISettings::getMargin() + setengahBtnSmall.x, UISettings::getMargin() + setengahBtnSmall.y), 
            //     sf::Vector2f(UISettings::getButtonSizeSmall()),
            //     "Kembali",
            //     // [this]() { std::cout<<"keluar"<<std::endl; }
            //     // [this]() { addScene(SceneName::exitConfScene);}
            //     [localManager]() { localManager->changeScene(SceneName::startScene);}
            //     // [this]() {std::cout << "ke exit confScene" << std::endl;;}
            //     // [this]() {m_sceneDataStruct->m_sceneManagerReference->addScene(SceneName::exitConfScene);}
            // ));
            // // if (m_tombolContainer->find(SceneName::startScene) == m_tombolContainer->end()) {
            // if (m_sceneManagerReference->getTombolContainerUMap()->find(SceneName::SettingsUI) == m_sceneManagerReference->getTombolContainerUMap()->end()) {
            //     (*m_sceneManagerReference->getTombolContainerUMap())[SceneName::SettingsUI] = std::make_unique<TombolContainer>(*m_sceneManagerReference->getFont());
            // }

            tabContainerStruct newTabContainerStruct;

            sliderStruct sfxVolumeSlider("SFX Volume", 0, 100);
            sliderStruct bgmVolumeSlider("BGM Volume", 0, 100);
            

            newTabContainerStruct.m_opsi.push_back("Audio");
            newTabContainerStruct.m_opsi.push_back("Tetromino");

            newTabContainerStruct.m_input["Audio"].push_back(sfxVolumeSlider);
            newTabContainerStruct.m_input["Audio"].push_back(bgmVolumeSlider);

            m_sceneStruct.m_tabContainer.push_back(newTabContainerStruct);

            // m_sceneManagerReference->getAudioPlayer()
            //setting keybinds

            // localManager->getTombolContainerUMap()->find(SceneName::SettingsUI)->second->click();
            // localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->click();
            
            createBinds({
                {Kontrol::kanan, [localManager](){localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kanan);}},
                // {Kontrol::kanan, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kiri);}},
                {Kontrol::kanan, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::kiri, [localManager](){localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kiri);}},
                {Kontrol::kiri, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::bawah, [localManager](){localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::bawah);}},
                {Kontrol::bawah, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::atas, [localManager](){localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::atas);}},
                {Kontrol::atas, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                // {Kontrol::drop, [localManager](){localManager->getTabContainerUMap()->find(SceneName::SettingsUI)->second->geser(Kontrol::kanan);}},
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

