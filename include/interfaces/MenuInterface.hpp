#pragma once

#include "../Game.hpp"
#include "../Interface.hpp"
#include "../Menu.hpp"

class MenuInterface : public Interface {
public:
    MenuInterface(Game *game) {
        MenuInterface::game = game;
        MenuInterface::menu = new Menu();
    }

    ~MenuInterface();

    void handleEvents();

    void update();

    void render();

    bool isActive() {
        if (game->getCurrentInterface() == name)
            return true;
        return false;
    };

private:
    Game *game;

    Menu *menu;

    std::string name = "menu";

};

