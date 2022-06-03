#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Interface.hpp"

class Engine {
public:
    Engine();

    ~Engine() = default;

    void clean();

    void refresh();

    SDL_Event event;

    static const int WINDOW_WIDTH = 1200;

    static const int WINDOW_HEIGHT = 750;

    constexpr static const float aspectRatio = Engine::WINDOW_WIDTH / (float) Engine::WINDOW_HEIGHT;

    static SDL_Renderer *renderer;

    void setRunning(bool newState) { isRunning = newState; }

    bool running() { return isRunning; };

    Interface *getCurrentInterface() { return currentInterface; };

private:
    SDL_Window *window;

    SDL_GLContext context;

    bool isRunning = false;

    Interface *currentInterface;

    static void initiateWindowSize();

    static void initiateSDLLibs();
};
