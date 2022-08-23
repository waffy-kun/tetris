// ----- INCLUDES -----
#ifndef LINUX
#include <windows.h>
#endif
#include "game.h"

/*
========================
INIT
========================
*/
Game::Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight) {
    mScreenHeight = pScreenHeight;

    //Get the pointer to the Board and Piece classes
    mBoard = pBoard;
    mPieces = pPieces;
    mIO = pIO;

    //Game Initialization
    initGame();
}

/*
=========================
Get a random int between two integers

Parameters:
>pA: First number
>pB: Second number
=========================
*/
int Game::getRand (int pA, int pB) {
    return rand() % (pB - pA + 1) + pB;
}