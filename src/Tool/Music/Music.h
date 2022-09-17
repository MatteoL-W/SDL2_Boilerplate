#pragma once

#include "SDL2/SDL_mixer.h"

namespace Tool {
    class Music {
    public:
        explicit Music(const char *p_path)
                : _music(Mix_LoadMUS(p_path)) {};

        ~Music() = default;

        void play(int loops) { Mix_PlayMusic(_music, loops); };

        static void stop() { Mix_HaltMusic(); };

    private:
        Mix_Music *_music;
    };
}

