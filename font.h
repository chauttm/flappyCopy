#ifndef FONT_H
#define FONT_H

#include <SDL_ttf.h>
#include <string>

// SDL_ttf true type font wrapper
class Font {
    TTF_Font* gFont;

public:
    Font();
    Font(const std::string& path, int size);
    ~Font() ;

    Font(const Font&) = delete;
    Font& operator=(const Font&) = delete;

    TTF_Font* getFont() const {return gFont;}
    bool      isValid() const {return gFont != nullptr;}
    void loadFromFile(const std::string& path, int size);

private:
    void free() ;
};

#endif // FONT_H
