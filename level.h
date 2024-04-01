#ifndef LEVEL_H
#define LEVEL_H

#include "defs.h"
#include "background.h"
#include "player.h"
#include "music.h"
#include "pipe.h"
#include "texture.h"
#include "font.h"

#include <array>
#include <random>

class MainWindow; // forward declare

class Level {
    const MainWindow& win;
    Background background;
    Player pl;
    Sound jump_s;
    Sound lost_s;
    std::array<Pipe, 3> pipes;
    Font font;
    Texture title;
    Texture pipeTexture;

    std::random_device seeder {};
    std::mt19937 engine;
    std::uniform_int_distribution<int> dist;

public:
    Level(const MainWindow&);
    Level(const Level&) = delete;
    Level& operator=(const Level&) = delete;

    void handle_events();
    void logic();
    void render();
    GameStates next_state = GameStates::Null;
    int score = 0;

private:
    inline bool hit_bottom();
    inline bool hit_roof();
    inline void check_bounds();
    inline void check_all_collisions();
    inline void check_score();
};

#endif // LEVEL_H
