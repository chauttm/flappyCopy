#include "intro.h"
#include "mainwindow.h"
#include "defs.h"

Intro::Intro(const MainWindow& _win)
    :win(_win),
    background{_win.getRenderer(), BACKGROUND_INTRO},
    title{_win.getRenderer()},
    subtitle{_win.getRenderer()}
{
    Font bigFont, smallFont;
    bigFont.loadFromFile(FONT_PATH, TEXT_SIZE_BIG);
    smallFont.loadFromFile(FONT_PATH, TEXT_SIZE_SMALL);
    title.loadFromRenderedText(WINDOW_TITLE, bigFont, SDL_Color{0xFF,0,0,0xFF});
    subtitle.loadFromRenderedText("Press to continue...", smallFont, SDL_Color{0,0,0,0xFF});
}

void Intro::logic()
{
    background.scroll(3);
}

void Intro::render()
{
    win.clear();
    background.render();

    title.render((win.getWidth() - title.getWidth()) / 2,
                 (win.getHeight() - title.getHeight()) / 2);
    subtitle.render((win.getWidth() - subtitle.getWidth()) / 2,
                    (win.getHeight() + title.getHeight() - subtitle.getHeight()) / 2);
    win.update();
}
