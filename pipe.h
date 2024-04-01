#ifndef PIPE_H
#define PIPE_H

#include "texture.h"

#include <utility>
#include <SDL.h>

class Pipe {
    Texture* texturePtr;
    SDL_Rect upper, lower;

public:
    bool left_behind = false;

    void init(Texture* texturePtr, int posX, int pass_height=100, int pass_size=120);
    void render();
    void set_pos(int posX);
    void set_height(int pass_height);
    void scroll(int distance);

    const SDL_Rect& get_upper() const {return upper;}
    const SDL_Rect& get_lower() const {return lower;}
    int                                      get_pos() const {return upper.x;}
    int                                    get_width() const {return upper.w;}
};

#endif // PIPE_H
