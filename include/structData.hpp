#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class SceneManager;

namespace globalColors {
    // const sf::Color NeonCyan(0x00f3ffFF);
    const sf::Color panelFill(0x242434FF);
    const sf::Color panelFill2(0x33334DFF);
    const sf::Color panelOutline(0x3d3d5cFF);
    const sf::Color buttonHovered(0x9200D9FF);
    const sf::Color fontColor(0xffffffff);
    const sf::Color darkenBg85(0x000000D9);
    const sf::Color darkenBg70(0x000000BF);
    const sf::Color darkenBg25(0x00000040);
}

enum class SceneName : uint8_t{
    startScene = 0,
    SettingsUI = 1,
    exitConfScene = 2
};

enum class Kontrol : uint8_t{
    kiri = static_cast<int>(sf::Keyboard::Key::A),
    kanan = static_cast<int>(sf::Keyboard::Key::D),
    atas = static_cast<int>(sf::Keyboard::Key::W),
    bawah = static_cast<int>(sf::Keyboard::Key::S),
    drop = static_cast<int>(sf::Keyboard::Key::Space),
    exit = static_cast<int>(sf::Keyboard::Key::Escape)
};

struct textStruct{
    std::string m_teks;
    sf::Vector2f m_posisi;
    sf::Color m_warna;
    uint8_t m_sizeKarakter;

    textStruct(sf::Vector2f posisi, std::string teks , sf::Color warna, uint8_t sizeKarakter)
    : m_teks(teks),
    m_posisi(posisi),
    m_warna(warna),
    m_sizeKarakter(sizeKarakter) {}
};


struct rectStruct{
    sf::Vector2f m_posisi;
    sf::Vector2f m_size;
    float m_outlineThickness;
    sf::Color m_warnaFill;
    sf::Color m_warnaOutline;

    rectStruct(sf::Vector2f size, sf::Vector2f pos, float outlineThickness, sf::Color warnaFill, sf::Color warnaOutline)
    : 
    m_posisi(pos),
    m_size(size),
    m_outlineThickness(outlineThickness),
    m_warnaFill(warnaFill), 
    m_warnaOutline(warnaOutline)
    {}
};


struct tombolStruct{
    sf::Vector2f m_posisiTombol;
    sf::Vector2f m_sizeBg;
    std::string m_teks;
    std::function<void()> m_action = nullptr;

    tombolStruct(sf::Vector2f posisiTombol, sf::Vector2f sizeBg, std::string teks, std::function<void()> action = [](){})
    :
    m_posisiTombol(posisiTombol),
    m_sizeBg(sizeBg),
    m_teks(teks),
    m_action(std::move(action))
    {};
};

struct sliderStruct{
    std::string m_label;
    float m_min = 0.0f;
    float m_max = 0.0f;

    sliderStruct(std::string label, float min, float max)
    :
    m_label(label),
    m_min(min),
    m_max(max)
    {}
};

struct checkButtonStruct{
    bool m_state = false;
};

struct tabContainerStruct{
    std::vector<std::string> m_opsi;
    std::unordered_map<std::string, std::vector<std::variant<sliderStruct, checkButtonStruct>>> m_input;

    tabContainerStruct(){};
};

struct sceneStruct{
    SceneName m_namaScene;
    std::unordered_map<std::string, textStruct> m_kumpulanTeks;
    std::unordered_map<std::string, rectStruct> m_kumpulanRect;
    std::unordered_map<std::string, tombolStruct> m_kumpulanTombol;
    std::unordered_map<Kontrol, std::vector<std::function<void()>>> m_keybinds;
    std::vector<tabContainerStruct> m_tabContainer;
    // std::unique_ptr<tabContainerStruct> m_tabContainer;
    // tabContainerStruct m_tabContainer;

    sceneStruct(SceneName namaScene) : m_namaScene(namaScene) {};
};

// struct sceneDataStruct{
//     SceneManager* m_sceneManagerReference;
//     sf::RenderWindow* m_window = nullptr;

//     sceneDataStruct(SceneManager* sceneManager)
//     :
//     m_sceneManagerReference(sceneManager)
//     {}
// };