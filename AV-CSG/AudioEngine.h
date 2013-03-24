#pragma once
#include "Singleton.h"

class AudioEngine : public Singleton<AudioEngine>
{
    friend class Singleton<AudioEngine>;

public:
    virtual ~AudioEngine();

    virtual bool Initialize();

    void PauseAudio();
    void ResumeAudio();
    void StopAudio();

    ///> �������ֲ���
    bool LoadMusic(const std::string& filename);
    void StopMusic();
    void PlayMusic();
    void PauseMusic();
    void ResumeMusic();

    ///> ��Ч����
    bool LoadSound(const std::string& filename);
    void PlaySound(const std::string& filename);
    void StopSound(const std::string& filename);
    void PauseSound(const std::string& filename);
    void ResumeSound(const std::string& filename);
    void PauseAllSounds();
    void ResumeAllSounds();
    void StopAllSounds();

private:
    AudioEngine();

};
