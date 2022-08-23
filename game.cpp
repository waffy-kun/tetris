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

/*
==========================
Initial parameters of the game
==========================
*/
void Game::initGame() {
    // Init Random Numbers
    srand ((unsigned int) time(NULL));

    // First Piece
    mPiece =    getRand(0, 6);
    mRotation = getRand(0, 3);
    mPosX =     (BOARD_WIDTH / 2) + mPieces -> getXInitialPosition (mPiece, mRotation);
    mPosY =     mPieces -> getYInitialPosition (mPiece, mRotation);


}