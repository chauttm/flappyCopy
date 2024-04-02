#include "exception.h"
#include <SDL.h>

void logErrorAndExit(const std::string&  msg, const char* error)
{
    if (error != nullptr)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    else
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s", msg);
    SDL_Quit();
    exit(-1);
}
