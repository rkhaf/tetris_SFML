#include "../../include/scenes/SettingsUI.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/TombolContainer.hpp"
#include "../../include/TabContainer.hpp"
// #include"../../include/custom_convex/Arrow.hpp"

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

            sf::Vector2f setengahBtnSmall = UISettings::getButtonSizeSmall() / 2.0f;

            tabContainerStruct newTabContainerStruct;

            sliderStruct sfxVolumeSlider("SFX Volume", 0, &Settings::Internal::AUDIO_VOLUME_SFX, 100);
            sliderStruct bgmVolumeSlider("BGM Volume", 0, Settings::getAudioVolumeBGM(), 100);
            

            newTabContainerStruct.m_opsi.push_back("Audio");
            newTabContainerStruct.m_opsi.push_back("Tetromino");

            newTabContainerStruct.m_input["Audio"].push_back(sfxVolumeSlider);
            newTabContainerStruct.m_input["Audio"].push_back(bgmVolumeSlider);

            m_sceneStruct.m_tabContainer.push_back(newTabContainerStruct);

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
                {Kontrol::exit, [localManager](){localManager->sinkronVolumeSpeaker();}},


            });
}

