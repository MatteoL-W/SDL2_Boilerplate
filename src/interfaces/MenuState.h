#pragma once

#include "interfaces/IState.h"
#include "Menu/Menu.h"

class MenuState : public IState {
public:
    void handleEvents() override;
    void update() override;
    void render() override;

private:
    Menu _menu{};
};

