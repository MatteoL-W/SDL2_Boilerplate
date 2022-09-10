#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Engine.h"
#include "Text.h"

void Text::generateSurface() {
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    _renderedText = TTF_RenderText_Blended(const_cast<TTF_Font *>(_font), _content.c_str(), _color);
}

void Text::bindTexture() {
    glGenTextures(1, &_textureBind);
    glBindTexture(GL_TEXTURE_2D, _textureBind);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Text::draw() {
    glEnable(GL_BLEND);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _renderedText->w, _renderedText->h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _renderedText->pixels);

    glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2f(_x, _y);
        glTexCoord2d(1, 1); glVertex2f(_x + ((float)_renderedText->w), _y);
        glTexCoord2d(1, 0); glVertex2f(_x + ((float)_renderedText->w), _y + (float)_renderedText->h);
        glTexCoord2d(0, 0); glVertex2f(_x, _y + (float)_renderedText->h );
    glEnd();

    glDisable(GL_BLEND);
}

void Text::drawInGame() {
    glEnable(GL_BLEND);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _renderedText->w, _renderedText->h, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, _renderedText->pixels);

    glBegin(GL_QUADS);
    glTexCoord2d(0, 1); glVertex2f(_x, _y);
    glTexCoord2d(1, 1); glVertex2f(_x + ((float)_renderedText->w / (Engine::WINDOW_WIDTH)) * Engine::aspectRatio, _y);
    glTexCoord2d(1, 0); glVertex2f(_x + ((float)_renderedText->w / (Engine::WINDOW_WIDTH)) * Engine::aspectRatio, _y + (float)_renderedText->h / (Engine::WINDOW_HEIGHT));
    glTexCoord2d(0, 0); glVertex2f(_x, _y + (float)_renderedText->h / (Engine::WINDOW_HEIGHT));
    glEnd();

    glDisable(GL_BLEND);
}

void Text::deleteTexture() {
    glDeleteTextures(1, &_textureBind);
    SDL_FreeSurface(_renderedText);
}
