#include "../include/SceneManager.hpp"
#include "../include/TombolContainer.hpp"
#include <iostream>

SceneManager::SceneManager(){
    
}

void SceneManager::init(sf::Font* font, sf::RenderWindow* window, std::unordered_map<SceneName, std::unique_ptr<TombolContainer>>* tombolContainerPtr){
    m_window = window;
    m_font = font;
    windowCenter = sf::Vector2f(m_window->getSize().x / 2, m_window->getSize().y / 2);
    m_tombolContainer=tombolContainerPtr;
    // changeScene(SceneName::startScene);
    addScene(SceneName::startScene);
    m_audioPlayer.playMusic(audioBoard::BGM_menuMusic);
}



//ngeclear seluruh scene, nambahin yg baru
void SceneManager::changeScene(SceneName targetScene){
    //CEK POINTER
    if(m_window!=nullptr){
        m_currentScene.clear();
        switch (targetScene){
            case SceneName::startScene:
                generateStartScene();
                break;
        }
    }
    // else{
    //     std::cout<<"windownya kosong"<<std::endl;
    // }
    // updateCurrentBindings();
}

//numpuk scene diatas
void SceneManager::addScene(SceneName targetScene){
    if(m_window!=nullptr){
        switch (targetScene){
            case SceneName::startScene:
                m_currentScene.push_back(generateStartScene());
                // generateStartScene();
                std::cout << "asd" << std::endl;
                break;

            case SceneName::exitConfScene:
                m_currentScene.push_back(generateExitConfirmationPanel());
                // generateExitConfirmationPanel();
                break;
        }
    }
}

void SceneManager::popScene(){
    if(!m_currentScene.empty()){
        delete m_currentScene.back();
        // m_currentScene[m_currentScene.size()-1] = nullptr;
        m_currentScene.pop_back();
    }
}

//###########################################[GENERATE SCENE]#########################################

