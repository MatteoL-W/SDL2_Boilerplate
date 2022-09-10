#pragma once

#include <iostream>
#include "SDL2/SDL.h"

#include "interfaces/Interface.h"

class Engine {
public:
    ~Engine() = default;

    static Engine *GetInstance();
    static Engine* _instance;

    void clean();
    void refresh();

    void setRunning(bool p_newState) { _isRunning = p_newState; }
    bool running() const { return _isRunning; };

    Interface *getCurrentInterface() { return _currentInterface; };

    SDL_Event event;
    static SDL_Renderer *renderer;

    static const int WINDOW_WIDTH = 1200;
    static const int WINDOW_HEIGHT = 750;
    constexpr static const float aspectRatio = Engine::WINDOW_WIDTH / (float) Engine::WINDOW_HEIGHT;


private:
    Engine();
    static void initiateWindowSize();
    static void initiateSDLLibs();

    Interface *_currentInterface;
    SDL_Window *_window;
    SDL_GLContext _context;

    bool _isRunning = false;
};
