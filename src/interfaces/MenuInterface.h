#pragma once

#include "Engine.h"
#include "interfaces/Interface.h"
#include "Menu/Menu.h"

class MenuInterface : public Interface {
public:
    explicit MenuInterface(Engine *engine)
            : engine(engine), menu(new Menu()) {
    }

    ~MenuInterface() = default;

    void handleEvents() override;

    void update() override;

    void render() override;

private:
    Engine *engine;

    Menu *menu;

};

