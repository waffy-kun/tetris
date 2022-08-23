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