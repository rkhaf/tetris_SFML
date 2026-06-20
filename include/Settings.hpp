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