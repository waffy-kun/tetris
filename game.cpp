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

    // Next Piece
    mNextPiece =    getRand(0, 6);
    mNextRotation = getRand(0, 3);
    mNextPosX =     BOARD_WIDTH + 5;
    mNextPosY =     5;
}

/*
===========================
Create a random piece after initialization
===========================
*/
void Game::createNewPiece() {

    // The new piece
    mPiece =    mNextPiece;
    mRotation = mNextRotation;
    mPosX =     (BOARD_WIDTH / 2) + mPieces -> getXInitialPosition (mPiece, mRotation);
    mPosY =     mPieces -> getYInitialPosition (mPiece, mRotation);

    // Random next piece
    mNextPiece =    getRand(0, 6);
    mNextRotation = getRand(0, 3);
}

/*
============================
Draw Piece

Parameters:
>pX: Horizontal position in blocks
>pY: Vertical position in blocks
>pPiece: Piece to draw
>pRotation: 1 of 4 possible rotations
============================
*/
void Game::drawPiece(int pX, int pY, int pPiece, int pRotation) {
    color mColor; //Color of the block

    //Obtain the position in pixel on the screen of the block to draw
    int mPixelsX = mBoard -> getXPosInPixels (pX);
    int mPixelsY = mBoard -> getYPosInPixels (pY);

    //Travel the blocks matrix and draw filled blocks
    for (int i = 0; i < PIECE_BLOCKS; i++) {
        for (int j = 0; j < PIECE_BLOCKS; j++) {
            // Get block type and draw with assigned color
            switch (mPieces -> getBlockType (pPiece, pRotation, j, i)) {
                case 1: mColor = GREEN; break; // For each block except pivot
                case 2: mColor = BLUE; break; // For the pivot block
            }
            if (mPieces -> getBlockType (pPiece, pRotation, j, i) != 0) {
                mIO -> drawRectangle (mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE,
                                    (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                                    (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                                    mColor);
            }
        }
    }
}

/*
============================
Draw Board

Draw two lines which delimit the board
============================
*/
void Game::drawBoard() {
    //Calculate the limits of the board in pixels
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    //Check if vertical margin is not too small
    //assert (mY > MIN_VERTICAL_MARGIN);

    //Rectangles that delimit the board
    mIO -> drawRectangle (mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
    mIO -> drawRectangle (mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

    //Check whether horizontal margin is too small
    //assert (mX1 > MIN_HORIZONTAL_MARGIN)

    //Drawing blocks already stored in the board
    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            //Check if block is filled then draws it
            if (!mBoard -> isFreeBlock(i, j)) {
                mIO -> drawRectangle (mX1 + i * BLOCK_SIZE, mY + j * BLOCK_SIZE, (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1, RED);
            }
        }
    }
}