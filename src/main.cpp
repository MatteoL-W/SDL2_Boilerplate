#include <SDL2/SDL.h>

#include "main.hpp"
#include "Engine.hpp"

Engine *game = nullptr;

int main(int argc, char *argv[]) {
    Engine engine;

    while (engine.running()) {
        Uint32 frameStart = SDL_GetTicks();

        engine.refresh();

        // FPS Handle (custom in Main.hpp)
        unsigned int frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    return 1;
}
