#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "Engine.h"
#include "interfaces/MenuInterface.h"

SDL_Renderer *Engine::renderer = nullptr;
MenuInterface *menuInterface = nullptr;

/**
 * @brief Initialize the engine (assign the window, renderer, define the engine as running)
 */
Engine::Engine() {
    initiateSDLLibs();

    /* Create SDL needs */
    _window = SDL_CreateWindow("Thomas Was Alone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                               WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    _context = SDL_GL_CreateContext(_window);

    if (_context == nullptr) {
        std::cout << "Error creating OpenGL context : " << SDL_GetError();

        SDL_DestroyWindow(_window);
        SDL_Quit();
        exit(1);
    }

    /* Define the interfaces */
    menuInterface = new MenuInterface(this);

    /* Define the default interface*/
    _currentInterface = menuInterface;

    _isRunning = true;

    initiateWindowSize();
}

void Engine::initiateSDLLibs() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "IMG_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (TTF_Init() < 0) {
        std::cout << "TTF_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
        printf("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }
}

/**
 * @brief Quit the engine properly
 */
void Engine::clean() {
    SDL_GL_DeleteContext(_context);
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

/**
 * @brief Chose the right interface and refresh execute its method
 */
void Engine::refresh() {
    _currentInterface->update();

    SDL_RenderClear(Engine::renderer);
    glClear(GL_COLOR_BUFFER_BIT);
    _currentInterface->render();
    SDL_GL_SwapWindow(_window);

    _currentInterface->handleEvents();
}

/**
 * @brief Initiate the window size and the orthonormal coordinate system
 */
void Engine::initiateWindowSize() {
    glViewport(0, 0, Engine::WINDOW_WIDTH, Engine::WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(
            0, 1200,
            0, 720
    );
}