#ifndef CHESSPIECEFACTORY_H
#define CHESSPIECEFACTORY_H
#include <memory>
#include "piece.h"
#include "pieces/rook.h"
#include "pieces/emptyfield.h"
#include "pieces/knight.h"
#include "pieces/queen.h"
#include "pieces/pawn.h"
#include "pieces/bishop.h"

namespace chess {

class ChessPieceFactory
{
public:
    ChessPieceFactory();
    static std::shared_ptr<Piece> make(const int& color, const int& role);
};
}

#endif // CHESSPIECEFACTORY_H
