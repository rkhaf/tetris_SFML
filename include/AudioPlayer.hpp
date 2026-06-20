#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <optional>
#include "Settings.hpp"

struct structNote{
    char name[4];
    double frekuensi;
};

enum audioBoard : uint8_t {
    SFX_clickSound,
    SFX_confirm,
    SFX_back,

    BGM_mainMusic,
    BGM_menuMusic
};


namespace note {
    // === OKTAF 4 (Nada Sedang) ===
    const structNote C4  = {"C4",  261.63};
    const structNote Cs4 = {"C#4", 277.18};
    const structNote D4  = {"D4",  293.66};
    const structNote Ds4 = {"D#4", 311.13};
    const structNote E4  = {"E4",  329.63};
    const structNote F4  = {"F4",  349.23};
    const structNote Fs4 = {"F#4", 369.99};
    const structNote G4  = {"G4",  392.00};
    const structNote Gs4 = {"G#4", 415.30};
    const structNote A4  = {"A4",  440.00}; // Nada standar tuning
    const structNote As4 = {"A#4", 466.16};
    const structNote B4  = {"B4",  493.88};

    // === OKTAF 5 (Nada Tinggi) ===
    const structNote C5  = {"C5",  523.25};
    const structNote Cs5 = {"C#5", 554.37};
    const structNote D5  = {"D5",  587.33};
    const structNote Ds5 = {"D#5", 622.25};
    const structNote E5  = {"E5",  659.25};
    const structNote F5  = {"F5",  698.46};
    const structNote Fs5 = {"F#5", 739.99};
    const structNote G5  = {"G5",  783.99};
    const structNote Gs5 = {"G#5", 830.61};
    const structNote A5  = {"A5",  880.00};
    const structNote As5 = {"A#5", 932.33};
    const structNote B5  = {"B5",  987.77};

    // === TAMBAHAN BUAT NADA REHAT (DIAM) ===
    const structNote REST = {"R",    0.00}; // Frekuensi 0 biar speakernya silent pas jeda lagu
}

// enum class note {
//     E5, B4, C5, D5
// };

class AudioPlayer{
    private:
        const int sampleRate = 44100;
        float base = 0.107f;
        const double PI = 3.14159265358979323846;
        // std::unordered_map<double> note;
        // std::vector<std::pair<structNote , float>> m_lagu;
        std::optional<sf::Sound> m_speaker_SFX;
        std::optional<sf::Sound> m_speaker_BGM;
        std::unordered_map<audioBoard, std::vector<std::pair<structNote , float>>> m_kumpulanLagu;
        std::unordered_map<audioBoard, sf::SoundBuffer> m_kumpulanLaguJadi;
        bool m_isPlayingMusic = false;

    public:
        AudioPlayer();
        void bakeSound();
        void playSound(audioBoard soundboard);
        void playMusic(audioBoard soundboard);
        void changeMusic(audioBoard soundboard);
        sf::SoundBuffer converter(const std::vector<std::pair<structNote, float>>& rentetanNot);
};