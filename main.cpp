#include "game.h"
#ifndef LINUX
#include <windows.h>
#endif

/*
======================
Main
======================
*/
#ifndef LINUX
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#else
int main()
#endif
{
    // ----- VARS -----
    // Class for drawing which uses SDL for rendering. Can change methods to use another render.
    IO mIO;
    int mScreenHeight = mIO.getScreenHeight();
    
    // Pieces
    Pieces mPieces;

    // Board
    Board mBoard (&mPieces, mScreenHeight);

    // Game
    Game mGame (&mBoard, &mPieces, &mIO, mScreenHeight);

    // Get actual time in milliseconds (SDL)
    unsigned long mTime1 = SDL_GetTicks();
    
    // ----- Main Loop -----
    while (!mIO.isKeyDown (SDLK_ESCAPE)) {

        // ----- Draw -----
        mIO.clearScreen();
        mGame.drawScene();
        mIO.updateScreen();

        // ----- Input -----
        int mKey = mIO.pollKey();
        
        switch (mKey) {
            case(SDLK_RIGHT): {
                if (mBoard.isPossibleMove (mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                    mGame.mPosX++;
                break;
            }

            case(SDLK_LEFT): {
                if (mBoard.isPossibleMove (mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                    mGame.mPosX--;
                break;
            }

            case(SDLK_DOWN): {
                if (mBoard.isPossibleMove (mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
                    mGame.mPosY++;
                break;
            }

            case(SDLK_x): {
                
                //Checks collision from top to bottom
                while (mBoard.isPossibleMove(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
                    mGame.mPosY++;
                }

                mBoard.storePiece (mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);
                mBoard.deletePossibleLines();

                if (mBoard.isGameOver()) {
                    mIO.getKey();
                    exit(0);
                }

                mGame.createNewPiece();
                break;
            }

            case(SDLK_z): {
                if (mBoard.isPossibleMove (mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
                    mGame.mRotation = (mGame.mRotation + 1) % 4;
                break;
            }
        }
    }
}