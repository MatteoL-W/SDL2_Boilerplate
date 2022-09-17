#pragma once

#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_mixer.h"

namespace Tool {
    class Initializer {
    public:
        static void initialize();
        static void setOpenGLAttribute();
        static void verifyOpenGLContext(SDL_GLContext p_context, SDL_Window *p_window);
    };
}
