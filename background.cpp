#include "background.h"

Background::Background(SDL_Renderer* renderer, const std::string& path)
    : t{renderer}, scrollingOffset{0}
{
    t.loadFromFile(path);
}

void Background::render()
{
    // Render 2 copies
    t.render(scrollingOffset, 0);
    t.render(scrollingOffset - t.getWidth(), 0);
}

void Background::scroll(int distance)
{
    scrollingOffset -= distance;
    if( scrollingOffset < 0 ) { scrollingOffset = t.getWidth(); }
}
