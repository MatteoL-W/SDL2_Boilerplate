#include <SDL2/SDL.h>

#include "Engine.h"
#include "MenuState.h"

void MenuState::handleEvents() {
    Engine* engine = Engine::GetInstance();
    SDL_Event event = engine->event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        engine->setRunning(false);
    }

}

void MenuState::update() {
    _menu.update();
}

void MenuState::render() {
    _menu.draw();
}
