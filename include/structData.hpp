#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum class SceneName : uint8_t{
    startScene = 0
};

enum class Kontrol : uint8_t{
    kiri = static_cast<int>(sf::Keyboard::Key::A),
    kanan = static_cast<int>(sf::Keyboard::Key::D),
    bawah = static_cast<int>(sf::Keyboard::Key::S),
    drop = static_cast<int>(sf::Keyboard::Key::Space),
    exit = static_cast<int>(sf::Keyboard::Key::Escape)
};

struct textStruct{
    sf::Keyboard::Key test = sf::Keyboard::Key::A;
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

struct sceneStruct{
    SceneName m_namaScene;
    std::unordered_map<std::string, textStruct> m_kumpulanTeks;
    std::unordered_map<std::string, rectStruct> m_kumpulanRect;
    std::unordered_map<std::string, tombolStruct> m_kumpulanTombol;
    // std::unordered_map<Kontrol, std::function<void()>> m_keybinds;
    std::unordered_map<Kontrol, std::vector<std::function<void()>>> m_keybinds;

    sceneStruct(SceneName namaScene) : m_namaScene(namaScene) {};
};