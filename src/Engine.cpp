#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "Engine.h"
#include "interfaces/MenuState.h"
#include "SDL_Initializer/SDL_Initializer.h"

SDL_Renderer *Engine::renderer = nullptr;
MenuState *menuInterface = nullptr;

/**
 * @brief Initialize the engine (assign the window, renderer, define the engine as running)
 */
Engine::Engine() {
    SDL_Initializer::initialize();

    _window = SDL_CreateWindow(
        "PROJECT",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    SDL_Initializer::setOpenGLAttribute();
    _context = SDL_GL_CreateContext(_window);
    SDL_Initializer::verifyOpenGLContext(_context, _window);

    /* Define the interfaces */
    menuInterface = new MenuState();

    /* Define the default interface*/
    _currentState = menuInterface;

    _isRunning = true;
    initiateWindowSize();
}

Engine *Engine::GetInstance() {
    if (_instance == nullptr) {
        _instance = new Engine{};
    }
    return _instance;
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
    _currentState->update();

    SDL_RenderClear(Engine::renderer);
    glClear(GL_COLOR_BUFFER_BIT);
    _currentState->render();
    SDL_GL_SwapWindow(_window);

    _currentState->handleEvents();
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