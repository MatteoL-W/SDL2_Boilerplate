#include <SDL2/SDL.h>

#include "MenuInterface.h"

void MenuInterface::handleEvents() {
    SDL_Event event = _engine->event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        _engine->setRunning(false);
    }

}

void MenuInterface::update() {
    _menu->update();
}

void MenuInterface::render() {
    _menu->draw();
}
