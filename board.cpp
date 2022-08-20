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