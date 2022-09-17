#include <memory>
#include "SDL2/SDL.h"

#include "Engine.h"
#include "MenuState.h"
#include "Tool/Text/Text.h"
#include "Constant/Color.h"
#include "Constant/Font.h"

std::unique_ptr<Tool::Text> titleText;

MenuState::MenuState() {
    titleText = std::make_unique<Tool::Text>(
            "Menu",
            TTF_OpenFont(Path::Font::Press, 50),
            Color::White,
            0,
            0
    );
}

void MenuState::handleEvents(SDL_Event event) {
    Engine* engine = Engine::GetInstance();
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        engine->clean();
    }

}

void MenuState::update() {
}

void MenuState::render() {
    glClearColor(0.18, 0.5, 0.41, 1);
    titleText->draw();
}

