// ------ INCLUDES ------
#include "IO.h"

static SDL_Surface *mScreen;
static Uint32 mColors [COLOR_MAX] = {0x000000ff, 0xff0000ff,
                                    0x00ff00ff, 0x0000ffff,
                                    0x00ffffff, 0xff00ffff,
                                    0xffff00ff, 0xffffffff};

/*
============================
INIT
============================
*/
IO::IO() {
    initGraph();
}

/*
============================
Method to color
============================
*/
void IO::boxColor(SDL_Surface *mScreen, int pX1, int pY1, int pX2, int pY2, Uint32 color) {
    SDL_Rect rect{pX1, pY1, pX2 - pX1, pY2 - pY1};
    SDL_FillRect(mScreen, &rect, color);
}

/*
============================
Clear a screen to black
============================
*/
void IO::clearScreen() {
    boxColor(mScreen, 0, 0, mScreen -> w - 1, mScreen -> h - 1, mColors[BLACK]);
}

/*
============================
Draw a rectangle with given color

Parameters:
> pX1, pY1: Upper left corner of rectangle
> pX2, pY2: Lower Right corner of rectangle
> pC: Color of rectangle
============================
*/
void IO::drawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC) {
    boxColor(mScreen, pX1, pY1, pX2, pY2 - 1, mColors[pC]);
}

