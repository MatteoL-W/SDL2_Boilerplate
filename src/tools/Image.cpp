#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Image.h"

void Image::generateSurface() {
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    _imageSurface = IMG_Load(_path.c_str());
}

void Image::bindTexture() {
    glGenTextures(1, &_textureBind);
    glBindTexture(GL_TEXTURE_2D, _textureBind);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Image::draw() {
    glEnable(GL_BLEND);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _imageSurface->w, _imageSurface->h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _imageSurface->pixels);

    glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2f(_x, _y);
        glTexCoord2d(1, 1); glVertex2f(_x + (float)_imageSurface->w / _divider, _y);
        glTexCoord2d(1, 0); glVertex2f(_x + (float)_imageSurface->w / _divider, _y + (float)_imageSurface->h / _divider);
        glTexCoord2d(0, 0); glVertex2f(_x, _y + (float)_imageSurface->h / _divider);
    glEnd();

    glDisable(GL_BLEND);
}

void Image::draw(glm::vec2 p_BL, float p_width, float p_height) {
    glEnable(GL_BLEND);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _imageSurface->w, _imageSurface->h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _imageSurface->pixels);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 1); glVertex2f(p_BL.x, p_BL.y);
    glTexCoord2d(1, 1); glVertex2f(p_BL.x + p_width, p_BL.y);
    glTexCoord2d(1, 0); glVertex2f(p_BL.x + p_width, p_BL.y + p_height);
    glTexCoord2d(0, 0); glVertex2f(p_BL.x, p_BL.y + p_height);
    glEnd();

    glDisable(GL_BLEND);
}

void Image::deleteTexture() {
    glDeleteTextures(1, &_textureBind);
    SDL_FreeSurface(_imageSurface);
}
