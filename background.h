#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "texture.h"

#include <string>
#include <SDL.h>

class Background {
    Texture t;
    int scrollingOffset;
public:
    Background(SDL_Renderer* renderer, const std::string& path);

    void render();
    void scroll(int distance);
};

#endif // BACKGROUND_H
