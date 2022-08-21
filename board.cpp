#include "board.h"

/*
=====================
Init
=====================
*/
Board::Board (Pieces *pPieces, int pScreenHeight) {
    //Get Screen Height
    mScreenHeight = pScreenHeight;
    
    //Get the pointer from the pieces class
    mPieces = pPieces;

    //Initialize the board blocks with free positions
    initBoard();
}

/*
=====================
Initialize the board blocks with free positions
=====================
*/
void Board::initBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++){
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            mBoard[i][j] = POS_FREE;
        }
    }
}

/*
======================
Store a piece in the board by filling the blocks

Parameters:

>pX: Horizontal position in blocks
>pY: Vertical position in blocks
>pPiece: Piece to draw
>pRotation: 1 of 4 possible rotations
======================
*/
void Board::storePiece(int pX, int pY, int pPiece, int pRotation) {
    //Store each piece of the block in the board
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            //Store only blocks that are not empty
            if (mPieces -> getBlockType (pPiece, pRotation, j2, i2) != 0){
                mBoard[i1][j1] = POS_FILLED;
            }
        }
    }
}

/*
=======================
Check if game is over after piece exceeded uppermost position
Returns True or False
=======================
*/
bool Board::isGameOver() {
    //If the first line is has blocks, end game.
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (mBoard[i][0] == POS_FILLED) return true;
    }
    return false;
}

/*
=======================
Delete a line by moving upper adjacent line down

Parameter:
>pY: Vertical position in blocks of line for deletion
=======================
*/
void Board::deleteLine(int pY) {
    //Moves all upper adjacent lines one row down
    for (int j = pY; j > 0; j--) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            mBoard[i][j] = mBoard[i][j-1];
        }
    }
}

/*
========================
Deletes lines that must be removed after player made a straight line
========================
*/
void Board::deletePossibleLines() {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while (i < BOARD_WIDTH) {
            if (mBoard[i][j] != POS_FILLED) break;
            i++;
        }
        if (i == BOARD_WIDTH) deleteLine(j);
    }
}

/*
========================
Returns true if a block in the board is empty, false if filled.

Parameters:

>pX: Horizontal position in blocks
>pY: Vertical position in blocks
========================
*/
bool Board::isFreeBlock(int pX, int pY) {
    return (mBoard[pX][pY] == POS_FILLED);
}

/*
========================
Returns horizontal position in pixels of the block

Parameters:
>pPos: Horizontal position of the block in the board
========================
*/
int Board::getXPosInPixels(int pPos) {
    return ((BOARD_POSITION-(BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

/*
=========================
Returns vertical position in pixels of the block

Parameters:
>pPos: Horizontal position of the block in the board
=========================
*/
int Board::getYPosInPixels(int pPos) {
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}