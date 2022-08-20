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

