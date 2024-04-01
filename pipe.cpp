#include "pipe.h"

void Pipe::init(Texture* _texturePtr, int posX, int pass_height, int pass_size)
{
    texturePtr = _texturePtr;

    upper.x = lower.x = posX;
    upper.y = 0 - pass_height;
    lower.y = upper.y + texturePtr->getHeight() + pass_size;

    upper.w = lower.w = texturePtr->getWidth();
    upper.h = lower.h = texturePtr->getHeight();
}

void Pipe::render()
{
    texturePtr->render(upper.x,  upper.y, nullptr, 0.0, nullptr, SDL_FLIP_VERTICAL); // Top pipe
    texturePtr->render(lower.x, lower.y); // Bottom pipe
}

void Pipe::set_pos(int posX)
{
    upper.x = lower.x = posX;
}

void Pipe::set_height(int pass_height)
{
    int sz = lower.y - upper.y - upper.h; // size of the passage
    upper.y = 0 - pass_height;
    lower.y = upper.y + upper.h + sz;
}

void Pipe::scroll(int distance)
{
    upper.x -= distance;
    lower.x -= distance;
}
