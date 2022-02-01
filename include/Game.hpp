#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class Game {
public:
    Game();

    ~Game();

    void clean();

    void refresh();

    SDL_Event event;

    static const int WINDOW_WIDTH = 750;

    static const int WINDOW_HEIGHT = 750;

    static SDL_Renderer *renderer;

    void setRunning(bool newState) { isRunning = newState; }

    bool running() { return isRunning; };

    bool inMenu() {
        if (currentInterface == "menu")
            return true;
        return false;
    }

private:
    SDL_Window *window;

    bool isRunning = false;

    std::string currentInterface = "menu";
};
