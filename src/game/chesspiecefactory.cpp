#include "chesspiecefactory.h"

std::shared_ptr<chess::Piece> chess::ChessPieceFactory::make(const int &color, const int &role)
{
        switch (role) {
        case ROOK:
            return std::make_shared<Piece>(Rook(color));
        case KNIGHT:
            return std::make_shared<Piece>(Knight(color));
        case BISHOP:
            return std::make_shared<Piece>(Bishop(color));
        case QUEEN:
            return std::make_shared<Piece>(Queen(color));
        case KING:
            return std::make_shared<Piece>(Pawn(color));
        default:
            return std::make_shared<Piece>(EmptyField());
        }
}
