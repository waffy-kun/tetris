#ifndef _GAME_
#define _GAME_

// ----- INCLUDES -----
#include "board.h"
#include "pieces.h"
#include "io.h"
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


};

#endif // _GAME_