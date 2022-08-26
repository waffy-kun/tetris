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

/*
============================
Return the screen height
============================
*/
int IO::getScreenHeight() {
    return mScreen -> h;
}

/*
============================
Update screen
============================
*/
void IO::updateScreen() {
    SDL_Flip (mScreen);
}

/*
=============================
Keyboard Input
=============================
*/
int IO::pollKey() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN: return event.key.keysym.sym;
            case SDL_QUIT: exit(3);
        }
    }
}

/*
=============================
Keyboard Input contd.
=============================
*/
int IO::getKey() {
    SDL_Event event;
    while (true) {
        SDL_WaitEvent(&event);
        if(event.type == SDL_KEYDOWN) break;
        if(event.type == SDL_QUIT) exit(3);
    };
    return event.key.keysym.sym;
}

/*
=============================
Keyboard input contd. further
=============================
*/
int IO::isKeyDown(int pKey) {
    Uint8* mKeyTable;
    int mNumKeys;
    SDL_PumpEvents();
    mKeyTable = SDL_GetKeyState(&mNumKeys);
    return mKeyTable[pKey];
}

/*
=============================
SDL Graphics Initialization
=============================
*/
int IO::initGraph() {
    const SDL_VideoInfo *info;
    Uint8 video_bpp;
    Uint32 videoflags;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    atexit (SDL_Quit);

    // Alpha blending does not work well in 8-bit
    info = SDL_GetVideoInfo();
    if (info -> vfmt -> BitsPerPixel > 8) {
        video_bpp = info -> vfmt -> BitsPerPixel;
    } else {
        video_bpp = 16;
    }
    videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

    // Set 640 x 480 in video mode
    if ((mScreen = SDL_SetVideoMode(640, 480, video_bpp, videoflags)) == NULL) {
        fprintf(stderr, "Couldn't set %ix%i video mode: %s\n", 640, 480, SDL_GetError());
        return 2;
    }
    return 0;
}