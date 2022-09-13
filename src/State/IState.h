#pragma once

class IState {
public:
    virtual void handleEvents(SDL_Event event) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