sceneStruct* SceneManager::generateStartScene(){
    sceneStruct* startScene = new sceneStruct(SceneName::startScene);

    //create panel
    createRect(startScene, "mainPanel", {
        sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, 
        sf::Vector2f{m_margin, m_margin}, 
        1.0f,
        globalColors::panelFill, 
        globalColors::panelOutline
    });

    //create teks
    createText(startScene, "title", {
        sf::Vector2f{static_cast<float>(m_window->getSize().x / 3.5), 0.0f}, 
        "Tetris", 
        sf::Color::White,
        150
    });

    //create tombol
    createBtn(startScene, "exit", {
        sf::Vector2f{static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 2))}, 
        sf::Vector2f{buttonStartSize},
        "Keluar",
        // [this]() { std::cout<<"keluar"<<std::endl; }
        [this]() { addScene(SceneName::exitConfScene);}
    });

    createBtn(startScene, "settings", {
        sf::Vector2f{static_cast<float>(windowCenter.x), static_cast<float>(windowCenter.y + ((buttonStartSize.y + buttonGap) * 1))}, 
        sf::Vector2f{buttonStartSize},
        "Pengaturan",
        [this]() { std::cout<<"masuk ke setings"<<std::endl; }
    });

    createBtn(startScene, "play", {
        sf::Vector2f{static_cast<float>(m_window->getSize().x / 2), static_cast<float>(m_window->getSize().y / 2)}, 
        sf::Vector2f{buttonStartSize},
        "Main"
        ,
        [this]() { std::cout<<"ayo main yuk"<<std::endl;}
    });

    if (m_tombolContainer->find(SceneName::startScene) == m_tombolContainer->end()) {
        (*m_tombolContainer)[SceneName::startScene] = std::make_unique<TombolContainer>(*m_font);
    }

    //setting keybinds
    createBinds(startScene, {
        {Kontrol::kiri, [this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kiri);}},
        {Kontrol::kiri, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::kanan, [this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kanan);}},
        {Kontrol::kanan, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::drop, [this](){m_tombolContainer->find(SceneName::startScene)->second->click();}},
        {Kontrol::drop, [this](){m_audioPlayer.playSound(audioBoard::SFX_confirm);}},

        {Kontrol::exit, [this](){this->addScene(SceneName::exitConfScene);}},
        {Kontrol::exit, [this](){m_audioPlayer.playSound(audioBoard::SFX_back);}},
        // {Kontrol::exit, [this](){m_audioPlayer.playMusic(audioBoard::BGM_mainMusic);}},

    });

    // m_currentScene.push_back(startScene);
    return startScene;
    // getCurrentKeybinds();
}
sceneStruct* SceneManager::generateExitConfirmationPanel(){
    // std::cout << "[SceneManager : " << this << "] : proses generate" << std::endl;
    sceneStruct* exitConfPanel = new sceneStruct(SceneName::exitConfScene);

    
    createRect(exitConfPanel, "exitPanel", {
        sf::Vector2f{m_window->getSize().x - (m_margin * 8), m_window->getSize().y - (m_margin * 8)},
        sf::Vector2f{m_margin * 4, m_margin * 4}, 
        1.0f, 
        globalColors::panelFill, 
        globalColors::panelOutline
    });
    createRect(exitConfPanel, "bg", {
        sf::Vector2f{m_window->getSize().x - (m_margin * 2), m_window->getSize().y - (m_margin * 2)}, 
        sf::Vector2f{m_margin, m_margin}, 
        1.0f,
        globalColors::darkenBg25, 
        globalColors::panelOutline
    });

    float exitPanelPosY = exitConfPanel->m_kumpulanRect.find("exitPanel")->second.m_posisi.y;

    createText(exitConfPanel, "title", {
        sf::Vector2f{m_window->getSize().x / 6.0f, exitPanelPosY + m_margin}, 
        "apakah yakin ingin keluar?", 
        sf::Color::White,
        48
    });

    createBtn(exitConfPanel, "yes", {
        sf::Vector2f{m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f}, 
        sf::Vector2f{buttonStartSize},
        "iya"
        ,
        [this]() { this->m_window->close();}
    });

    sf::Vector2f yesButtonPos = exitConfPanel->m_kumpulanTombol.find("yes")->second.m_posisiTombol;

    createBtn(exitConfPanel, "no", {
        sf::Vector2f{yesButtonPos.x, yesButtonPos.y + (buttonStartSize.y + buttonGap)}, 
        sf::Vector2f{buttonStartSize},
        "tidak"
        ,
        [this]() { this->popScene();}
    });

    createBinds(exitConfPanel, {
        {Kontrol::kiri, [this](){m_tombolContainer->find(SceneName::exitConfScene)->second->geser(Kontrol::kanan);}},
        {Kontrol::kiri, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::kanan, [this](){m_tombolContainer->find(SceneName::exitConfScene)->second->geser(Kontrol::kiri);}},
        {Kontrol::kanan, [this](){m_audioPlayer.playSound(audioBoard::SFX_clickSound);}},

        {Kontrol::drop, [this](){m_tombolContainer->find(SceneName::exitConfScene)->second->click();}},
        {Kontrol::drop, [this](){m_audioPlayer.playSound(audioBoard::SFX_confirm);}},

        {Kontrol::exit, [this](){this->popScene();}},
        {Kontrol::exit, [this](){m_audioPlayer.playSound(audioBoard::SFX_back);}},
    });

    // m_currentScene.push_back(exitConfPanel);
    return exitConfPanel;
    // std::cout << "[SceneManager : " << this << "] : selesai generate scene" << std::endl;
}

//####################################################################################################

//buat ngambil keybinds yang berlaku di scene yg lagi difokusin
sceneStruct* SceneManager::getCurrentKeybinds(){

    if(!m_currentScene.empty()){  
        return m_currentScene.back();
    }
    return nullptr;
}

std::vector<sceneStruct*>* SceneManager::getCurrentScene(){
    return &m_currentScene;
}

//buat ngecreate rectangle
void SceneManager::createRect(sceneStruct* const sceneStruct,std::string nama, const rectStruct& config){
    sceneStruct->m_kumpulanRect.try_emplace(std::move(nama), config.m_size, config.m_posisi, config.m_outlineThickness, config.m_warnaFill, config.m_warnaOutline);
}

//buat ngecreate sf::text
void SceneManager::createText(sceneStruct* const sceneStruct,std::string nama, const textStruct& config){
    sceneStruct->m_kumpulanTeks.try_emplace(std::move(nama), config.m_posisi, config.m_teks, config.m_warna, config.m_sizeKarakter);
}

//buat ngecreate tombol
void SceneManager::createBtn(sceneStruct* const sceneStruct,std::string nama, const tombolStruct& config){
    sceneStruct->m_kumpulanTombol.try_emplace(std::move(nama), config.m_posisiTombol, config.m_sizeBg, std::move(config.m_teks), config.m_action);
}

void SceneManager::createBinds(sceneStruct* const sceneStruct, std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan){
    // startScene->m_keybinds[Kontrol::kiri].push_back([this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kiri);});
    if(!vecPasangan.empty()){
        for(const auto& [kontrol, fungsi] : vecPasangan){
            sceneStruct->m_keybinds[kontrol].push_back(std::move(fungsi));
        }
    }
}