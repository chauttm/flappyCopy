#include "mainwindow.h"
#include "defs.h"
#include "intro.h"
#include "level.h"
#include "music.h"

#include <SDL.h>
#include <memory>

GameStates doIntro(MainWindow& win) {
    Intro intro(win);
    SDL_Event e;

    while (true) {
        intro.render();
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return GameStates::Quit;
            }
            else if (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_FINGERDOWN) {
                return GameStates::Level;
            }
        }
        intro.logic();
    }
}

void doGameOver(MainWindow& win, int score) {
        Texture back(win.getRenderer()), t(win.getRenderer());
        back.loadFromFile(BACKGROUND_GAMEOVER);
        Font f;
        f.loadFromFile(FONT_PATH, TEXT_SIZE_BIG);
        t.loadFromRenderedText("YOU LOST!!! Score: " + std::to_string(score), f,SDL_Color{0xFF,0,0,0xFF});

        win.clear();
        back.render(0,0);
        t.render((win.getWidth() - t.getWidth()) / 2, ((win.getHeight() - t.getHeight()) / 2));
        win.update();

        SDL_Delay(2000);
}

GameStates doLevel(MainWindow& win) {
    Level level(win);

    while (level.next_state == GameStates::Null) {
        level.handle_events();
        level.logic();
        level.render();
    }
    if (level.next_state == GameStates::Lost) {
        doGameOver(win, level.score);
        return GameStates::Intro;
    }
    return level.next_state;
}

int main(int argc, char *argv[])
{
    MainWindow win (640, 480, WINDOW_TITLE);
    win.setIcon(WINDOW_ICON_PATH);

    Music mus {MUSIC_THEME_PATH};
    mus.play();

    GameStates current_state = GameStates::Intro;

    while (current_state != GameStates::Quit) {
        switch (current_state)
        {
            case GameStates::Intro: current_state = doIntro(win); break;
            case GameStates::Level: current_state = doLevel(win); break;
            default: return -1; // unexpected
        }
    }
    return 0;
}
