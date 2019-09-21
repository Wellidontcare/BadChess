#ifndef CHESSPIECEFACTORY_H
#define CHESSPIECEFACTORY_H

#include "Piece.h"
#include "Rook.h"
#include "emptyfield.h"
namespace chess {

class ChessPieceFactory
{
public:
    ChessPieceFactory();
    static Piece* create_piece(const int& color, const int& role);
};
}

#endif // CHESSPIECEFACTORY_H
