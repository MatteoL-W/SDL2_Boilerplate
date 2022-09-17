#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include "glm/vec2.hpp"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <utility>

namespace Tool {
    class Image {
    public:
        explicit Image(std::string p_path, float p_x = 0, float p_y = 0, float p_divider = 0)
                : _path(std::move(p_path)), _x(p_x), _y(p_y), _divider(p_divider) {
            apply();
        };

        ~Image() = default;

        void draw();
        void draw(glm::vec2 p_BL, float p_width, float p_height);

        void apply() { generateSurface(); bindTexture(); }
        void deleteTexture();

    private:
        void generateSurface();
        void bindTexture();

        std::string _path;
        SDL_Surface* _imageSurface{};
        GLuint _textureBind = 0;
        float _x, _y, _divider;
    };
}
