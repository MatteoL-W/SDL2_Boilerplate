#pragma once

#include "Engine.h"
#include "interfaces/Interface.h"
#include "Menu/Menu.h"

class MenuInterface : public Interface {
public:
    explicit MenuInterface()
            : _menu(new Menu()) {
    }
    ~MenuInterface() = default;

    void handleEvents() override;
    void update() override;
    void render() override;

private:
    Menu *_menu;
};

