#include "texture.h"
#include "font.h"
#include "mainwindow.h"
#include "exception.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

Texture::Texture(SDL_Renderer* renderer)
    : mTexture{nullptr},
      gRenderer{renderer},
      mWidth{0}, mHeight{0}
{}

Texture::~Texture()
{
    free();
}

void Texture::loadFromFile( const std::string& path )
{
    free();

    mTexture = IMG_LoadTexture(gRenderer, path.c_str());
    if( mTexture == nullptr ) {
        logErrorAndExit("Unable to create texture from " + path, SDL_GetError());
    }
    SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
}

void Texture::loadFromRenderedText( const std::string& textureText, Font& f, SDL_Color textColor )
{
    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid( f.getFont(), textureText.c_str(), textColor );
    if( textSurface == nullptr ) {
        logErrorAndExit("Unable to render text surface! SDL_ttf Error: ", TTF_GetError());
    }

    mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
    if( mTexture == nullptr ) {
        logErrorAndExit("Unable to create texture from text :", SDL_GetError());
    }

    mWidth = textSurface->w;
    mHeight = textSurface->h;

    SDL_FreeSurface( textSurface );
}

void Texture::free()
{
    if( mTexture != nullptr ) {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void Texture::setBlendMode( SDL_BlendMode blending )
{
    SDL_SetTextureBlendMode( mTexture, blending );
}

void Texture::setAlpha( Uint8 alpha )
{
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void Texture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    if( clip != nullptr )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}
