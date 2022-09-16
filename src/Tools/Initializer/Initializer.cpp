#include <iostream>

#include "Initializer.h"

namespace Tools {
    void Initializer::initialize() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        if (!IMG_Init(IMG_INIT_PNG)) {
            std::cerr << "IMG_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        if (TTF_Init() < 0) {
            std::cerr << "TTF_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
            exit(1);
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(1);
        }
    }

    void Initializer::setOpenGLAttribute() {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    }

    void Initializer::verifyOpenGLContext(SDL_GLContext p_context, SDL_Window *p_window) {
        if (p_context == nullptr) {
            std::cerr << "Error creating OpenGL context : " << SDL_GetError();

            SDL_DestroyWindow(p_window);
            SDL_Quit();
            exit(1);
        }
    }
}
