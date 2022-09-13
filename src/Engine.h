#pragma once

#include <iostream>
#include "SDL2/SDL.h"

#include "State/IState.h"
#include "State/Menu/MenuState.h"

class Engine {
public:
    ~Engine() = default;

    // Singleton
    static Engine *GetInstance();
    static Engine* _instance;

    // State Machine
    IState *getCurrentState() { return _currentState; };

    void refresh();
    void clean();

    bool isRunning() const { return _isRunning; };

    static const int WINDOW_WIDTH = 1200;
    static const int WINDOW_HEIGHT = 750;
    constexpr static const float aspectRatio = Engine::WINDOW_WIDTH / (float) Engine::WINDOW_HEIGHT;

private:
    Engine();
    static void initiateWindowSize();

    // States
    MenuState* _menuInterface;

    IState *_currentState;
    SDL_Window *_window;
    SDL_GLContext _context;
    SDL_Event _event;

    bool _isRunning = false;
};
