#pragma once

#include "SDL2/SDL_mixer.h"

namespace Tool {
    class Sound {
    public:
        explicit Sound(const char *p_path)
                : _soundChunk(Mix_LoadWAV(p_path)) {};

        ~Sound() = default;

        void play() { Mix_PlayChannel(-1, _soundChunk, false); };

    private:
        Mix_Chunk *_soundChunk;
    };
}


