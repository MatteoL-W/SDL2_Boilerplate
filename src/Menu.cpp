#include "../include/Menu.hpp"
#include "../include/Engine.hpp"
#include "../include/variables/Color.hpp"

Text* titleText;

Menu::Menu() {
    titleText = new Text("Menu", TTF_OpenFont("./assets/fonts/Press.ttf", 50), WhiteColor, 0, 0);
}

/**
 * @brief Update the menu
 */
void Menu::update() {

}

/**
 * @brief Draw the menu
 */
void Menu::draw() {
    glClearColor(0.18, 0.5, 0.41, 1);
    glColor3f(0, 0, 0);
    titleText->draw();
}