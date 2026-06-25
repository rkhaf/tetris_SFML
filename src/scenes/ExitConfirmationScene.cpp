#include "../../include/scenes/ExitConfirmationScene.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/TombolContainer.hpp"

// StartScene::StartScene(SceneName sceneName, SceneManager* sceneManager){

// }

void ExitConfirmationScene::init(){
    //create panel
    SceneManager* localManager = this->m_sceneManagerReference;
    std::cout << "ExitConfirmationScene::init()1" << std::endl;
    createRect("exitPanel", rectStruct(
        sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x - (UISettings::getMargin() * 8), m_sceneManagerReference->getRenderWindow()->getSize().y - (UISettings::getMargin() * 8)},
        sf::Vector2f{UISettings::getMargin() * 4, UISettings::getMargin() * 4}, 
        1.0f, 
        globalColors::panelFill, 
        globalColors::panelOutline
    ));
    std::cout << "ExitConfirmationScene::init()1.1" << std::endl;
    createRect("bg", rectStruct(
        sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x - (UISettings::getMargin() * 2), m_sceneManagerReference->getRenderWindow()->getSize().y - (UISettings::getMargin() * 2)}, 
        sf::Vector2f{UISettings::getMargin(), UISettings::getMargin()}, 
        1.0f,
        globalColors::darkenBg25, 
        globalColors::panelOutline
    ));

    std::cout << "ExitConfirmationScene::init()2" << std::endl;
    float exitPanelPosY = m_sceneStruct.m_kumpulanRect.find("exitPanel")->second.m_posisi.y;

    createText("title", textStruct(
        sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x / 6.0f, exitPanelPosY + UISettings::getMargin()}, 
        "apakah yakin ingin keluar?", 
        sf::Color::White,
        48
    ));

    std::cout << "ExitConfirmationScene::init()3" << std::endl;
    //create tombol
    createBtn("yes", tombolStruct(
        sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x / 2.0f, m_sceneManagerReference->getRenderWindow()->getSize().y / 2.0f + ((UISettings::getButtonSizeBig().y + UISettings::getButtonGap()) * 2)}, 
        sf::Vector2f{UISettings::getButtonSizeBig()},
        "iya",
        // [this]() { std::cout<<"keluar"<<std::endl; }
        [localManager]() {localManager->getRenderWindow()->close();}
    ));

    sf::Vector2f yesButtonPos = m_sceneStruct.m_kumpulanTombol.find("yes")->second.m_posisiTombol;

    createBtn("no", tombolStruct(
        sf::Vector2f{m_sceneManagerReference->getRenderWindow()->getSize().x / 2.0f, m_sceneManagerReference->getRenderWindow()->getSize().y / 2.0f + ((UISettings::getButtonSizeBig().y + UISettings::getButtonGap()) * 1)}, 
        sf::Vector2f{UISettings::getButtonSizeBig()},
        "tidak",
        [localManager]() {localManager->popScene();}
    ));

    std::cout << "ExitConfirmationScene::init()4" << std::endl;
    // SceneManager* localManager = this->m_sceneManagerReference;
    createBinds({
        {Kontrol::kiri, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::exitConfScene)->second->geser(Kontrol::kanan);}},
        {Kontrol::kiri, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::kanan, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::exitConfScene)->second->geser(Kontrol::kiri);}},
        {Kontrol::kanan, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::drop, [localManager](){localManager->getTombolContainerUMap()->find(SceneName::exitConfScene)->second->click();}},
        {Kontrol::drop, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_confirm);}},

        {Kontrol::exit, [localManager](){localManager->popScene();}},
        {Kontrol::exit, [localManager](){localManager->getAudioPlayer().playSound(audioBoard::SFX_back);}},
    });
    std::cout << "ExitConfirmationScene::init()5" << std::endl;

}

