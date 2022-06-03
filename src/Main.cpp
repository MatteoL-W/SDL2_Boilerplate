#include <SDL2/SDL.h>

#include "../include/Main.hpp"
#include "../include/Engine.hpp"

Engine *game = nullptr;

int main(int argc, char *argv[]) {
    game = new Engine();

    while (game->running()) {
        Uint32 frameStart = SDL_GetTicks();

        game->refresh();

        // FPS Handle (custom in Main.hpp)
        int frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    return 1;
}
