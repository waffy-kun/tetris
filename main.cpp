#include "game.h"
#ifndef LINUX
#include <windows.h>
#endif

/*
======================
Main
======================
*/
#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
    // ----- VARS -----
    // Class for drawing which uses SDL for rendering. Can change methods to use another render.
    IO mIO;
    int mScreenHeight = mIO.getScreenHeight();
    
    // Pieces
    Pieces mPieces;

    // Board
    Board mBoard (&mPieces, mScreenHeight);

    // Game
    Game mGame (&mBoard, &mPieces, &mIO, mScreenHeight);

    // Get actual time in milliseconds (SDL)
    unsigned long mTime1 = SDL_GetTicks();
    
}