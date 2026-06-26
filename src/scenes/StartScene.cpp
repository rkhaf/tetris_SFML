#include "../../include/scenes/StartScene.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/TombolContainer.hpp"

// StartScene::StartScene(SceneName sceneName, SceneManager* sceneManager){

// }

void StartScene::init(){
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
            createText("title", {
                sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x / 3.5f, 0.0f}, 
                "Tetris", 
                sf::Color::White,
                150
            });

            //create tombol
            createBtn("exit", tombolStruct(
                sf::Vector2f(static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().x / 2.0f), static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().y / 2.0f+ ((UISettings::getButtonSizeBig().y + UISettings::getButtonGap()) * 2))), 
                sf::Vector2f(UISettings::getButtonSizeBig()),
                "Keluar",
                // [this]() { std::cout<<"keluar"<<std::endl; }
                // [this]() { addScene(SceneName::exitConfScene);}
                [localManager]() { localManager->addScene(SceneName::exitConfScene);}
                // [this]() {std::cout << "ke exit confScene" << std::endl;;}
                // [this]() {m_sceneDataStruct->m_sceneManagerReference->addScene(SceneName::exitConfScene);}
            ));

            createBtn("settings", {
                sf::Vector2f{static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().x / 2.0f), static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().y / 2.0f + ((UISettings::getButtonSizeBig().y + UISettings::getButtonGap()) * 1))}, 
                sf::Vector2f{UISettings::getButtonSizeBig()},
                "Pengaturan",
                [localManager]() { localManager->changeScene(SceneName::SettingsUI); }
                // [localManager]() { std::cout<<"masuk ke setings"<<std::endl; }
            });

            createBtn("play", {
                sf::Vector2f{static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().x / 2), static_cast<float>(m_sceneManagerReference->getRenderWindow()->getSize().y / 2)}, 
                sf::Vector2f{UISettings::getButtonSizeBig()},
                "Main"
                ,
                [localManager]() { std::cout<<"ayo main yuk"<<std::endl;}
            });

            // if (m_tombolContainer->find(SceneName::startScene) == m_tombolContainer->end()) {
            if (m_sceneManagerReference->getTombolContainerUMap()->find(SceneName::startScene) == m_sceneManagerReference->getTombolContainerUMap()->end()) {
                (*m_sceneManagerReference->getTombolContainerUMap())[SceneName::startScene] = std::make_unique<TombolContainer>(*m_sceneManagerReference->getFont());
            }

            // m_sceneManagerReference->getAudioPlayer()
            //setting keybinds
            
            createBinds({
                {Kontrol::atas, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::startScene)->second->geser(Kontrol::kiri);}},
                // {Kontrol::kiri, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},
                {Kontrol::atas, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::bawah, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::startScene)->second->geser(Kontrol::kanan);}},
                {Kontrol::bawah, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

                {Kontrol::drop, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::startScene)->second->click();}},
                {Kontrol::drop, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_confirm);}},

                {Kontrol::exit, [localManager](){localManager->addScene(SceneName::exitConfScene);}},
                // {Kontrol::exit, [this](){m_sceneManagerReference->addScene(SceneName::exitConfScene);}},

                // {Kontrol::exit, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_back);}},
                // {Kontrol::exit, [localManager](){std::cout << "TEST" << std::endl;}},
                // {Kontrol::exit, [localManager](){test();}},
                // {Kontrol::exit, [localManager](){localManager->test();}},
                // {Kontrol::exit, [this](){m_audioPlayer.playMusic(audioBoard::BGM_mainMusic);}},

            });
}

