#include "../include/SceneParent.hpp"
#include <iostream>
// #include "../include/SceneParent.hpp"

SceneParent::SceneParent(SceneName sceneName, SceneManager* sceneManager)
:
m_sceneStruct(sceneName),
m_sceneManagerReference(sceneManager)
{
}

SceneParent::~SceneParent(){
}

sceneStruct SceneParent::getSceneStruct(){
    std::cout << "TEST" << std::endl;
    return std::move(m_sceneStruct);
}

void SceneParent::init(){
    // m_sceneDataStruct = sceneDataStruct;
    // m_window = sceneDataStruct->m_window;
    // m_windowCenter = sf::Vector2f(m_window->getSize().x/2.0f, m_window->getSize().y/2.0f);
}

//buat ngecreate rectangle
void SceneParent::createRect(std::string nama, const rectStruct& config){
    m_sceneStruct.m_kumpulanRect.try_emplace(std::move(nama), config.m_size, config.m_posisi, config.m_outlineThickness, config.m_warnaFill, config.m_warnaOutline);
}

//buat ngecreate sf::text
void SceneParent::createText(std::string nama, const textStruct& config){
    m_sceneStruct.m_kumpulanTeks.try_emplace(std::move(nama), config.m_posisi, config.m_teks, config.m_warna, config.m_sizeKarakter);
}

//buat ngecreate tombol
void SceneParent::createBtn(std::string nama, const tombolStruct& config){
    m_sceneStruct.m_kumpulanTombol.try_emplace(std::move(nama), config.m_posisiTombol, config.m_sizeBg, std::move(config.m_teks), config.m_action);
}

void SceneParent::createBinds(std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan){
    // startScene->m_keybinds[Kontrol::kiri].push_back([this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kiri);});
    if(!vecPasangan.empty()){
        for(const auto& [kontrol, fungsi] : vecPasangan){
            m_sceneStruct.m_keybinds[kontrol].push_back(std::move(fungsi));
        }
    }
}
