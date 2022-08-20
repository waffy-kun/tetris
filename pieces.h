#ifndef _PIECES_
#define _PIECES_

class Pieces {
    public:
    int getBlockType (int pPiece, int pRotation, int pX, int pY);
    int getXInitialPosition (int pPiece, int pRotation);
    int getYInitialPosition (int pPience, int pRotation);
};

#endif // _PIECES_