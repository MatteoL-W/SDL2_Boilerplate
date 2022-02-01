#pragma once

#include "Text.hpp"

class Menu {
public:
    Menu();

    ~Menu();

    void update();

    void draw();

private:
    Text* titleText;
};
