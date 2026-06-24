#include "../include/SceneParent.hpp"
#include "../include/AudioPlayer.hpp"
#include "../include/TombolContainer.hpp"

void SceneParent::init(sceneDataStruct* dataScene){
    m_dataScene = dataScene;
}

sceneStruct& SceneParent::getStruct(){
    return m_scene;
}

void SceneParent::createRect(std::string nama, const rectStruct& config){
    // sceneStruct->m_kumpulanRect.try_emplace(std::move(nama), config.m_size, config.m_posisi, config.m_outlineThickness, config.m_warnaFill, config.m_warnaOutline);
    m_scene.m_kumpulanRect.try_emplace(std::move(nama), config.m_size, config.m_posisi, config.m_outlineThickness, config.m_warnaFill, config.m_warnaOutline);
}

//buat ngecreate sf::text
void SceneParent::createText(std::string nama, const textStruct& config){
    m_scene.m_kumpulanTeks.try_emplace(std::move(nama), config.m_posisi, config.m_teks, config.m_warna, config.m_sizeKarakter);
}

//buat ngecreate tombol
void SceneParent::createBtn(std::string nama, const tombolStruct& config){
    m_scene.m_kumpulanTombol.try_emplace(std::move(nama), config.m_posisiTombol, config.m_sizeBg, std::move(config.m_teks), config.m_action);
}

void SceneParent::createBinds(std::vector<std::pair<Kontrol, std::function<void()>>> vecPasangan){
    // startScene->m_keybinds[Kontrol::kiri].push_back([this](){m_tombolContainer->find(SceneName::startScene)->second->geser(Kontrol::kiri);});
    if(!vecPasangan.empty()){
        for(const auto& [kontrol, fungsi] : vecPasangan){
            m_scene.m_keybinds[kontrol].push_back(std::move(fungsi));
        }
    }
}