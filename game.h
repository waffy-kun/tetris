#ifndef _GAME_
#define _GAME_

// ----- INCLUDES -----
#include "board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

// ----- DEFINES -----
#define WAIT_TIME 700 // Number of milliseconds before piece go 1 block down

//---------------------
// Game
//---------------------

class Game {
    public:

    Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

    void drawScene();
    void createNewPiece();

    int mPosX, mPosY; // Position of piece falling down
    int mPiece, mRotation; // Type and rotation of piece falling down

    private:

    int mScreenHeight; // Screen height in pixels
    int mNextPosX, mNextPosY; // Position of the next piece
    int mNextPiece, mNextRotation; // Type and rotation of next piece

    Board *mBoard;
    Pieces *mPieces;
    IO *mIO;

    int getRand(int pA, int pB);
    void initGame();
    void drawPiece(int pX, int pY, int pPiece, int pRotation);
    void drawBoard();
};

#endif // _GAME_