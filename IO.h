#ifndef _IO_
#define _IO_

// ------ INCLUDES ------
#ifndef LINUX
#include "SDL/include/SDL.h"
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#else
#include "SDL/SDL.h"
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"
#endif
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

// ------ ENUMS ------
enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; //colors

// -------------------
//  IO
// -------------------
class IO {
    public:
    IO();

    void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
    void boxColor(SDL_Surface *mScreen, int pX1, int pY1, int pX2, int pY2, Uint32 color);
    void clearScreen();
    int getScreenHeight();
    int initGraph();
    int pollKey();
    int getKey();
    int isKeyDown(int pKey);
    void updateScreen();
};

#endif // _IO_