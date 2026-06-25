#pragma once

// struct Settings{
//     float AUDIO_VOLUME_SFX = 100.0f;
//     float AUDIO_VOLUME_BGM = 100.0f;
// };

namespace Settings{
    namespace Internal{
        inline float AUDIO_VOLUME_SFX = 100.0f;
        inline float AUDIO_VOLUME_BGM = 100.0f;
    }

    inline float getAudioVolumeSFX(){return Internal::AUDIO_VOLUME_SFX;}
    inline void setAudioVolumeSFX(float value){Internal::AUDIO_VOLUME_SFX = value;}

    inline float getAudioVolumeBGM(){return Internal::AUDIO_VOLUME_BGM;}
    inline void setAudioVolumeBGM(float value){Internal::AUDIO_VOLUME_BGM = value;}
    
}

namespace UISettings{
    namespace Internal{
        // inline float AUDIO_VOLUME_SFX = 100.0f;
        // inline float AUDIO_VOLUME_BGM = 100.0f;
        inline float buttonGap = 18.0f;
        inline float m_margin=12.0f;
        inline sf::Vector2f buttonSizeBig = sf::Vector2f((256.0f * 2), (128.0f * 0.5));
    }
    
    inline float getButtonGap(){return Internal::buttonGap;};
    inline float getMargin(){return Internal::m_margin;};
    inline sf::Vector2f getButtonSizeBig(){return Internal::buttonSizeBig;};
}