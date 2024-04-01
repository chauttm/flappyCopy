#ifndef INTRO_H
#define INTRO_H

#include "defs.h"
#include "texture.h"
#include "background.h"
#include "font.h"
#include "mainwindow.h"

class Intro {
    const MainWindow& win;
    Background background;
    Texture title;
    Texture subtitle;

public:
    Intro(const MainWindow&);
    Intro(const Intro&) = delete;
    Intro& operator=(const Intro&) = delete;

    void logic();
    void render();
};

#endif // INTRO_H
