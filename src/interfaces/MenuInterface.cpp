#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../include/interfaces/MenuInterface.hpp"
#include "../../include/Game.hpp"
#include "../../include/Text.hpp"

/**
 * @brief Handle SDL Events in the menu
 */
void MenuInterface::handleEvents() {
    SDL_Event event = game->event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        game->setRunning(false);
    }

}

/**
 * @brief Update the menu
 */
void MenuInterface::update() {
    SDL_RenderClear(Game::renderer);

    menu->update();

    SDL_RenderPresent(Game::renderer);
}

/**
 * @brief Render the menu
 */
void MenuInterface::render() {
    SDL_RenderClear(Game::renderer);

    menu->draw();

    SDL_RenderPresent(Game::renderer);
}
