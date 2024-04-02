#ifndef DEFS_H
#define DEFS_H

#define WINDOW_TITLE "Flappy Bird Remake"
#define WINDOW_ICON_PATH "./flappy_assets/flappy.png"

#define BACKGROUND_INTRO "./flappy_assets/clouds.jpg"
#define BACKGROUND_LEVEL "./flappy_assets/clouds.jpg"
#define BACKGROUND_GAMEOVER "flappy_assets/background.jpg"

#define FONT_PATH "./flappy_assets/Purisa-BoldOblique.ttf"

#define MUSIC_THEME_PATH "./flappy_assets/Running Away - John Charles Fiddy.mp3"
#define SOUND_JUMP "./flappy_assets/jump.wav"
#define SOUND_LOST "./flappy_assets/lost.wav"

#define PIPE_IMAGE "./flappy_assets/pipe.png"
#define BIRD_IMAGE "./flappy_assets/flappy.png"

#define TEXT_SIZE_BIG 30
#define TEXT_SIZE_SMALL 16

enum class GameStates {
    Intro,
    Level,
    Lost,
    Quit,
    Null
};

#endif // DEFS_H
