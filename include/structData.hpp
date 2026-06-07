#pragma once
#include <SFML/Graphics.hpp>

enum class SceneName : uint8_t{
    startScene = 0
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
    float m_outlineThicknessBg;
    sf::Color m_warnaTeks;
    uint8_t m_sizeKarakterTeks;
    sf::Color m_warnaFillBg;
    sf::Color m_warnaOutlineBg;
    std::string m_teks;

    tombolStruct(sf::Vector2f posisiTombol, sf::Vector2f sizeBg, float outlineThicknessBg, sf::Color warnaTeks, uint8_t sizeKarakterTeks, sf::Color warnaFillBg, sf::Color warnaOutlineBg, std::string teks)
    :
    m_posisiTombol(posisiTombol),
    m_sizeBg(sizeBg),
    m_outlineThicknessBg(outlineThicknessBg),
    m_warnaTeks(warnaTeks),
    m_sizeKarakterTeks(sizeKarakterTeks),
    m_warnaFillBg(warnaFillBg),
    m_warnaOutlineBg(warnaOutlineBg),
    m_teks(teks)
    {};

};

struct sceneStruct{
    SceneName m_namaScene;
    std::unordered_map<std::string, textStruct> m_kumpulanTeks;
    std::unordered_map<std::string, rectStruct> m_kumpulanRect;
    std::unordered_map<std::string, tombolStruct> m_kumpulanTombol;

    sceneStruct(SceneName namaScene) : m_namaScene(namaScene) {};
};