#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <SDL.h>

class MainWindow final {
    int width;
    int height;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;

public:
    MainWindow(int w, int h, const std::string& title = " ");
    ~MainWindow();
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

    void setIcon(const std::string& path);
    void clear() const;
    void update() const;

    SDL_Renderer* getRenderer() const {return gRenderer;}
    SDL_Window*     getWindow() const {return gWindow;  }
    int              getWidth() const {return width;    }
    int             getHeight() const {return height;   }
};

#endif // MAINWINDOW_H
