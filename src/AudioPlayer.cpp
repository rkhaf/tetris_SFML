#include "../include/AudioPlayer.hpp"
#include <iostream>

AudioPlayer::AudioPlayer(){
    m_kumpulanLagu[audioBoard::SFX_clickSound] = {
        {note::E5, 0.1f},
        {note::REST, 0.2f}
    };
    m_kumpulanLagu[audioBoard::SFX_confirm] = {
        {note::D4, 0.1f},
        {note::E5, 0.1f},
        {note::REST, 0.2f}
    };
    m_kumpulanLagu[audioBoard::SFX_back] = {
        {note::E5, 0.1f},
        {note::D4, 0.1f},
        {note::REST, 0.2f}
    };
    m_kumpulanLagu[audioBoard::BGM_mainMusic] = {
        { note::E5, base * 4 },
        { note::B4, base * 2 },
        { note::C5, base * 2 },
        { note::D5, base * 4 },
        { note::C5, base * 2 },
        { note::B4, base * 2 },
        { note::A4, base * 6 },
        { note::C5, base * 2 },
        { note::E5, base * 4 },
        { note::D5, base * 2 },
        { note::C5, base * 2 },
        { note::B4, base * 6 },
        { note::C5, base * 2 },
        { note::D5, base * 4 },
        { note::E5, base * 4 },
        { note::C5, base * 4 },
        { note::A4, base * 4 },
        { note::A4, base * 4 },
        { note::A4, base * 6 },
        { note::D5, base * 4 },
        { note::F5, base * 2 },
        { note::A5, base * 4 },
        { note::G5, base * 2 },
        { note::F5, base * 2 },
        { note::E5, base * 6 },
        { note::F5, base * 2 },
        { note::E5, base * 4 },
        { note::D5, base * 2 },
        { note::C5, base * 2 },
        { note::B4, base * 6 },
        { note::C5, base * 2 },
        { note::D5, base * 2 },
        { note::D5, base * 2 },
        { note::C5, base * 2 },
        { note::B4, base * 2 },
        { note::A4, base * 12 },
        { note::A4, base * 2 },
        { note::C5, base * 2 }
    };

    m_kumpulanLagu[audioBoard::BGM_menuMusic] = {
// --- SCREENSHOT 1 (Bar 1 - Bar 3 Akhir) ---
    { note::G4,   base * 2 },
    { note::Gs4, base * 2 },
    { note::A4,   base * 4 },
    { note::Gs4, base * 4 },
    { note::A4,   base * 2 },  
    { note::As4, base * 2 },  
    { note::B4,   base * 2 },  
    { note::C5,   base * 2 },  
    { note::A4,   base * 6 },
    { note::Gs4, base * 2 },
    { note::A4, base * 2 },
    { note::As4, base * 2 },
    { note::C5, base * 2 },
    { note::D5, base * 2 },
    { note::E5, base * 6 },
    { note::C5, base * 2 },
    { note::B4, base * 2 },
    { note::D5, base * 2 },
    { note::C5, base * 2 },
    { note::B4, base * 2 },
    { note::A4, base * 6 },
    { note::B4, base * 2 },
    { note::D5, base * 2 },
    { note::C5, base * 2 }
    };
    bakeSound();
}

void AudioPlayer::playSound(audioBoard soundboard){
    // m_speaker_SFX.emplace(m_kumpulanLaguJadi.find(soundboard)->second);
    m_speaker_SFX->setBuffer(m_kumpulanLaguJadi.find(soundboard)->second);
    m_speaker_SFX->play();
}

void AudioPlayer::playMusic(audioBoard soundboard){
    if(m_speaker_BGM->getStatus()!=sf::Sound::Status::Playing){
        m_speaker_BGM->setLooping(true);
        m_speaker_BGM->setBuffer(m_kumpulanLaguJadi.find(soundboard)->second);
        m_speaker_BGM->play();
    }
}

void AudioPlayer::changeMusic(audioBoard soundboard){
    m_speaker_BGM->setBuffer(m_kumpulanLaguJadi.find(soundboard)->second);
}

void AudioPlayer::bakeSound(){
    for(const auto& [nama, vektor] : m_kumpulanLagu){
        m_kumpulanLaguJadi[nama] = converter(vektor);
    }
    m_speaker_SFX.emplace(m_kumpulanLaguJadi.find(audioBoard::SFX_clickSound)->second);
    m_speaker_BGM.emplace(m_kumpulanLaguJadi.find(audioBoard::SFX_clickSound)->second);
    
    synchronizeSpeakerVolume();
    // m_speaker_BGM->setVolume(Settings::getAudioVolumeBGM());
    // m_speaker_SFX->setVolume(Settings::getAudioVolumeSFX());
}

void AudioPlayer::synchronizeSpeakerVolume(){
    m_speaker_BGM->setVolume(Settings::getAudioVolumeBGM());
    m_speaker_SFX->setVolume(Settings::getAudioVolumeSFX());
}

sf::SoundBuffer AudioPlayer::converter(const std::vector<std::pair<structNote, float>>& rentetanNot) {
    std::vector<int16_t> totalSamples;
    
    //mke global biar gelombang sinus nyambung terus
    double global_t = 0.0; 
    double dt = 1.0 / 44100.0; // Durasi per satu sampel waktu

    for (const auto& notePair : rentetanNot) {
        structNote currentNote = notePair.first;
        float duration = notePair.second;

        //ngitung sample bwt durasi not
        size_t noteSamplesCount = static_cast<size_t>(sampleRate * duration);

        for (size_t i = 0; i < noteSamplesCount; ++i) {
            int16_t sampleValue = 0;

            if (currentNote.frekuensi > 0.0) {
                //idk
                double getaranSinus = std::sin(2.0 * 3.141592653589793 * currentNote.frekuensi * global_t);

                double gelombangSinus = std::sin(2.0 * M_PI * currentNote.frekuensi * global_t);
                double gelombangKotak = (std::sin(2.0 * M_PI * currentNote.frekuensi * global_t) > 0) ? 1.0 : -1.0;
                double suaraFinal = (0.7 * gelombangSinus) + (0.3 * gelombangKotak);

                // sampleValue = static_cast<int16_t>(10000.0 * getaranSinus);
                sampleValue = static_cast<int16_t>(5000.0 * suaraFinal);
            }

            // push2 kali buat kanan kiri
            totalSamples.push_back(sampleValue); // Kiri
            totalSamples.push_back(sampleValue); // Kanan

            // nmbh waktu
            global_t += dt;
        }
    }

    sf::SoundBuffer matengBuffer;

    // ngemapping channel static biar stabil di RAM
    static const std::vector<sf::SoundChannel> defaultChannelMap = {
        sf::SoundChannel::FrontLeft,
        sf::SoundChannel::FrontRight
    };

    //ngeget mke parameter map channel
    if (!matengBuffer.loadFromSamples(totalSamples.data(), totalSamples.size(), 2, sampleRate, defaultChannelMap)) {
        std::cout << "Fiks gagal di level internal SFML gann" << std::endl;
    }

    return matengBuffer;
}
