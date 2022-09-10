#include <SDL2/SDL.h>

#include "MenuInterface.h"

void MenuInterface::handleEvents() {
    Engine* engine = Engine::GetInstance();
    SDL_Event event = engine->event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        engine->setRunning(false);
    }

}

void MenuInterface::update() {
    _menu->update();
}

void MenuInterface::render() {
    _menu->draw();
}
