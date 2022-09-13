#pragma once

#include "interfaces/StateInterface.h"
#include "Menu/Menu.h"

class MenuState : public StateInterface {
public:
    void handleEvents() override;
    void update() override;
    void render() override;

private:
    Menu _menu{};
};

