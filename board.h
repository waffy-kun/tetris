#ifndef _BOARD_
#define _BOARD_

//--INCLUDES--
#include "pieces.h"

//--DEFINES--

#define BOARD_LINE_WIDTH 6 //WIDTH OF EACH TWO LINES WHICH DELIMIT BOARD
#define BLOCK_SIZE 16 //Width and Height of each block piece
#define BOARD_POSITION 320 //Center position from the leftmost part of screen
#define BOARD_WIDTH 10 //Board Width in Blocks
#define BOARD_HEIGHT 20 //Board Height in Blocks
#define MIN_VERTICAL_MARGIN 20 //Minimum vertical margin for board limit
#define MIN_HORIZONTAL_MARGIN 20 //Minimum horizontal margin for board limit
#define PIECE_BLOCKS 5 //Number of horizontal and vertical blocks of matrix piece

class Board {
    public:
    Board (Pieces *pPieces, int pScreenHeight);

    int getXPosInPixels (int pPos);
    int getYPosInPixels (int pPos);
    bool isFreeBlock (int pX, int pY);
    bool isPossibleMove (int pX, int pY, int pPiece, int pRotation);
    void storePiece (int pX, int pY, int pPiece, int pRotation);
    void deletePossibleLines();
    bool isGameOver();

    private:
    //POS_FREE = empty position in the board
    //POS_FILLED = filled position in the board
    enum {POS_FREE, POS_FILLED};

    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; //Board which contains the pieces
    Pieces *mPieces;
    int mScreenHeight;

    void initBoard();
    void deleteLine(int pY);
};

#endif // _BOARD_