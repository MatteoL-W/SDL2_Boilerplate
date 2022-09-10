#pragma once

#include "Engine.h"
#include "interfaces/Interface.h"
#include "Menu/Menu.h"

class MenuInterface : public Interface {
public:
    explicit MenuInterface(Engine *p_engine)
            : _engine(p_engine), _menu(new Menu()) {
    }
    ~MenuInterface() = default;

    void handleEvents() override;
    void update() override;
    void render() override;

private:
    Engine *_engine;
    Menu *_menu;
};

