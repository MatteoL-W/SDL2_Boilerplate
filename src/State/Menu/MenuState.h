#pragma once

#include "State/IState.h"

class MenuState : public IState {
public:
    MenuState();

    void handleEvents() override;
    void update() override;
    void render() override;
};

