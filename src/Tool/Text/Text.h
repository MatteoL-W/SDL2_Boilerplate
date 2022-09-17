#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/vec2.hpp>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <utility>

namespace Tool {
    class Text {
    public:
        Text(std::string p_content, TTF_Font *p_font, SDL_Color p_color, float p_x, float p_y)
                : _content(std::move(p_content)), _font(p_font), _color(p_color), _x(p_x), _y(p_y) {
            apply();
        };

        ~Text() = default;

        void draw();
        void apply() {
            generateSurface();
            bindTexture();
        }

        void changeText(std::string newText) { _content = std::move(newText); };
        void changeColor(SDL_Color newColor) { _color = newColor; };
        void deleteTexture();

    private:
        void generateSurface();
        void bindTexture();

        std::string _content;
        TTF_Font *_font;
        SDL_Color _color;
        SDL_Surface *_renderedText{};
        GLuint _textureBind = 0;
        float _x, _y;
    };
}
