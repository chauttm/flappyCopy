#include "intro.h"
#include "level.h"
#include <iostream>

class MainWindow;

class Game {
    MainWindow& win;

public:
    GameStates curr_state = GameStates::Intro;
    GameState* state;

    Game(MainWindow& _win) :win(_win) {
        state = new Intro(_win);
    }

    void lost()
    {
        Texture back(win.getRenderer()), t(win.getRenderer());
        back.loadFromFile("flappy_assets/background.jpg");
        Font f;
        f.loadFromFile("./flappy_assets/Purisa-BoldOblique.ttf", 30);
        t.loadFromRenderedText("YOU LOST!!! Score: " + std::to_string(state->score), f,SDL_Color{0xFF,0,0,0xFF});

        win.clear();
        back.render(0,0);
        t.render((win.getWidth() - t.getWidth()) / 2, ((win.getHeight() - t.getHeight()) / 2));
        win.update();

        SDL_Delay(2000);
    }

    void changeState()
    {
        if (state->next_state != GameStates::Null) {
            curr_state = state->next_state;

            switch (curr_state) {
                case GameStates::Lost:
                    lost();
                    delete state;
                    state = new Intro(win);
                    break;
                case GameStates::Intro:
                    delete state;
                    state = new Intro(win);
                    break;
                case GameStates::Level:
                    delete state;
                    state = new Level(win);
                    break;
                default:
                    break;
            }
        }
    }
};
